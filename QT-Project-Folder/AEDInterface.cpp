#include "AEDInterface.h"

AEDInterface::AEDInterface() : batteryLevel(100), shockAdvised(false), electrodesPlaced(false) {}

AEDInterface::~AEDInterface() {}

void AEDInterface::displayStatus(const std::string& status) {
    std::cout << "Status: " << status << std::endl;
}

void AEDInterface::displayECG(const std::vector<double>& ecgData) {
    for (const auto& data : ecgData) {
        std::cout << data << " ";  // Realistic ECG waveform display
    }
    std::cout << std::endl;
}

void AEDInterface::updateCPRFeedback(const std::string& feedback) {
    std::cout << "CPR Feedback: " << feedback << std::endl;
}

void AEDInterface::showInstruction(const std::string& instruction) {
    std::cout << "Instruction: " << instruction << std::endl;
}

void AEDInterface::displayBatteryStatus(int level) {
    batteryLevel = level;
    std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
}

void AEDInterface::displayShockInstructions(bool isAdvised) {
    shockAdvised = isAdvised;
    std::cout << (shockAdvised ? "Shock advised. Press the shock button." : "No shock advised.") << std::endl;
}

void AEDInterface::voicePrompt(const std::string& message) {
    std::cout << "Voice Prompt: " << message << std::endl;
}

void AEDInterface::electrodePlacementStatus(bool placed) {
    electrodesPlaced = placed;
    std::cout << (electrodesPlaced ? "Electrodes correctly placed." : "Check electrodes placement.") << std::endl;
}

