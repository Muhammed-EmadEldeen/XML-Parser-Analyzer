#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QListView>
#include <QFile>
#include <QStandardItem>
#include <QDebug>
#include "XmlParser.cpp"


QString file ;


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

     file =
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






void MainWindow::on_Prettifybtn_clicked()
{
    //XmlParser::prettifyXML() ;      ////////should take some parameters
 }


 void MainWindow::on_Minifybtn_clicked()
 {
     //XmlParser::minifyXML();
 }

void MainWindow::on_Detectbtn_clicked()
{
    XmlParser::XML_error_detection();
}


void MainWindow::on_correctbtn_clicked()
{
   // XmlParser::correctXml() ;
}


void MainWindow::on_Compressbtn_clicked()
{
    //XmlParser::byte_pair_compress( &file) ;
}


void MainWindow::on_Decompressbtn_clicked()
{
    XmlParser::decompress();
}



void MainWindow::on_XMLExpButton_clicked()
{

}


void MainWindow::on_JsonExpButton_clicked()
{
    XmlParser::json();
}


