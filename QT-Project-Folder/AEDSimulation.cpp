#include "AEDSimulation.h"
#include <iostream>
#include <sstream>
#include <iomanip>  // For setting precision of currentTime
#include "mainwindow.h"
#include "Scenario.h"
#include <QString>
#include <QDir>

AEDSimulation::AEDSimulation(Ui::MainWindow* ui):cprFeedback(*this, ui),
    mainUi(ui),
    currentScenario(*this, *mainUi),
    battery(100),  // Initialize battery before using it
    timer(new QTimer()),  // Initialize timer before using it
    useCaseNumber(0),
    batteryLife(0),
    shockCount(0),
    currentStep(0),
    simulationRunning(false),
    padsPlaced(false),
    powerState(false){
    // Initialize QTimer
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &AEDSimulation::updateSimulation);
    timer->start(500);  // Update every 500 milliseconds
}

AEDSimulation::~AEDSimulation() {
    delete timer;
}
void AEDSimulation::setCurrentUseCaseNumber(int value){
    this->useCaseNumber = value;
};
void AEDSimulation::stopSimulation() {
    simulationRunning = false;
    timer->stop();  // Stop the timer
    std::cout << "AED Simulation stopped." << std::endl;
}
void AEDSimulation::updateSimulation() {
    if (!simulationRunning) {
        return;
    }
    updateCurrentTime();
    emit updateInterfaceSignal();  // Emit signal to update the interface
}
void AEDSimulation::deliverShock() {
    shockCount += 1;
    currentInstruction = "Shock Delivered";
    QString shockString = "Shock " + QString::number(shockCount);
    mainUi->shockText->setPlainText(shockString);
    currentScenario.conductHeartBeatAnalysis();
    // Update the Interface
    emit updateInterfaceSignal();  // Emit signal to update the interface
}
/*Start of the AED operation*/
void AEDSimulation::powerOn(int useCaseNumber) {
    //reset the starting action function
   currentScenario.resetFunctionIndex();
    cprFeedback.setGoodCompressionCount(0);
    shockCount = 0;
    batteryLife = useCaseNumber == 7? 5:100;
    simulationRunning = true;
    this->battery.resetBattery();
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
    else if(useCaseNumber == 7) currentScenario.loadScenario(ScenarioType::BatterLifeLow);
    else if(useCaseNumber == 8) currentScenario.loadScenario(ScenarioType::LossOfConnection);
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
/*Returns the number of shocks given to the patient*/
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
/*Display an image on the main display*/
void AEDSimulation::displayIMG(QString path){
    QImage image(path);
    if(!image.isNull()){
         QPixmap pix(path);
         QSize labelSize = mainUi->testIMG->size();  // Get the size of the label
         QPixmap scaledPix = pix.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
         mainUi->testIMG->setPixmap(scaledPix);
    }
}
/*Update the buttons and the GUI text instuction*/
void AEDSimulation::updateCurrentStepAndInstruction(int step,int scenario, const std::string& instruction) {
    mainUi->instructionText->setFontPointSize(10);
    if(step == 0){//this is for the self check test message because it is long
        mainUi->instructionText->setFontPointSize(7);
    }
    currentStep = step == 0?currentStep:step;
    currentInstruction = instruction;
    //remove the image when not appropriate
    if(step != 4){mainUi->testIMG->setPixmap(QPixmap());}
    if(scenario == 2 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Nonshockable1.png";
        currentInstruction = "PEA HB Detected, No shock Needed. Press Next";
        displayIMG(imagePath);
        //qDebug("IT SHOULD DISPLAY IMAGE");
    }
    else if(scenario == 8 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Nonshockable1.png";
        currentInstruction = "PEA HB Detected, No shock Needed. Press Next";
        displayIMG(imagePath);
        //qDebug("IT SHOULD DISPLAY IMAGE");
    }
    else if(scenario == 3 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Nonshockable2.png";
        currentInstruction = "Flatline HB Detected, No shock Needed. Wait...";
        displayIMG(imagePath);
    }
    else if(scenario == 4 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Shockable1.png";
        currentInstruction = "Irregular VF HB Detected, Shock Needed. Wait...";
        displayIMG(imagePath);
    }
    else if(scenario == 5 && instruction == ""){
        QString imagePath = QDir::currentPath() + "/Images/Shockable2.png";
        currentInstruction = "Irregular VT HB Detected, Shock Needed";
        displayIMG(imagePath);
    }
    emit updateInterfaceSignal();  // Emit signal to update the interface
}
/*Analyzes the HB depending on which use case is being run*/
void AEDSimulation::analyzeHB(){
    // change display based on shockable or non-shockable
    updateCurrentStepAndInstruction(this->currentStep,this->useCaseNumber , "Analyzing HB ...");
    handleTimeIntervals([this](){
        updateCurrentStepAndInstruction(this->currentStep, this->useCaseNumber, "");
        if(this->useCaseNumber == 4 || this->useCaseNumber == 5){
            handleTimeIntervals([this](){
                if(shockCount == currentScenario.getShocksNeeded()){
//                    updateCurrentStepAndInstruction(this->currentStep+2, this->useCaseNumber, "");
                    currentScenario.onNextButtonClicked();
                    return;
                }
                currentScenario.allowShock();
            },2);
        }
    },2);
    //change battery life
    this->depleteBattery(10);
};
/*This is like a setTimeOut function, it delays the call to a function*/
void AEDSimulation::handleTimeIntervals(std::function<void()> action, int timeInSeconds) {
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [=]() {
        action();
        // Stop the timer after executing the action
        timer->stop();
    });
    // Start the timer with the specified interval
    timer->start(timeInSeconds * 1000);  // Convert seconds to milliseconds
};
void AEDSimulation::performCPR(){
    cprFeedback.performCPR();
};
/*After the CPR is finished, it should move to mouth to mouth*/
void AEDSimulation::CPRFinished(){
    currentScenario.performMouthToMouth();
}
void AEDSimulation::setBatteryLife(int value){
    this->batteryLife = value;
};
int AEDSimulation::getBatteryLife(){
    return this->battery.getBatteryLife();
}
/*This function call the battery object to decrease the battery level*/
void AEDSimulation::depleteBattery(int value){
    this->battery.decreaseBatteryLife(value);
}
