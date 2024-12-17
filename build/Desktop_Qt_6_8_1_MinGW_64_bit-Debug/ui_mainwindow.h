/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Prettifybtn;
    QPushButton *Detectbtn;
    QPushButton *correctbtn;
    QPushButton *Compressbtn;
    QPushButton *Decompressbtn;
    QListView *listView;
    QListWidget *listWidget;
    QPushButton *Minifybtn;
    QPushButton *JsonExpButton;
    QPushButton *XMLExpButton;
    QTextEdit *textEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Prettifybtn = new QPushButton(centralwidget);
        Prettifybtn->setObjectName("Prettifybtn");
        Prettifybtn->setGeometry(QRect(20, 410, 93, 29));
        Detectbtn = new QPushButton(centralwidget);
        Detectbtn->setObjectName("Detectbtn");
        Detectbtn->setGeometry(QRect(270, 410, 93, 29));
        correctbtn = new QPushButton(centralwidget);
        correctbtn->setObjectName("correctbtn");
        correctbtn->setGeometry(QRect(400, 410, 93, 29));
        Compressbtn = new QPushButton(centralwidget);
        Compressbtn->setObjectName("Compressbtn");
        Compressbtn->setGeometry(QRect(520, 410, 93, 29));
        Decompressbtn = new QPushButton(centralwidget);
        Decompressbtn->setObjectName("Decompressbtn");
        Decompressbtn->setGeometry(QRect(640, 410, 93, 29));
        listView = new QListView(centralwidget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(160, 20, 431, 311));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(160, 340, 431, 51));
        Minifybtn = new QPushButton(centralwidget);
        Minifybtn->setObjectName("Minifybtn");
        Minifybtn->setGeometry(QRect(150, 410, 93, 29));
        JsonExpButton = new QPushButton(centralwidget);
        JsonExpButton->setObjectName("JsonExpButton");
        JsonExpButton->setGeometry(QRect(250, 480, 111, 31));
        JsonExpButton->setStyleSheet(QString::fromUtf8(""));
        XMLExpButton = new QPushButton(centralwidget);
        XMLExpButton->setObjectName("XMLExpButton");
        XMLExpButton->setGeometry(QRect(400, 480, 111, 31));
        XMLExpButton->setStyleSheet(QString::fromUtf8(""));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(603, 120, 181, 211));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(650, 90, 141, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Prettifybtn->setText(QCoreApplication::translate("MainWindow", "Prettify", nullptr));
        Detectbtn->setText(QCoreApplication::translate("MainWindow", "Detect", nullptr));
        correctbtn->setText(QCoreApplication::translate("MainWindow", "Correct", nullptr));
        Compressbtn->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        Decompressbtn->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        Minifybtn->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        JsonExpButton->setText(QCoreApplication::translate("MainWindow", "Export As Json", nullptr));
        XMLExpButton->setText(QCoreApplication::translate("MainWindow", "Export As XML", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
