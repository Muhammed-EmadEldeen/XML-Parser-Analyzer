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
    QPushButton *pushButton;
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
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(162, 480, 111, 29));
        pushButton->setStyleSheet(QString::fromUtf8(""));
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
        JsonExpButton->setGeometry(QRect(310, 480, 111, 29));
        JsonExpButton->setStyleSheet(QString::fromUtf8(""));
        XMLExpButton = new QPushButton(centralwidget);
        XMLExpButton->setObjectName("XMLExpButton");
        XMLExpButton->setGeometry(QRect(450, 480, 121, 29));
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
        menubar->setGeometry(QRect(0, 0, 800, 25));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Import ", nullptr));
        Prettifybtn->setText(QCoreApplication::translate("MainWindow", "Prettify", nullptr));
        Detectbtn->setText(QCoreApplication::translate("MainWindow", "Detect", nullptr));
        correctbtn->setText(QCoreApplication::translate("MainWindow", "Correct", nullptr));
        Compressbtn->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        Decompressbtn->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        Minifybtn->setText(QCoreApplication::translate("MainWindow", "Minify", nullptr));
        JsonExpButton->setText(QCoreApplication::translate("MainWindow", "Export As Json", nullptr));
        XMLExpButton->setText(QCoreApplication::translate("MainWindow", "Export As XML", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
