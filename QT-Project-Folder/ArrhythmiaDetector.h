#ifndef ARRHYTHMIADETECTOR_H
#define ARRHYTHMIADETECTOR_H

#include <vector>
#include <queue>
#include <string>
class ArrhythmiaDetector {
public:
    ArrhythmiaDetector();
    ~ArrhythmiaDetector();

//    bool analyzeRhythm(const std::vector<double>& ecgData);
     bool analyzeRhythm(int scenario);

private:
    std::queue<double> recentECGData; // Queue to store recent ECG data
    double shockableThreshold;
    double thresholdForChange;
    int analysisWindow;

    bool isRhythmShockable(const std::vector<double>& ecgSegment);
    double calculateAverageRhythm(const std::vector<double>& ecgSegment);
    void processECGSegment(const std::vector<double>& ecgSegment);
};

#endif // ARRHYTHMIADETECTOR_H
