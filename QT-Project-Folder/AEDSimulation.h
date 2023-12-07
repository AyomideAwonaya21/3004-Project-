#ifndef AEDSIMULATION_H
#define AEDSIMULATION_H

#include "AEDInterface.h"
#include "ArrhythmiaDetector.h"
#include "CPRFeedback.h"
#include "Scenario.h"
#include <vector>
#include <string>

class AEDSimulation {
public:
    AEDSimulation();
    ~AEDSimulation();

    void startSimulation();
    void stopSimulation();
    void simulateECGData();
    void updateSimulation();

    void deliverShock();
    void powerOn();
    std::string getCurrentInstruction() const;
    std::string getCurrentTime() const;
    int getShockCount() const;
    bool isPoweredOn() const;
    int getCurrentStep() const;

private:
    AEDInterface interface;
    ArrhythmiaDetector arrhythmiaDetector;
    CPRFeedback cprFeedback;
    Scenario currentScenario;
    bool simulationRunning;
    std::vector<double> ecgData;

    int shockCount;
    bool powerState;
    int currentStep;
    std::string currentInstruction;
    std::string currentTime;
    std::string formatTime(long seconds) const;
};

#endif // AEDSIMULATION_H
