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
#include "ui_mainwindow.h"
class MainWindow;

class AEDSimulation : public QObject {
    Q_OBJECT

public:
    //explicit AEDSimulation(QObject *parent = nullptr);
    AEDSimulation(Ui::MainWindow* ui);
    ~AEDSimulation();

    void startSimulation(int useCaseNumber);
    void stopSimulation();
    void simulateECGData();
    void updateSimulation();

    void deliverShock();
    void powerOn(int useCaseNumber);
    std::string getCurrentInstruction() const;
    std::string getCurrentTime() const;
    int getShockCount() const;
    bool isPoweredOn() const;
    int getCurrentStep() const;
    void updateCurrentStepAndInstruction(int step, const std::string& instruction);
    bool analyzeHB(std::string condition); // calls the arrhythmiaDetector to analyze HB

signals:
    void updateInterfaceSignal();
    void currentTimeUpdated();

private:
    AEDInterface interface;
    ArrhythmiaDetector arrhythmiaDetector;
    CPRFeedback cprFeedback;
    Ui::MainWindow* mainUi;
    Scenario currentScenario;
    bool simulationRunning;
    std::vector<double> ecgData;
    MainWindow *mainwindow;
    void handleTimeIntervals(std::function<void()> action, int timeInSeconds);
    bool padsPlaced;

    int shockCount;
    bool powerState;
    int currentStep;
    std::string currentInstruction;
    std::string currentTime;
    std::string formatTime(long seconds) const;
    QTimer *timer;

    void updateCurrentTime();
};

#endif // AEDSIMULATION_H

