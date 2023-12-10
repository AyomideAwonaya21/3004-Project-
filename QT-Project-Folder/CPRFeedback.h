#ifndef CPRFEEDBACK_H
#define CPRFEEDBACK_H

#include <string>
#include <QPushButton>
#include "ui_mainwindow.h"
#include <QDateTime>
class AEDSimulation;

class CPRFeedback: public QObject {
    Q_OBJECT
public:
    CPRFeedback(AEDSimulation& aedSimulation,Ui::MainWindow* ui);
    ~CPRFeedback();
    void evaluateCompressions(int rate, int depth);
    std::string getFeedback();
    void performCPR();


private:
    double idealRate;
    int idealDepth;
    std::string currentFeedback;
    std::string updateFeedback(double rate, int depth);
    Ui::MainWindow* mainUi;
    void onCPRButtonClicked();
    QDateTime lastClickTime;
    AEDSimulation& aedSimulation;
    int goodCompressionCount = 0;
    std::string compressionStatus ="bad";

    void connectCPRButton();
        void disconnectCPRButton();
    QMetaObject::Connection cprButtonConnection;
};

#endif // CPRFEEDBACK_H
