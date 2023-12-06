#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString imagePath = QDir::currentPath() + "/Images/main.png";
    qDebug() << imagePath;
    QPixmap pix(imagePath);
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

