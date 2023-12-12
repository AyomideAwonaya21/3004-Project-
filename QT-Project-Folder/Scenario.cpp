/*
This calss deals with the different use case scenarios. It uses the aedSimulation to update the
global use case number, update the GUI and send CPR and HB requests.
*/
#include "AEDSimulation.h"
#include "Scenario.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QPushButton>
#include <random>
#include <iostream>
#include <QDir>

Scenario::Scenario(AEDSimulation &aedSimulation, Ui::MainWindow& ui) : aedSimulation(aedSimulation), mainUi(ui) {
    //connect(mainUi.nextButton, &QPushButton::clicked, this, &Scenario::onNextButtonClicked);
    activateNextButton();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,3);
    shocksNeeded = distribution(gen);
}

Scenario::~Scenario() {}
/*This function loads the current use case scenario*/
void Scenario::loadScenario(ScenarioType type) {
    currentType = type;
    initializeScenario(type);
    std::cout << "Loaded Scenario: " << description << std::endl;
}
/*this is like a setTimeout function, creates an interval before running another function*/
void Scenario::handleTimeIntervals(std::function<void()> action, int timeInSeconds) {
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [=]() {
        action();
        // Stop the timer after executing the action
        timer->stop();
    });
    // Start the timer with the specified interval
    timer->start(timeInSeconds * 1000);  // Convert seconds to milliseconds
}
/*This function is in charge of loading the necessary variables for the use case selected*/
void Scenario::initializeScenario(ScenarioType type) {
    currentFunctionIndex = 0;
    mainUi.padsOn->setStyleSheet("background-color: red;");
    connect(mainUi.placePadsButton, &QPushButton::clicked, this, &Scenario::onPadsPlaceButtonClicked);
    switch (type) {
        case ScenarioType::SelfCheck:
        selfCheck();
            std::cout<<"Self check completed, Batter 100%, pads aer functional. Ready to Operate"<<std::endl;
            break;
        case ScenarioType::RegualarHBPEA:
            description = "Basic Life Support Scenario";
            checkPatient();
            actions = {
                [this]() { callAmbulance(); },
                [this]() { placePadsOnPatient(); },
                [this]() { conductHeartBeatAnalysis(); },
                [this]() { performCPR();},
                 [this]() { waitForAmbulance();},
            };
            break;
        case ScenarioType::RegularHBFlatlined:
            description = "Advanced Cardiac Life Support Scenario";
            checkPatient();
            actions = {
                [this]() { callAmbulance(); },
                [this]() { placePadsOnPatient(); },
                [this]() { conductHeartBeatAnalysis(); },
                [this]() { performCPR();},
                 [this]() { waitForAmbulance();},
            };
            break;
        // Additional scenarios...
        case ScenarioType:: IrregularHBVF:
         checkPatient();
         actions = {
            [this]() { callAmbulance(); },
            [this]() { placePadsOnPatient(); },
            [this]() { conductHeartBeatAnalysis(); },

            [this]() { performCPR();},
             [this]() { waitForAmbulance();},
             };
            break;
        case ScenarioType:: IrregularHBVT:
        checkPatient();
        actions = {
           [this]() { callAmbulance(); },
           [this]() { placePadsOnPatient(); },
           [this]() { conductHeartBeatAnalysis(); },
           [this]() { performCPR();},
            [this]() { waitForAmbulance();},
            };
            break;
        case ScenarioType::PadsAlreadyOn:
            aedSimulation.setCurrentUseCaseNumber(2);
            onPadsPlaceButtonClicked();
            conductHeartBeatAnalysis();
            actions = {
                [this]() { performCPR();},
                [this]() { waitForAmbulance();},
            };
            break;
       case ScenarioType::BatterLifeLow:
                batteryLow();
             break;
      case ScenarioType::LossOfConnection:
        this->connectionFixed = false;
        checkPatient();
        actions = {
           [this]() { callAmbulance(); },
           [this]() { placePadsOnPatient(); },
           [this]() { conductHeartBeatAnalysis(); },
            [this]() { placePadsOnPatient();},
            [this]() { conductHeartBeatAnalysis(); },
            [this]() { performCPR();},
             [this]() { waitForAmbulance();},
            };
            break;
        default:
            description = "Unknown Scenario";
            actions.clear();
            break;
    }
}
/*This function is in charge of indicating to the user the current step*/
void Scenario::checkPatient(){
    // set the AEDSimulation text and step, that function will then update GUI
    aedSimulation.updateCurrentStepAndInstruction(1,aedSimulation.getUseCaseNumber(), "Check Patient Responsiveness");
};
/*This function is in charge of indicating to the user the current step*/
void Scenario::callAmbulance(){
    aedSimulation.updateCurrentStepAndInstruction(2,aedSimulation.getUseCaseNumber(), "Call Ambulance");
    //change battery life
    aedSimulation.depleteBattery(5);
};
/*This function is in charge of indicating to the user the current step*/
void Scenario::placePadsOnPatient(){
    if(aedSimulation.getUseCaseNumber() && connectionFixed == true){
        aedSimulation.updateCurrentStepAndInstruction(3, aedSimulation.getUseCaseNumber(), "Connect Lost, please place pads");
    }
    else{
        aedSimulation.updateCurrentStepAndInstruction(3, aedSimulation.getUseCaseNumber(), "Place Pads");
    }
    //change battery life
    aedSimulation.depleteBattery(5);
};
/*This function is in charge of indicating to the user the current step,
and sending the aed an instruction to analyze the HB depending on the use case*/
void Scenario::conductHeartBeatAnalysis(){
    // Note: the analysis should set a variable to true if shock is needed
    aedSimulation.updateCurrentStepAndInstruction(4,aedSimulation.getUseCaseNumber(), "Checking HB");
    if((aedSimulation.getUseCaseNumber() >=2 && aedSimulation.getUseCaseNumber() <=6) || aedSimulation.getUseCaseNumber() ==8){
        deactivateNextButton();
        //if there is loss of connectionn
        if(aedSimulation.getUseCaseNumber() == 8 && this->connectionFixed == false){
            std::cout<<"In the scenario"<<std::endl;
            mainUi.padsOn->setStyleSheet("background-color: red;");
            //aedSimulation.updateCurrentStepAndInstruction(3, aedSimulation.getUseCaseNumber(), "Connection Lost, please Place pads");
            this->padsPlaced = false;
            this->connectionFixed = true;
        }
        aedSimulation.analyzeHB();
        handleTimeIntervals([this]() { activateNextButton(); }, 2);
    }
};
/*This function allows the user to shock the patient, it activates the shock button as well*/
void Scenario::allowShock(){
    deactivateNextButton();
    aedSimulation.updateCurrentStepAndInstruction(5,aedSimulation.getUseCaseNumber(), "Apply Shock");
   enableShockButton();
};
void Scenario::enableShockButton(){
    QObject::connect(mainUi.shockButton, &QPushButton::clicked, this, &Scenario::onShockButtonClicked);
};
void Scenario::disableShockButton(){
    QObject::disconnect(mainUi.shockButton, &QPushButton::clicked, this, &Scenario::onShockButtonClicked);
};
/*This function intructs and allows the user to perform CPR on the patient*/
void Scenario::performCPR(){
    deactivateNextButton();
    aedSimulation.updateCurrentStepAndInstruction(6,aedSimulation.getUseCaseNumber(), "Perform CPR");
    aedSimulation.performCPR();
};
/*This function instructs the user to perform mouth to mouth on the patient*/
void Scenario::performMouthToMouth(){
    activateNextButton();
    aedSimulation.updateCurrentStepAndInstruction(7,aedSimulation.getUseCaseNumber(), "Perform Mouth To Mouth");
    //change battery life
    aedSimulation.depleteBattery(5);
}
/*This is the function that shocks the patient. Invoked when there is an irregular HB*/
void Scenario::onShockButtonClicked(){
    disableShockButton();
    aedSimulation.deliverShock();
    //change battery life
    aedSimulation.depleteBattery(10);
};
void Scenario::resetFunctionIndex(){
    this->currentFunctionIndex = 0;
};
/*This function is connect to the next button, which is meant to move to the next step in the
operation*/
void Scenario::onNextButtonClicked() {
    if((currentFunctionIndex == 2 || currentFunctionIndex == 4)&& this->padsPlaced == false){
        return;
    }
    // Check if the currentFunctionIndex is within the bounds of the actions vector
    if (static_cast<std::vector<int>::size_type>(currentFunctionIndex) < actions.size()) {
        // Execute the function at the current index
        actions[currentFunctionIndex]();
        currentFunctionIndex++;
    }
};
/*This button is for the pads, places pads on patient when called*/
void Scenario::onPadsPlaceButtonClicked() {
    // Change the color of mainUi->padsOn to green
    mainUi.padsOn->setStyleSheet("background-color: green;");
    aedSimulation.updateCurrentStepAndInstruction(3, aedSimulation.getUseCaseNumber(), "Pads have been Placed");
    this->padsPlaced = true;
}
/*This is to instruct the patient to wait for an ambulance and monitor the patient*/
void Scenario:: waitForAmbulance(){
    aedSimulation.updateCurrentStepAndInstruction(4,aedSimulation.getUseCaseNumber(), "Monitor Patient While Ambulance Comes");
}
int Scenario::getShocksNeeded(){
    return this->shocksNeeded;
}

/*These last two functions are for use case 1 and 7, where plain text is put on the screen*/
void Scenario::selfCheck(){
    aedSimulation.updateCurrentStepAndInstruction(0,aedSimulation.getUseCaseNumber(), "Self check complete, battery is full, pads are available. Ready to operate!");
}
void Scenario::batteryLow(){
    aedSimulation.depleteBattery(95);
    aedSimulation.updateCurrentStepAndInstruction(0,0, "Battery too low, please change batteries before proceeding");
}
void Scenario::activateNextButton() {
    // Connect the clicked signal of nextButton to onNextButtonClicked slot
    QObject::connect(mainUi.nextButton, &QPushButton::clicked, this, &Scenario::onNextButtonClicked);
}
void Scenario::deactivateNextButton() {
    // Disconnect the clicked signal of nextButton
    QObject::disconnect(mainUi.nextButton, &QPushButton::clicked, this, &Scenario::onNextButtonClicked);
}


