#include "CPRFeedback.h"
#include <iostream>  // Include the iostream header for std::cout

CPRFeedback::CPRFeedback(Ui::MainWindow* ui) :mainUi(ui), idealRate(100), idealDepth(5) {}

CPRFeedback::~CPRFeedback() {}

void CPRFeedback::evaluateCompressions(int rate, int depth) {
    // Detailed evaluation of CPR compressions
    updateFeedback(rate, depth);
    std::cout << "CPR Feedback: " << currentFeedback << std::endl;
}

void CPRFeedback::updateFeedback(int rate, int depth) {
    // Implement detailed feedback logic based on CPR rate and depth
    // Placeholder logic for feedback
    if (rate < idealRate) {
        currentFeedback = "Increase compression rate.";
    } else if (rate > idealRate + 20) {
        currentFeedback = "Decrease compression rate.";
    } else if (depth < idealDepth) {
        currentFeedback = "Increase compression depth.";
    } else if (depth > idealDepth + 1) {
        currentFeedback = "Decrease compression depth.";
    } else {
        currentFeedback = "Good compressions.";
    }
}
std::string CPRFeedback::getFeedback() {
    return currentFeedback; // Return the current feedback
}
void CPRFeedback::performCPR(){
    std::cout<<"Performing CPR"<<std::endl;
}
