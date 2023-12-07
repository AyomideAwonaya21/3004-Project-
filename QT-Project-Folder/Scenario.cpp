#include "Scenario.h"

Scenario::Scenario() : currentType(ScenarioType::BasicLifeSupport) {}

Scenario::~Scenario() {}

void Scenario::loadScenario(ScenarioType type) {
    currentType = type;
    initializeScenario(type);
    std::cout << "Loaded Scenario: " << description << std::endl;
}

void Scenario::executeScenario() {
    if (currentType == ScenarioType::Unknown) {
        std::cout << "No scenario loaded." << std::endl;
        return;
    }
    std::cout << "Executing Scenario: " << description << std::endl;
    processExecution();
}

void Scenario::initializeScenario(ScenarioType type) {
    switch (type) {
        case ScenarioType::BasicLifeSupport:
            description = "Basic Life Support Scenario";
            actions = {"Check responsiveness", "Call for help", "Perform CPR"};
            break;
        case ScenarioType::AdvancedCardiacLifeSupport:
            description = "Advanced Cardiac Life Support Scenario";
            actions = {"Use defibrillator", "Administer medication", "Continue CPR"};
            break;
        // Additional scenarios...
        default:
            description = "Unknown Scenario";
            actions.clear();
            break;
    }
}

void Scenario::processExecution() {
    for (const auto& action : actions) {
        std::cout << "Performing action: " << action << std::endl;
        // Add detailed logic for each action
    }
}

