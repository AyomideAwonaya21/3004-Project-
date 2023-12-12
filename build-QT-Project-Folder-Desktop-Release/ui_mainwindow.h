/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QSpinBox *useCaseNumber;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_6;
    QLabel *mainImage;
    QTextBrowser *centerDisplay;
    QTextBrowser *checkPoint1;
    QTextBrowser *checkPoint6;
    QTextBrowser *checkPoint4;
    QTextBrowser *checkPoint3;
    QTextBrowser *checkPoint2;
    QTextBrowser *checkPoint5;
    QPushButton *shockButton;
    QPushButton *onButton;
    QTextBrowser *onSignal;
    QPlainTextEdit *shockText;
    QPlainTextEdit *timeText;
    QTextEdit *instructionText;
    QTextBrowser *checkPoint7;
    QLabel *testIMG;
    QTextBrowser *padsOn;
    QPushButton *nextButton;
    QPushButton *placePadsButton;
    QPushButton *CPRButton;
    QSpinBox *depthNumber;
    QPlainTextEdit *batteryText;
    QPlainTextEdit *plainTextEdit_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(749, 581);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 811, 601));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 256, 541));
        textBrowser_2->setStyleSheet(QString::fromUtf8("border-right: 1px solid black;"));
        useCaseNumber = new QSpinBox(centralwidget);
        useCaseNumber->setObjectName(QString::fromUtf8("useCaseNumber"));
        useCaseNumber->setGeometry(QRect(30, 90, 45, 26));
        useCaseNumber->setMinimum(1);
        useCaseNumber->setMaximum(7);
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 140, 211, 31));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(30, 190, 161, 31));
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(30, 240, 201, 31));
        plainTextEdit_3->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(30, 290, 181, 31));
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName(QString::fromUtf8("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(30, 340, 161, 31));
        plainTextEdit_5->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_6 = new QPlainTextEdit(centralwidget);
        plainTextEdit_6->setObjectName(QString::fromUtf8("plainTextEdit_6"));
        plainTextEdit_6->setGeometry(QRect(30, 390, 201, 31));
        plainTextEdit_6->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        mainImage = new QLabel(centralwidget);
        mainImage->setObjectName(QString::fromUtf8("mainImage"));
        mainImage->setGeometry(QRect(260, 0, 481, 501));
        centerDisplay = new QTextBrowser(centralwidget);
        centerDisplay->setObjectName(QString::fromUtf8("centerDisplay"));
        centerDisplay->setGeometry(QRect(400, 180, 161, 101));
        centerDisplay->setStyleSheet(QString::fromUtf8("background-color:white;"));
        checkPoint1 = new QTextBrowser(centralwidget);
        checkPoint1->setObjectName(QString::fromUtf8("checkPoint1"));
        checkPoint1->setGeometry(QRect(370, 240, 16, 16));
        checkPoint1->setStyleSheet(QString::fromUtf8("height: 20px;\n"
"width:20px;\n"
"border-radius: 50%;\n"
"background-color: grey;"));
        checkPoint6 = new QTextBrowser(centralwidget);
        checkPoint6->setObjectName(QString::fromUtf8("checkPoint6"));
        checkPoint6->setGeometry(QRect(380, 370, 16, 16));
        checkPoint6->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        checkPoint4 = new QTextBrowser(centralwidget);
        checkPoint4->setObjectName(QString::fromUtf8("checkPoint4"));
        checkPoint4->setGeometry(QRect(560, 360, 16, 16));
        checkPoint4->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        checkPoint3 = new QTextBrowser(centralwidget);
        checkPoint3->setObjectName(QString::fromUtf8("checkPoint3"));
        checkPoint3->setGeometry(QRect(570, 240, 16, 16));
        checkPoint3->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        checkPoint2 = new QTextBrowser(centralwidget);
        checkPoint2->setObjectName(QString::fromUtf8("checkPoint2"));
        checkPoint2->setGeometry(QRect(500, 140, 16, 16));
        checkPoint2->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        checkPoint5 = new QTextBrowser(centralwidget);
        checkPoint5->setObjectName(QString::fromUtf8("checkPoint5"));
        checkPoint5->setGeometry(QRect(460, 290, 16, 16));
        checkPoint5->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        shockButton = new QPushButton(centralwidget);
        shockButton->setObjectName(QString::fromUtf8("shockButton"));
        shockButton->setGeometry(QRect(420, 330, 91, 25));
        shockButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        onButton = new QPushButton(centralwidget);
        onButton->setObjectName(QString::fromUtf8("onButton"));
        onButton->setGeometry(QRect(580, 450, 83, 25));
        onSignal = new QTextBrowser(centralwidget);
        onSignal->setObjectName(QString::fromUtf8("onSignal"));
        onSignal->setGeometry(QRect(550, 450, 16, 16));
        onSignal->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        shockText = new QPlainTextEdit(centralwidget);
        shockText->setObjectName(QString::fromUtf8("shockText"));
        shockText->setGeometry(QRect(400, 180, 91, 31));
        shockText->setStyleSheet(QString::fromUtf8("border: white;"));
        timeText = new QPlainTextEdit(centralwidget);
        timeText->setObjectName(QString::fromUtf8("timeText"));
        timeText->setGeometry(QRect(510, 180, 51, 31));
        timeText->setStyleSheet(QString::fromUtf8("border: white;"));
        instructionText = new QTextEdit(centralwidget);
        instructionText->setObjectName(QString::fromUtf8("instructionText"));
        instructionText->setGeometry(QRect(400, 210, 161, 51));
        instructionText->setStyleSheet(QString::fromUtf8("border: white;"));
        checkPoint7 = new QTextBrowser(centralwidget);
        checkPoint7->setObjectName(QString::fromUtf8("checkPoint7"));
        checkPoint7->setGeometry(QRect(320, 330, 16, 16));
        checkPoint7->setStyleSheet(QString::fromUtf8("height: 20px;\n"
"width:20px;\n"
"border-radius: 50%;\n"
"background-color: grey;"));
        testIMG = new QLabel(centralwidget);
        testIMG->setObjectName(QString::fromUtf8("testIMG"));
        testIMG->setGeometry(QRect(400, 230, 161, 71));
        padsOn = new QTextBrowser(centralwidget);
        padsOn->setObjectName(QString::fromUtf8("padsOn"));
        padsOn->setGeometry(QRect(630, 240, 16, 16));
        padsOn->setStyleSheet(QString::fromUtf8("border-radius: 50%;\n"
"background-color: grey;"));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(300, 260, 51, 25));
        placePadsButton = new QPushButton(centralwidget);
        placePadsButton->setObjectName(QString::fromUtf8("placePadsButton"));
        placePadsButton->setGeometry(QRect(600, 310, 83, 25));
        CPRButton = new QPushButton(centralwidget);
        CPRButton->setObjectName(QString::fromUtf8("CPRButton"));
        CPRButton->setGeometry(QRect(342, 400, 41, 25));
        depthNumber = new QSpinBox(centralwidget);
        depthNumber->setObjectName(QString::fromUtf8("depthNumber"));
        depthNumber->setGeometry(QRect(290, 400, 45, 26));
        depthNumber->setMaximum(5);
        batteryText = new QPlainTextEdit(centralwidget);
        batteryText->setObjectName(QString::fromUtf8("batteryText"));
        batteryText->setGeometry(QRect(470, 150, 91, 31));
        batteryText->setStyleSheet(QString::fromUtf8("font-size: 10px;"));
        plainTextEdit_7 = new QPlainTextEdit(centralwidget);
        plainTextEdit_7->setObjectName(QString::fromUtf8("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(30, 440, 161, 31));
        plainTextEdit_7->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 749, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\" bgcolor=\"#808080\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "1. Device Self Check Test", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("MainWindow", "2. Regular HB (PEA)", nullptr));
        plainTextEdit_3->setPlainText(QCoreApplication::translate("MainWindow", "3. Regular HB (Flatlined)", nullptr));
        plainTextEdit_4->setPlainText(QCoreApplication::translate("MainWindow", "4. Irregular HB (VF)", nullptr));
        plainTextEdit_5->setPlainText(QCoreApplication::translate("MainWindow", "5. Irregular HB (VT)", nullptr));
        plainTextEdit_6->setPlainText(QCoreApplication::translate("MainWindow", "6. Pad Already on Patient", nullptr));
        mainImage->setText(QString());
        shockButton->setText(QCoreApplication::translate("MainWindow", "Apply Shock", nullptr));
        onButton->setText(QCoreApplication::translate("MainWindow", "Turn On", nullptr));
        shockText->setPlainText(QCoreApplication::translate("MainWindow", "SHOCKS 00", nullptr));
        timeText->setPlainText(QString());
        instructionText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        testIMG->setText(QString());
        nextButton->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        placePadsButton->setText(QCoreApplication::translate("MainWindow", "Place Pads", nullptr));
        CPRButton->setText(QCoreApplication::translate("MainWindow", "CPR", nullptr));
        batteryText->setPlainText(QCoreApplication::translate("MainWindow", "Battery 100%", nullptr));
        plainTextEdit_7->setPlainText(QCoreApplication::translate("MainWindow", "7. Low Battery Life", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
