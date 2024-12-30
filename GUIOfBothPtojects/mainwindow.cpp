#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "parserwindow.h"
#include "analyzerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ParserButton_clicked()
{
    ParserWindow myParserWindow;
    myParserWindow.setModal(true);
    myParserWindow.exec();
}


void MainWindow::on_AnalyzerButton_clicked()
{
    AnalyzerWindow myAnalyzerWindow;
    myAnalyzerWindow.setModal(true);
    myAnalyzerWindow.exec();
}

