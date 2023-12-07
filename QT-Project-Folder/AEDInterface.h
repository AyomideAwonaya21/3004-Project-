#ifndef AEDINTERFACE_H
#define AEDINTERFACE_H

#include <iostream>
#include <string>
#include <vector>

class AEDInterface {
public:
    AEDInterface();
    ~AEDInterface();

    void displayStatus(const std::string& status);
    void displayECG(const std::vector<double>& ecgData);
    void updateCPRFeedback(const std::string& feedback);
    void showInstruction(const std::string& instruction);
    void displayBatteryStatus(int batteryLevel);
    void displayShockInstructions(bool isAdvised);
    void voicePrompt(const std::string& message);
    void electrodePlacementStatus(bool placed);

private:
    int batteryLevel;
    bool shockAdvised;
    bool electrodesPlaced;
};

#endif // AEDINTERFACE_H


