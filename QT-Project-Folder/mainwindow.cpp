#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), aedSimulation() {
    ui->setupUi(this);

    // Set the main image using the provided path
    //QPixmap pix("/home/student/Desktop/Final Project/3004-Project-/QT-Project-Folder/Images/main.png");
    QString imagePath = QDir:: currentPath()+"/Images/main.png";
    QPixmap pix(imagePath);
    qDebug() << imagePath;
    ui->mainImage->setPixmap(pix);

    // Connect buttons to their respective slots
    //connect(ui->shockButton, &QPushButton::clicked, this, &MainWindow::on_shockButton_clicked);
    //connect(ui->onButton, &QPushButton::clicked, this, &MainWindow::on_onButton_clicked);

    // Start the AED simulation
    //aedSimulation.startSimulation();

    // Set the initial size of the MainWindow
    resize(800, 600);
}

MainWindow::~MainWindow() {
    // Stop the simulation before the MainWindow is destroyed
    aedSimulation.stopSimulation();
    delete ui;
}

void MainWindow::on_shockButton_clicked() {
    // Handle logic when the shock button is clicked
    aedSimulation.deliverShock(); // Assuming this method exists in AEDSimulation
    updateInterface();
}

void MainWindow::on_onButton_clicked() {
    // Handle logic when the on button is clicked
    aedSimulation.powerOn(); // Assuming this method exists in AEDSimulation
    updateInterface();
}

void MainWindow::updateInterface() {
    // Update the user interface elements based on the state of the AED simulation
    ui->instructionText->setPlainText(QString::fromStdString(aedSimulation.getCurrentInstruction()));
    ui->timeText->setPlainText(QString::fromStdString(aedSimulation.getCurrentTime()));
    ui->shockText->setPlainText(QString("SHOCKS ") + QString::number(aedSimulation.getShockCount()));
    ui->onSignal->setStyleSheet(aedSimulation.isPoweredOn() ? "background-color: green;" : "background-color: grey;");

    // Update the checkpoint indicators based on the current step of the simulation
    updateCheckpoints(aedSimulation.getCurrentStep());
}

void MainWindow::updateCheckpoints(int step) {
    // Update the color of each checkpoint based on the current step of the simulation
    ui->checkPoint1->setStyleSheet(step >= 1 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint2->setStyleSheet(step >= 2 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint3->setStyleSheet(step >= 3 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint4->setStyleSheet(step >= 4 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint5->setStyleSheet(step >= 5 ? "background-color: green;" : "background-color: grey;");
    ui->checkPoint6->setStyleSheet(step >= 6 ? "background-color: green;" : "background-color: grey;");
}
