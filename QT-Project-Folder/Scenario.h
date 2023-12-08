#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <QObject>
class AEDSimulation;
enum class ScenarioType {
    PowerOn,
    BasicLifeSupport,
    AdvancedCardiacLifeSupport,
    ChokingEmergency,
    DrowningResponse,
    Unknown
};

class Scenario {
public:
    Scenario(AEDSimulation& aedSimulation);
    ~Scenario();

    void loadScenario(ScenarioType type);
    void executeScenario();
    //void setWindow(Mainwindow *window);

private:
    ScenarioType currentType;
    std::string description;
    std::vector<std::string> actions;
    void initializeScenario(ScenarioType type);
    void processExecution();
    AEDSimulation& aedSimulation;
     void handleTenSecondIntervals(std::function<void()> action);

    // These are the steps the machine takes
    void checkPatient();
    void callAmbulance();
    void placePadsOnPatient();
    void conductHeartBeatAnalysis();
    void allowShock(); //this is to give patient shock after HB analysis
    void CPRAndMouthToMouth();

    // this should be set to the parent windown so the button can be turned green
//    MainWindow *mainWindow;
};

#endif // SCENARIO_H
