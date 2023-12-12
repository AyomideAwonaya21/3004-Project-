#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>
#include <QPushButton>
#include "ui_mainwindow.h"

class AEDSimulation;
enum class ScenarioType {
    SelfCheck,
    RegualarHBPEA,
    RegularHBFlatlined,
    IrregularHBVF,
    IrregularHBVT,
    PadsAlreadyOn,
    BatterLifeLow
};

class Scenario: public QObject {
    Q_OBJECT
public:
    Scenario(AEDSimulation& aedSimulation,Ui::MainWindow& ui);
    ~Scenario();
    void loadScenario(ScenarioType type);
    void performMouthToMouth();
    void allowShock();
    void conductHeartBeatAnalysis();
    int getShocksNeeded();

public slots:
    void onNextButtonClicked();

private:
    void initializeScenario(ScenarioType type);
    void onShockButtonClicked();
    void handleTimeIntervals(std::function<void()> action, int timeInSeconds);
    void donNextButtonClicked();
    void onPadsPlaceButtonClicked();
    void batteryLow();

    //Functions for steps/instructions
    void checkPatient();
    void callAmbulance();
    void placePadsOnPatient();
    void performCPR();
    void waitForAmbulance();
    void selfCheck();

    ScenarioType currentType;
    std::string description;
    AEDSimulation& aedSimulation;
    Ui::MainWindow& mainUi;
    std::vector<std::function<void()>> actions;

    bool shockButtonPressed = false;
    bool padsPlaced = false;
    int currentFunctionIndex;
    int shocksNeeded;  
};
#endif // SCENARIO_H
