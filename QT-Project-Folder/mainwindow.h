#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AEDSimulation.h"  // Include AEDSimulation header
#include <QPlainTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTimeInThread(QPlainTextEdit *timeTextEdit);
    void startThreadToUpdateTime(QPlainTextEdit *timeTextEdit);
    void updateCheckpoints(int step);


private slots:
   // void on_shockButton_clicked();
    void onButtonClicked(int useCaseNumber);

private:
    Ui::MainWindow *ui;
    AEDSimulation *aedSimulation;  // AEDSimulation as a pointer

    void updateInterface();
    void updateStatusDisplay();
    void startSimulation(int useCaseNumber);
};

#endif // MAINWINDOW_H
