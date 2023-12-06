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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_6;
    QLabel *mainImage;
    QTextBrowser *centerDisplay;
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
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 90, 45, 26));
        spinBox->setMinimum(1);
        spinBox->setMaximum(7);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 90, 83, 25));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 140, 131, 31));
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
        plainTextEdit_4->setGeometry(QRect(30, 290, 131, 31));
        plainTextEdit_4->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName(QString::fromUtf8("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(30, 340, 131, 31));
        plainTextEdit_5->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        plainTextEdit_6 = new QPlainTextEdit(centralwidget);
        plainTextEdit_6->setObjectName(QString::fromUtf8("plainTextEdit_6"));
        plainTextEdit_6->setGeometry(QRect(30, 390, 161, 31));
        plainTextEdit_6->setStyleSheet(QString::fromUtf8("background-color: grey;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: none;"));
        mainImage = new QLabel(centralwidget);
        mainImage->setObjectName(QString::fromUtf8("mainImage"));
        mainImage->setGeometry(QRect(260, 10, 481, 501));
        centerDisplay = new QTextBrowser(centralwidget);
        centerDisplay->setObjectName(QString::fromUtf8("centerDisplay"));
        centerDisplay->setGeometry(QRect(400, 180, 161, 81));
        centerDisplay->setStyleSheet(QString::fromUtf8("background-color:white;"));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "1. Turn On AED", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("MainWindow", "2. Place Electropads", nullptr));
        plainTextEdit_3->setPlainText(QCoreApplication::translate("MainWindow", "3. Analyze Heart Rythm", nullptr));
        plainTextEdit_4->setPlainText(QCoreApplication::translate("MainWindow", "4. Deliver Shock", nullptr));
        plainTextEdit_5->setPlainText(QCoreApplication::translate("MainWindow", "5. Perform CPR", nullptr));
        plainTextEdit_6->setPlainText(QCoreApplication::translate("MainWindow", "6. Monitor Patient", nullptr));
        mainImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
