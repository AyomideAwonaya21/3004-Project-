#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include <QDebug>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    aedSimulation = new AEDSimulation(ui); // Initialize AEDSimulation

    // Set the main image using the provided path
    QString imagePath = QDir::currentPath() + "/Images/main.png";
    QPixmap pix(imagePath);
    ui->mainImage->setPixmap(pix);

    // this is for the timer
    ui->timeText->setPlainText("00:00");

    // Connect buttons to their respective slots
    //connect(ui->shockButton, &QPushButton::clicked, this, &MainWindow::on_shockButton_clicked);
    connect(ui->onButton, &QPushButton::clicked, [=](){
        int useCaseNumber = ui->useCaseNumber->value();
        onButtonClicked(useCaseNumber);
    });

    // Connect the AEDSimulation signals to MainWindow slots
    connect(aedSimulation, &AEDSimulation::updateInterfaceSignal, this, &MainWindow::updateInterface);
    // Set the initial size of the MainWindow
    resize(800, 600);
}

MainWindow::~MainWindow() {
    // Stop the simulation before the MainWindow is destroyed
    aedSimulation->stopSimulation();
    delete aedSimulation; // Delete the aedSimulation object
    delete ui;
}
void MainWindow::onButtonClicked(int useCaseNumber) {
    // Handle logic when the on button is clicked
    aedSimulation->powerOn(useCaseNumber);
    updateInterface();
}
/*Updates the buttons on the interface and the text displayed in the middle*/
void MainWindow::updateInterface() {
    if(aedSimulation->getCurrentStep() == 6){
        ui->instructionText->setFontPointSize(7);
    }
    else{
        ui->instructionText->setFontPointSize(9);
    }
    // Update the user interface elements based on the state of the AED simulation
    ui->instructionText->setPlainText(QString::fromStdString(aedSimulation->getCurrentInstruction()));
    ui->timeText->setPlainText(QString::fromStdString(aedSimulation->getCurrentTime()));
    ui->shockText->setPlainText(QString("SHOCKS ") + QString::number(aedSimulation->getShockCount()));
    ui->onSignal->setStyleSheet(aedSimulation->isPoweredOn() ? "background-color: green;" : "background-color: grey;");

    std::stringstream feedbackStream;
    feedbackStream << "Battery: " << aedSimulation->getBatteryLife()<<"%";
     std::string batteryString = feedbackStream.str();


     QString batteryText = QString::fromStdString(batteryString);
     QString styleSheet;

     if (aedSimulation->getBatteryLife() <= 100 && aedSimulation->getBatteryLife() > 70) {
         styleSheet = "background-color: lightgreen; font-size: 10px;";
     } else if (aedSimulation->getBatteryLife() <= 70 && aedSimulation->getBatteryLife() >= 50) {
         styleSheet = "background-color: lightyellow; font-size: 10px;";
     } else if (aedSimulation->getBatteryLife() < 50) {
         styleSheet = "background-color: red; font-size: 10px;";
     }

     ui->batteryText->setPlainText(batteryText);
     ui->batteryText->setStyleSheet(styleSheet);

    // Update the checkpoint indicators based on the current step of the simulation
    updateCheckpoints(aedSimulation->getCurrentStep());
}
/*Updates the button step colors*/
void MainWindow::updateCheckpoints(int step) {
    //qDebug() << step;
    // Update the color of each checkpoint based on the current step of the simulation
    ui->checkPoint1->setStyleSheet(step == 1 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint2->setStyleSheet(step == 2 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint3->setStyleSheet(step == 3 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint4->setStyleSheet(step == 4 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint5->setStyleSheet(step == 5 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint6->setStyleSheet(step == 6 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint7->setStyleSheet(step == 7 ? "background-color: green;" : "background-color: grey;");

}
