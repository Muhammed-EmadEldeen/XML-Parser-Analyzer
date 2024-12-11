#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QListView>
#include <QFile>
#include <QStandardItem>
#include <QDebug>


void saveFile() {
    // Save file dialog

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model_1(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->listView->setModel(model_1);
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
        loadXMLAsPlainText(file);
        QMessageBox::information(this , tr("File Selected")  , tr("File Selected Successfully") ) ;

    }
}

void MainWindow::loadXMLAsPlainText(const QString &filePath)
{
    model_1->clear(); // Clear the model for fresh data
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open the file.");
        return;
    }

    // Read the file line by line and add each line as an item in the model
    while (!file.atEnd()) {
        QString line = file.readLine().trimmed(); // Read and trim each line
        QStandardItem *item = new QStandardItem(line);
        model_1->appendRow(item); // Add the line as an item in the model
    }

    file.close();
}



void MainWindow::on_label_linkActivated(const QString &link)
{

}



void MainWindow::on_Prettifybtn_clicked()
{
    QFile data("output.txt");

     if (!data.open(QFile::WriteOnly | QFile::Truncate)) {

        qDebug() << "Can't open file";


    }
}

