#include "AEDSimulation.h"
#include "Scenario.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QPushButton>
#include <random>
#include <iostream>
#include <QDir>
//#include <QMediaPlayer>

Scenario::Scenario(AEDSimulation &aedSimulation, Ui::MainWindow& ui) : aedSimulation(aedSimulation), mainUi(ui) {
    connect(mainUi.nextButton, &QPushButton::clicked, this, &Scenario::onNextButtonClicked);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distribution(1,3);
    shocksNeeded = distribution(gen);
}

Scenario::~Scenario() {

}

void Scenario::loadScenario(ScenarioType type) {
    currentType = type;
    initializeScenario(type);
    std::cout << "Loaded Scenario: " << description << std::endl;
}

void Scenario::executeScenario() {
//    if (currentType == ScenarioType::Unknown) {
//        std::cout << "No scenario loaded." << std::endl;
//        return;
//    }
    //std::cout << "Executing Scenario: " << description << std::endl;
    processExecution();
}

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
            break;
        case ScenarioType::PadsAlreadyOn:
            break;
       case ScenarioType::BatterLifeLow:

             break;
        default:
            description = "Unknown Scenario";
            actions.clear();
            break;
    }
}

void Scenario::processExecution() {
    for (const auto& action : actions) {
        //std::cout << "Performing action: " << action << std::endl;
        // Add detailed logic for each action
    }
}
void Scenario::checkPatient(){
    // set the AEDSimulation text and step, that function will then update GUI
    aedSimulation.updateCurrentStepAndInstruction(1,aedSimulation.getUseCaseNumber(), "Check Patient Responsiveness");
    //play audio here
//    QString imagePath = QDir::currentPath() + "/Auuuuudioable1.png";

    // Play audio here
//        QString audioPath = QDir::currentPath() + "/Audio/CheckPatient.mp3";
//        // Create a QMediaPlayer instance
//        QMediaPlayer* mediaPlayer = new QMediaPlayer;
//        // Set the media content
//        mediaPlayer->setMedia(QUrl::fromLocalFile(audioPath));
//        // Play the audio
//        mediaPlayer->play();
};
void Scenario::callAmbulance(){
    aedSimulation.updateCurrentStepAndInstruction(2,aedSimulation.getUseCaseNumber(), "Call Ambulance");
    //change battery life
    aedSimulation.depleteBattery(5);
};
void Scenario::placePadsOnPatient(){
    aedSimulation.updateCurrentStepAndInstruction(3, aedSimulation.getUseCaseNumber(), "Place Pads");
    //change battery life
    aedSimulation.depleteBattery(5);
};
void Scenario::conductHeartBeatAnalysis(){
    // Note: the analysis should set a variable to true if shock is needed
    aedSimulation.updateCurrentStepAndInstruction(4,aedSimulation.getUseCaseNumber(), "Checking HB");
    if(aedSimulation.getUseCaseNumber() == 2){aedSimulation.analyzeHB(2);}
    else  if(aedSimulation.getUseCaseNumber() == 3){aedSimulation.analyzeHB(3);}
     else  if(aedSimulation.getUseCaseNumber() == 4){aedSimulation.analyzeHB(4);}
     else  if(aedSimulation.getUseCaseNumber() == 5){aedSimulation.analyzeHB(5);}
     else  if(aedSimulation.getUseCaseNumber() == 6){aedSimulation.analyzeHB(6);}

};
void Scenario::allowShock(){
    aedSimulation.updateCurrentStepAndInstruction(5,aedSimulation.getUseCaseNumber(), "Apply Shock");
    // Disconnect the existing connection (if any)
        QObject::disconnect(mainUi.shockButton, &QPushButton::clicked, this, &Scenario::onShockButtonClicked);

    // Connect the clicked signal of shockButton to onShockButtonClicked slot
    QObject::connect(mainUi.shockButton, &QPushButton::clicked, this, &Scenario::onShockButtonClicked);

}; //this is to give patient shock after HB analysis
void Scenario::performCPR(){
    aedSimulation.updateCurrentStepAndInstruction(6,aedSimulation.getUseCaseNumber(), "Perform CPR");
    aedSimulation.performCPR();
//    //change battery life
//    aedSimulation.depleteBattery(10);
};
void Scenario::performMouthToMouth(){
    aedSimulation.updateCurrentStepAndInstruction(7,aedSimulation.getUseCaseNumber(), "Perform Mouth To Mouth");
    //change battery life
    aedSimulation.depleteBattery(5);
}

void Scenario::onShockButtonClicked(){
    aedSimulation.deliverShock(shocksNeeded);

    //change battery life
    aedSimulation.depleteBattery(10);
};
void Scenario::onNextButtonClicked() {
    if(currentFunctionIndex == 2&& this->padsPlaced == false){
        std::cout<<"PADS ARE NOT PLACE"<<std::endl;
        return;
    }
    // Check if the currentFunctionIndex is within the bounds of the actions vector
    if (currentFunctionIndex < actions.size()) {
        // Execute the function at the current index
        actions[currentFunctionIndex]();

        // Increment the index for the next function
        //check to see if pads are placed before moving to next step
        std::cout<<"The function index is: ";
        std::cout<<currentFunctionIndex;
        std::cout<<" and the pads are: ";
        std::cout<<this->padsPlaced<<std::endl;
//        if(currentFunctionIndex == 1&& this->padsPlaced == false){
//            std::cout<<"PADS ARE NOT PLACE"<<std::endl;
//            return;
//        }
//        else{currentFunctionIndex++;};
        currentFunctionIndex++;

    }
};
void Scenario::onPadsPlaceButtonClicked() {
    // Change the color of mainUi->padsOn to green
    mainUi.padsOn->setStyleSheet("background-color: green;");
    this->padsPlaced = true;
}
void Scenario:: waitForAmbulance(){
    aedSimulation.updateCurrentStepAndInstruction(4,aedSimulation.getUseCaseNumber(), "Monitor Patient While Ambulance Comes");

}
int Scenario::getShocksNeeded(){
    return this->shocksNeeded;
}
void Scenario::selfCheck(){

    aedSimulation.updateCurrentStepAndInstruction(0,aedSimulation.getUseCaseNumber(), "Self check complete, battery is full, pads are available. Ready to operate!");
}



