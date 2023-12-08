#include "AEDSimulation.h"
#include "Scenario.h"
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QPushButton>

Scenario::Scenario(AEDSimulation &aedSimulation, Ui::MainWindow& ui) : aedSimulation(aedSimulation), mainUi(ui), currentType(ScenarioType::BasicLifeSupport) {
    connect(mainUi.nextButton, &QPushButton::clicked, this, &Scenario::onNextButtonClicked);
}

Scenario::~Scenario() {

}

void Scenario::loadScenario(ScenarioType type) {
    currentType = type;
    initializeScenario(type);
    std::cout << "Loaded Scenario: " << description << std::endl;
}

void Scenario::executeScenario() {
    if (currentType == ScenarioType::Unknown) {
        std::cout << "No scenario loaded." << std::endl;
        return;
    }
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
        case ScenarioType::PowerOn:
            std::cout<<"HERE------"<<std::endl;
            checkPatient();
            actions = {
                [this]() { callAmbulance(); },
                [this]() { placePadsOnPatient(); },
                [this]() { conductHeartBeatAnalysis(); }
            };
            break;
        case ScenarioType::BasicLifeSupport:
            description = "Basic Life Support Scenario";
            //actions = {"Check responsiveness", "Call for help", "Perform CPR"};
            break;
        case ScenarioType::AdvancedCardiacLifeSupport:
            description = "Advanced Cardiac Life Support Scenario";
            //actions = {"Use defibrillator", "Administer medication", "Continue CPR"};
            break;
        // Additional scenarios...
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
    aedSimulation.updateCurrentStepAndInstruction(1, "Check Patient Responsiveness");
    //play audio here
};
void Scenario::callAmbulance(){
    aedSimulation.updateCurrentStepAndInstruction(2, "Call Ambulance");
};
void Scenario::placePadsOnPatient(){
    aedSimulation.updateCurrentStepAndInstruction(3, "Place Pads");

};
void Scenario::conductHeartBeatAnalysis(){
    // Note: the analysis should set a variable to true if shock is needed
    aedSimulation.updateCurrentStepAndInstruction(4, "Checking HB");
    aedSimulation.analyzeHB("stable");
};
void Scenario::allowShock(){
    aedSimulation.updateCurrentStepAndInstruction(5, "Apply Shock");
    // Connect the clicked signal of shockButton to onShockButtonClicked slot
    QObject::connect(mainUi.shockButton, &QPushButton::clicked, this, &Scenario::onShockButtonClicked);

}; //this is to give patient shock after HB analysis
void Scenario::CPRAndMouthToMouth(){
    aedSimulation.updateCurrentStepAndInstruction(6, "Perform CPR");
};

void Scenario::onShockButtonClicked(){
    qDebug()<<"Shock button Has been Pressed";
};
void Scenario::onNextButtonClicked() {
    // Check if the currentFunctionIndex is within the bounds of the actions vector
    if (currentFunctionIndex < actions.size()) {
        // Execute the function at the current index
        actions[currentFunctionIndex]();

        // Increment the index for the next function
        //check to see if pads are placed before moving to next step
        std::cout<<"The function index is: ";
        std::cout<<currentFunctionIndex<<std::endl;
        if(currentFunctionIndex == 1 && this->padsPlaced == false){
            std::cout<<"PADS ARE NOT PLACE"<<std::endl;
        }
        else{++currentFunctionIndex;};

    }
};
void Scenario::onPadsPlaceButtonClicked() {
    // Change the color of mainUi->padsOn to green
    mainUi.padsOn->setStyleSheet("background-color: green;");
    this->padsPlaced = true;
}



