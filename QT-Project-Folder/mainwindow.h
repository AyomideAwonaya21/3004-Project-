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


private slots:
    void on_shockButton_clicked();
    void on_onButton_clicked();

private:
    Ui::MainWindow *ui;
    AEDSimulation aedSimulation;  // AEDSimulation as a member variable

    void updateInterface();
    void updateCheckpoints(int step);
    void updateStatusDisplay();
};

#endif // MAINWINDOW_H
