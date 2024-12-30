#include "analyzerwindow.h"
#include "ui_analyzerwindow.h"


AnalyzerWindow::AnalyzerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AnalyzerWindow)
{
    ui->setupUi(this);
}

AnalyzerWindow::~AnalyzerWindow()
{
    delete ui;
}
