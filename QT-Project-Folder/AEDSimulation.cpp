#include "AEDSimulation.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip> // for setting precision of currentTime

AEDSimulation::AEDSimulation() : simulationRunning(false), shockCount(0), powerState(false), currentStep(0) {
    currentScenario.loadScenario(ScenarioType::BasicLifeSupport);
}

AEDSimulation::~AEDSimulation() {}

std::string AEDSimulation::formatTime(long seconds) const {
    long mins = seconds / 60;
    long secs = seconds % 60;
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << mins << ":" << std::setw(2) << secs;
    return ss.str();
}

void AEDSimulation::startSimulation() {
    simulationRunning = true;
    powerState = true; // Assuming the AED is powered on when the simulation starts
    currentTime = "00:00";
    std::cout << "AED Simulation started." << std::endl;
    auto startTime = std::chrono::system_clock::now();

    while (simulationRunning) {
        auto now = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
        currentTime = formatTime(elapsed.count());
        simulateECGData();
        updateSimulation();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void AEDSimulation::stopSimulation() {
    simulationRunning = false;
    std::cout << "AED Simulation stopped." << std::endl;
}

void AEDSimulation::simulateECGData() {
    ecgData.clear();
    for (int i = 0; i < 100; ++i) {
        double waveform = (i % 20 == 0) ? 0.0 : 1.0; // Simplified waveform pattern
        ecgData.push_back(waveform);
    }
    interface.displayECG(ecgData);
}

void AEDSimulation::updateSimulation() {
    bool shockableRhythm = arrhythmiaDetector.analyzeRhythm(ecgData);
    interface.displayShockInstructions(shockableRhythm);

    // Simulate user action for CPR
    cprFeedback.evaluateCompressions(100, 5); // Example CPR rate and depth
    interface.updateCPRFeedback(cprFeedback.getFeedback());

    // Update the scenario based on the simulation state
    currentScenario.executeScenario();
}
void AEDSimulation::deliverShock() {
    shockCount++;
    currentInstruction = "Shock Delivered";
    currentStep++;
}

void AEDSimulation::powerOn() {
    powerState = true;
    currentInstruction = "AED Powered On";
    currentStep = 1;
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


