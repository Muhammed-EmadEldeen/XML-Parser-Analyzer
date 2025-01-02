#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string.h>
#include "XmlParser.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        "QPushButton {"
        "background-color: #31374b;"
        "color: white;"
        "font-size: 13px;"
        "font-weight: bold;"
        "border-radius: 10px;"
        "padding: 5px 5px;"
        "border: 2px solid #444;"
        "border-color: white ; "
        "background-clip: border;"
        "background-origin: content; }"


        "QPushButton:hover {"
        "background-color: red;"
        "color: yellow; }"



        "QLabel {"
        "   color: white;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   padding: 1px;"
        "}"




        "QListView { "
        "background-color:white;"
        "border : 4px solid white ; "
        "border-radius: 7px ;"
        "color: white ;}"


        "QTextEdit{"
        "background-color:white;"
        "border : 4px solid white ; "
        "border-radius: 7px ;"
        "color: white ;}"




        "QWidget {"
        "background-color: #222339;"
        "font-family: Arial, sans-serif; }"



        );
    MainWindow w;
    w.show();
    return a.exec();



}






