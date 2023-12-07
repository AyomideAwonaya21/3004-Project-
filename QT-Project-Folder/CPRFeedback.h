#ifndef CPRFEEDBACK_H
#define CPRFEEDBACK_H

#include <string>

class CPRFeedback {
public:
    CPRFeedback();
    ~CPRFeedback();

    void evaluateCompressions(int rate, int depth);
    std::string getFeedback();

private:
    int idealRate;
    int idealDepth;
    std::string currentFeedback;
    void updateFeedback(int rate, int depth);
};

#endif // CPRFEEDBACK_H
