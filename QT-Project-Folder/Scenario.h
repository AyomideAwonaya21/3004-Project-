#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <vector>

enum class ScenarioType {
    BasicLifeSupport,
    AdvancedCardiacLifeSupport,
    ChokingEmergency,
    DrowningResponse,
    Unknown
};

class Scenario {
public:
    Scenario();
    ~Scenario();

    void loadScenario(ScenarioType type);
    void executeScenario();

private:
    ScenarioType currentType;
    std::string description;
    std::vector<std::string> actions;

    void initializeScenario(ScenarioType type);
    void processExecution();
};

#endif // SCENARIO_H
