#include "AEDSimulation.h"
#include "CPRFeedback.h"
#include <iostream>
#include <QDateTime>
#include <QPushButton>
#include <QObject>


CPRFeedback::CPRFeedback(AEDSimulation& aedSimulation,Ui::MainWindow* ui) :aedSimulation(aedSimulation), mainUi(ui), idealRate(1.66), idealDepth(5) {
}

CPRFeedback::~CPRFeedback() {
   disconnectCPRButton();
}

void CPRFeedback::evaluateCompressions(int rate, int depth) {
    // Detailed evaluation of CPR compressions
    updateFeedback(rate, depth);
    std::cout << "CPR Feedback: " << currentFeedback << std::endl;
}

std::string CPRFeedback::updateFeedback(double rate, int depth) {
    // 10 good compressions and then mouth to mouth
    if (rate < idealRate) {
        currentFeedback = "Increase compression rate.";
        mainUi->instructionText->setPlainText("Increase Compression Rate");
        return "bad";
    } else if (rate > idealRate + 2) {
        mainUi->instructionText->setPlainText("Decrease Compression Rate");
        return "bad";
    } else {
        currentFeedback = "Good compressions.";
        aedSimulation.updateCurrentStepAndInstruction(0,0,"Good compression");
        return "good";
    }
}

std::string CPRFeedback::getFeedback() {
    return currentFeedback; // Return the current feedback
}

void CPRFeedback::performCPR() {
    std::cout << "Performing CPR" << std::endl;
    //connect(mainUi->CPRButton, &QPushButton::clicked, this, &CPRFeedback::onCPRButtonClicked);
    connectCPRButton();
}

void CPRFeedback::onCPRButtonClicked() {
    if(goodCompressionCount == 10){
        std::cout<<"Go to mouth to mouth"<<std::endl;
        disconnectCPRButton();
        aedSimulation.CPRFinished();
        return;
    }
    // Get the current timestamp
    QDateTime currentTime = QDateTime::currentDateTime();

    // Calculate the time interval since the last click
    qint64 intervalMilliseconds = lastClickTime.msecsTo(currentTime);

    // Calculate the rate as the reciprocal of the time interval
    double rate = 1000.0 / intervalMilliseconds;

    // Print the rate to the console
    //std::cout << "CPR Rate: " << rate << " compressions per second" << std::endl;
    std::string feedback = updateFeedback(rate, 2);
    if(feedback == "good"){
        goodCompressionCount++;
    };
    std::cout<<goodCompressionCount<<std::endl;



    // Update the last click time
    lastClickTime = currentTime;
}

void CPRFeedback::connectCPRButton() {
    // Connect the signal to the slot and store the connection
    cprButtonConnection = connect(mainUi->CPRButton, &QPushButton::clicked, this, &CPRFeedback::onCPRButtonClicked);
}

void CPRFeedback::disconnectCPRButton() {
    // Disconnect the signal-slot connection
    disconnect(cprButtonConnection);
}
