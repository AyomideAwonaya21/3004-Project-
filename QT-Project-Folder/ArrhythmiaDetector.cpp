#include "ArrhythmiaDetector.h"
#include <cmath>
#include <string>
#include <QDebug>
ArrhythmiaDetector::ArrhythmiaDetector() : shockableThreshold(100.0), analysisWindow(5000) {
    // Initialization code for ArrhythmiaDetector
}

ArrhythmiaDetector::~ArrhythmiaDetector() {}
//bool ArrhythmiaDetector::analyzeRhythm(const std::vector<double>& ecgData);
bool ArrhythmiaDetector::analyzeRhythm(int scenario) { // true if shockable, false it not
//    for (const auto& data : ecgData) {
//        recentECGData.push(data);
//        // Cast recentECGData.size() to int for comparison
//        if (static_cast<int>(recentECGData.size()) > analysisWindow) {
//            recentECGData.pop();
//        }
//    }

//    return isRhythmShockable(ecgData);
    qDebug() << "In the arrythmaia CLass";
    return true;
}


bool ArrhythmiaDetector::isRhythmShockable(const std::vector<double>& ecgSegment) {
    double average = calculateAverageRhythm(ecgSegment);
    return average > shockableThreshold;
}

double ArrhythmiaDetector::calculateAverageRhythm(const std::vector<double>& ecgSegment) {
    double sum = 0.0;
    for (auto value : ecgSegment) {
        sum += value;
    }
    return sum / ecgSegment.size();
}

void ArrhythmiaDetector::processECGSegment(const std::vector<double>& ecgSegment) {
    // This method will process the ECG segment to analyze for arrhythmias.
    // For demonstration, let's implement a simple logic to detect unusual patterns.

    if (ecgSegment.empty()) {
        return;  // Return if the segment is empty
    }
    // Detecting abnormal spikes or drops in the ECG segment
    double lastValue = ecgSegment.front();
    for (auto value : ecgSegment) {
        double change = std::abs(value - lastValue);
        if (change > thresholdForChange) {  // Threshold to detect significant change
            // Abnormal change detected, potential arrhythmia
            // Implement further logic as needed
        }
        lastValue = value;
    }
    // Additional analysis logic can be added here
}

