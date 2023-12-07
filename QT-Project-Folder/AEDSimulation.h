#ifndef AEDSIMULATION_H
#define AEDSIMULATION_H

#include <QObject>
#include <QTimer>
#include "AEDInterface.h"
#include "ArrhythmiaDetector.h"
#include "CPRFeedback.h"
#include "Scenario.h"
#include <vector>
#include <string>

class AEDSimulation : public QObject {
    Q_OBJECT

public:
    explicit AEDSimulation(QObject *parent = nullptr);
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

signals:
    void updateInterfaceSignal();
    void currentTimeUpdated();

private:
    AEDInterface interface;
    ArrhythmiaDetector arrhythmiaDetector;
    CPRFeedback cprFeedback;
    Scenario currentScenario;
    bool simulationRunning;
    std::vector<double> ecgData;

    QTimer *timer;
    int shockCount;
    bool powerState;
    int currentStep;
    std::string currentInstruction;
    std::string currentTime;
    std::string formatTime(long seconds) const;

    void updateCurrentTime();
};

#endif // AEDSIMULATION_H

