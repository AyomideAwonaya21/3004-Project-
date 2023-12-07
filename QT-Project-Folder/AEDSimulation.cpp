#include "AEDSimulation.h"
#include <iostream>
#include <sstream>
#include <iomanip>  // For setting precision of currentTime

AEDSimulation::AEDSimulation(QObject *parent)
    : QObject(parent), simulationRunning(false), shockCount(0), powerState(false), currentStep(0) {
    currentScenario.loadScenario(ScenarioType::BasicLifeSupport);

    // Initialize QTimer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AEDSimulation::updateSimulation);
    timer->start(500);  // Update every 500 milliseconds
}

AEDSimulation::~AEDSimulation() {
    delete timer;
}

void AEDSimulation::startSimulation() {
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

    bool shockableRhythm = arrhythmiaDetector.analyzeRhythm(ecgData);
    interface.displayShockInstructions(shockableRhythm);

    // Simulate user action for CPR
    cprFeedback.evaluateCompressions(100, 5); // Example CPR rate and depth
    interface.updateCPRFeedback(cprFeedback.getFeedback());

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

void AEDSimulation::powerOn() {
    powerState = true;
    currentInstruction = "AED Powered On";
    currentStep = 1;
    emit updateInterfaceSignal();  // Emit signal to update the interface
}

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
