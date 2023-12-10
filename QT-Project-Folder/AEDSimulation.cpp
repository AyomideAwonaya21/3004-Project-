#include "AEDSimulation.h"
#include <iostream>
#include <sstream>
#include <iomanip>  // For setting precision of currentTime
#include "mainwindow.h"
#include "Scenario.h"
#include <QString>
#include <QDir>

AEDSimulation::AEDSimulation(Ui::MainWindow* ui):cprFeedback(ui), mainUi(ui), simulationRunning(false), shockCount(0), powerState(false),currentScenario(*this, *mainUi), currentStep(0) {
    //currentScenario.loadScenario(ScenarioType::BasicLifeSupport);

    // Initialize QTimer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AEDSimulation::updateSimulation);
    timer->start(500);  // Update every 500 milliseconds
}

AEDSimulation::~AEDSimulation() {
    delete timer;
}

void AEDSimulation::startSimulation(int useCaseNumber) {
    simulationRunning = true;
    powerState = true;
    currentTime = "00:00";
    timer->start();  // Start the timer
    std::cout << "AED Simulation started." << std::endl;
}

void AEDSimulation::stopSimulation() {
    simulationRunning = false;
    timer->stop();  // Stop the timer
    std::cout << "AED Simulation stopped." << std::endl;
}

void AEDSimulation::simulateECGData() {
    ecgData.clear();
    for (int i = 0; i < 100; ++i) {
        double waveform = (i % 20 == 0) ? 0.0 : 1.0;  // Simplified waveform pattern
        ecgData.push_back(waveform);
    }
    interface.displayECG(ecgData);
}

void AEDSimulation::updateSimulation() {
    if (!simulationRunning) {
        return;
    }

    //bool shockableRhythm = arrhythmiaDetector.analyzeRhythm(ecgData);
    //interface.displayShockInstructions(shockableRhythm);

    // Simulate user action for CPR
    //cprFeedback.evaluateCompressions(100, 5); // Example CPR rate and depth
    //interface.updateCPRFeedback(cprFeedback.getFeedback());

    // Update the scenario based on the simulation state
    currentScenario.executeScenario();
    updateCurrentTime();
    emit updateInterfaceSignal();  // Emit signal to update the interface
}

void AEDSimulation::deliverShock() {
    shockCount++;
    currentInstruction = "Shock Delivered";
    currentStep++;
    emit updateInterfaceSignal();  // Emit signal to update the interface
}

void AEDSimulation::powerOn(int useCaseNumber) {

    simulationRunning = true;
    powerState = true;
    currentTime = "00:00";
    timer->start();  // Start the timer
    powerState = true;
    currentStep = useCaseNumber;
    this->useCaseNumber = useCaseNumber;
    if(useCaseNumber == 1) currentScenario.loadScenario(ScenarioType::SelfCheck);
    else if(useCaseNumber == 2) currentScenario.loadScenario(ScenarioType::RegualarHBPEA);
    else if(useCaseNumber == 3) currentScenario.loadScenario(ScenarioType::RegularHBFlatlined);
    else if(useCaseNumber == 4) currentScenario.loadScenario(ScenarioType::IrregularHBVF);
    else if(useCaseNumber == 5) currentScenario.loadScenario(ScenarioType::IrregularHBVT);
    else if(useCaseNumber == 6) currentScenario.loadScenario(ScenarioType::PadsAlreadyOn);
    emit updateInterfaceSignal();  // Emit signal to update the interface
}
int AEDSimulation::getUseCaseNumber(){
    return this->useCaseNumber;
};

std::string AEDSimulation::getCurrentInstruction() const {
    return currentInstruction;
}

std::string AEDSimulation::getCurrentTime() const {
    return currentTime;
}

int AEDSimulation::getShockCount() const {
    return shockCount;
}

bool AEDSimulation::isPoweredOn() const {
    return powerState;
}

int AEDSimulation::getCurrentStep() const {
    return currentStep;
}

void AEDSimulation::updateCurrentTime() {
    static auto startTime = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
    currentTime = formatTime(elapsed.count());
    emit currentTimeUpdated();  // Emit signal when time is updated
}

std::string AEDSimulation::formatTime(long seconds) const {
    long mins = seconds / 60;
    long secs = seconds % 60;
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << mins << ":" << std::setw(2) << secs;
    return ss.str();
}

void AEDSimulation::updateCurrentStepAndInstruction(int step,int scenario, const std::string& instruction) {
    currentStep = step;
    currentInstruction = instruction;
    //remove the image when not appropriate
    if(scenario != 4){mainUi->testIMG->setPixmap(QPixmap());}
    if(scenario == 2 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Shockable1.png";
        currentInstruction = "PEA HB Detected, No shock Needed";
        QImage image(imagePath);
        if(!image.isNull()){
             std::cout <<"Image is NOT null"<<std::endl;
             QPixmap pix(imagePath);
             QSize labelSize = mainUi->testIMG->size();  // Get the size of the label
             QPixmap scaledPix = pix.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
             mainUi->testIMG->setPixmap(scaledPix);
        }
        else{
            std::cout <<"Image is null"<<std::endl;
        }
        qDebug("IT SHOULD DISPLAY IMAGE");
    }
    emit updateInterfaceSignal();  // Emit signal to update the interface
}
bool AEDSimulation::analyzeHB(int scenario){

    this->arrhythmiaDetector.analyzeRhythm(scenario); //PASS A VALUE TO THIS
    // change display based on shockable or non-shockable
    updateCurrentStepAndInstruction(this->currentStep,this->useCaseNumber , "Analyzing HB ...");
    handleTimeIntervals([this](){
        updateCurrentStepAndInstruction(this->currentStep, this->useCaseNumber, "");
    },2);
};
void AEDSimulation::handleTimeIntervals(std::function<void()> action, int timeInSeconds) {
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [=]() {
        action();

        // Stop the timer after executing the action
        timer->stop();
    });

    // Start the timer with the specified interval
    timer->start(timeInSeconds * 1000);  // Convert seconds to milliseconds
}
void AEDSimulation::performCPR(){
    int val = 1;
    while (val == 1){
        std::cout<<"About to perform CPR"<<std::endl;
    }
}
