#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QListView>
#include <QFile>
#include <QStandardItem>
#include <QDebug>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QTextStream>


#include "XmlParser.cpp"

QString file ;


bool MainWindow::saveToFile(const QString &filePath, const QString &content) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << content;
        file.close();
        return true;
    }
    qDebug() << "Failed to open file for writing:" << filePath;
    return false;
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

void MainWindow::on_ImportButton_clicked()
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
        QString smallLine = line.length() > 20 ? line.left(20) + "..." : line;
        QStandardItem *item = new QStandardItem(smallLine);
        model_1->appendRow(item); // Add the line as an item in the model
    }

    file.close();
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    model_1->clear(); // Clear the model for fresh data

    // Split the text into lines and add each line as an item in the model
    QStringList lines = text.split('\n');
    for (const QString &line : lines) {
        QStandardItem *item = new QStandardItem(line.trimmed());
        model_1->appendRow(item);
    }
}




void MainWindow::on_Prettifybtn_clicked()
{
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save prettified XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the prettified XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
            XmlParser::prettifyXML(inputFilePath.toStdString(), outputFilePath.toStdString());
            qDebug() << "XML prettified. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to prettify.");
            return;
        }

        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

        XmlParser::prettifyXML(inputFileName.toStdString(), outputFileName.toStdString());
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "prettify Complete", "The XML file has been prettified and saved.");
    }
}


void MainWindow::on_Minifybtn_clicked() {
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
            XmlParser::minifyXML(inputFilePath.toStdString(), outputFilePath.toStdString());
            qDebug() << "XML minified. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to minify.");
            return;
        }

        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

        XmlParser::minifyXML(inputFileName.toStdString(), outputFileName.toStdString());
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Minify Complete", "The XML file has been minified and saved.");
    }
}
/*

void MainWindow::on_Detectbtn_clicked()
{
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Detection XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Detection XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
            XmlParser::XML_error_detection();
            qDebug() << "XML Detection. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to Detection.");
            return;
        }

        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Detection XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Detection XML file.");
            return;
        }

        XmlParser::XML_error_detection();
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Detection Complete", "The XML file has been Detection and saved.");
    }
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
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Decompressed XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Decompressed XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
            XmlParser::decompress();
            qDebug() << "XML Decompressed. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to Decompressed.");
            return;
        }

        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Decompressed XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Decompressed XML file.");
            return;
        }

        XmlParser::decompress();
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Decompression Complete", "The XML file has been Decompressed and saved.");
    }
}



void MainWindow::on_XMLExpButton_clicked()
{

}


void MainWindow::on_JsonExpButton_clicked()
{
    // XmlParser::json();
}

*/

void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}





void MainWindow::on_textEdit_copyAvailable(bool b)
{

}


void MainWindow::on_listView_activated(const QModelIndex &index)
{

}







void MainWindow::on_listView_windowTitleChanged(const QString &title)
{

}

void on_listWidget_currentItemChanged (QListWidgetItem *current, QListWidgetItem *previous){

}



void MainWindow::on_Compressbtn_clicked()
{

    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
           //////// XmlParser::compress(inputFilePath.toStdString(), outputFilePath.toStdString());
            qDebug() << "XML minified. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to minify.");
            return;
        }

        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

       ///////////// XmlParser::minifyXML(inputFileName.toStdString(), outputFileName.toStdString());
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Minify Complete", "The XML file has been minified and saved.");
    }

}


void MainWindow::on_XMLExpButton_clicked()
{
    QString outputFilePath = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");
    qDebug() << "Failed to open file for writing:" << outputFilePath  ;
    if (outputFilePath.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
        return;
    }
    QFile file (outputFilePath) ;
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open the file.");
        return;
    }

    QTextStream out (&file) ;

    QString content = ui->textEdit->toPlainText() ;
    qDebug() << "Failed to open file for writing:" << content ;
    out<<content ;

    file.close() ;
    QMessageBox::information(this, "File saved", "File Saved Successfully ");




}

