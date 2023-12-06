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
    resize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

