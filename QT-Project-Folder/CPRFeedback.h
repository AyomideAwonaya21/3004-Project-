#ifndef CPRFEEDBACK_H
#define CPRFEEDBACK_H

#include <string>
#include <QPushButton>
#include "ui_mainwindow.h"

class CPRFeedback {
public:
    CPRFeedback(Ui::MainWindow* ui);
    ~CPRFeedback();

    void evaluateCompressions(int rate, int depth);
    std::string getFeedback();

private:
    int idealRate;
    int idealDepth;
    std::string currentFeedback;
    void updateFeedback(int rate, int depth);
    Ui::MainWindow* mainUi;


};

#endif // CPRFEEDBACK_H
