#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QListView>

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

void MainWindow::on_pushButton_clicked()
{

    QString file =
        QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen",
                                     "XML files (*.xml)");

    if (file.isEmpty()){
        QMessageBox::warning(this , tr("No file ")  , tr("No file selected") ) ;

    }else {
        QMessageBox::information(this , tr("File Selected")  , tr("File Selected Successfully") ) ;

    }
}


void MainWindow::on_label_linkActivated(const QString &link)
{

}


