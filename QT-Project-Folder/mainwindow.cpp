#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/student/Desktop/Final Project/3004-Project-/QT-Project-Folder/Images/main.png");
    ui->mainImage->setPixmap(pix);

    //the checkpoints are for the images, light them green when the image is active and play audio
    //ui->checkPoint1;
    //ui->checkPoint2;
    //ui->checkPoint3;
    //ui->checkPoint4;
    //ui->checkPoint5;
    //ui->checkPoint6;

    //this is the button to apply the shock
    //ui->shockButton;

    //the components for turning AED on, flash signal to green when on
    //ui->onSignal;
    //ui->onButton;

    //these texts are for the main display on the AED
   // ui->shockText;
    //ui->timeText;
    //ui->instructionText;

    resize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

