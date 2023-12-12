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
    void performCPR();
    void setGoodCompressionCount(int value);

private:
    std::string updateFeedback(double rate, int depth);
    void onCPRButtonClicked();
    void onDepthNumberValueChanged(int value);
    void connectCPRButton();
    void disconnectCPRButton();

    std::string currentFeedback;
    Ui::MainWindow* mainUi;
    QDateTime lastClickTime;
    AEDSimulation& aedSimulation;
    std::string compressionStatus ="bad";
    QMetaObject::Connection cprButtonConnection;

    double idealRate;
    int idealDepth;
    int goodCompressionCount = 0;
    int compressionDepth;
};

#endif // CPRFEEDBACK_H
