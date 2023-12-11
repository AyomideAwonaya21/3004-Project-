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

    void startSimulation(int useCaseNumber);
    void stopSimulation();
    void simulateECGData();
    void updateSimulation();
    void CPRFinished();

    void deliverShock(int numOfShocksNeeded);
    void powerOn(int useCaseNumber);
    std::string getCurrentInstruction() const;
    std::string getCurrentTime() const;
    int getShockCount() const;
    bool isPoweredOn() const;
    int getCurrentStep() const;
    void updateCurrentStepAndInstruction(int step, int scenario, const std::string&instruction);
    bool analyzeHB(int scenario); // calls the arrhythmiaDetector to analyze HB
    int getUseCaseNumber();
    void performCPR();
    void setBatteryLife(int value);
    int getBatteryLife();
    void depleteBattery(int value);
    void setCurrentUseCaseNumber(int value);

signals:
    void updateInterfaceSignal();
    void currentTimeUpdated();

private:
    int useCaseNumber;
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
    void displayIMG(QString path);
    int batteryLife;
    Battery battery;


    int shockCount = 0;
    bool powerState;
    int currentStep;
    std::string currentInstruction;
    std::string currentTime;
    std::string formatTime(long seconds) const;
    QTimer *timer;

    void updateCurrentTime();
};

#endif // AEDSIMULATION_H

