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
#include "Battery.h"
class MainWindow;

class AEDSimulation : public QObject {
    Q_OBJECT

public:
    //explicit AEDSimulation(QObject *parent = nullptr);
    AEDSimulation(Ui::MainWindow* ui);
    ~AEDSimulation();
    // string returns
    std::string getCurrentInstruction() const;
    std::string getCurrentTime() const;
    // int returns
    int getShockCount() const;
    int getCurrentStep() const;
    int getUseCaseNumber();
    int getBatteryLife();
    // boolean returns
    bool isPoweredOn() const;
    void analyzeHB();
    //void funtions
    void stopSimulation();
    void updateSimulation();
    void CPRFinished();
    void deliverShock();
    void powerOn(int useCaseNumber);
    void updateCurrentStepAndInstruction(int step, int scenario, const std::string&instruction);
    void performCPR();
    void setBatteryLife(int value);
    void depleteBattery(int value);
    void setCurrentUseCaseNumber(int value);

signals:
    void updateInterfaceSignal();
    void currentTimeUpdated();

private:
    //functions
    void updateCurrentTime();
    void displayIMG(QString path);
    void handleTimeIntervals(std::function<void()> action, int timeInSeconds);
    std::string formatTime(long seconds) const;

    //variables
    CPRFeedback cprFeedback;
    Ui::MainWindow* mainUi;
    Scenario currentScenario;
    MainWindow *mainwindow;
    Battery battery;
    QTimer *timer;

    int useCaseNumber;
    int batteryLife;
    int shockCount = 0;
    int currentStep;

    bool simulationRunning;
    bool padsPlaced;
    bool powerState;

    std::string currentInstruction;
    std::string currentTime;
};

#endif // AEDSIMULATION_H

