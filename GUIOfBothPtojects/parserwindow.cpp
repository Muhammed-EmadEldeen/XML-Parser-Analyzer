#include "parserwindow.h"
#include "ui_parserwindow.h"

ParserWindow::ParserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ParserWindow)
{
    ui->setupUi(this);
}

ParserWindow::~ParserWindow()
{
    delete ui;
}
