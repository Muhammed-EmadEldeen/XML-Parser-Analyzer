#include "ParserWindow.h"
#include "ui_ParserWindow.h"
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

//#include "XmlParser.cpp"
//#include "XmlParser/XmlParser.h"

//#include "XmlParser/Tags_utilities.h"
//displayVectorInListWidget

QString file ;


bool ParserWindow::saveToFile(const QString &filePath, const QString &content) {
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

ParserWindow::ParserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ParserWindow)
    , model_1(new QStandardItemModel(this))
{
    ui->setupUi(this);
    //connect(ui->Detectbtn , &QPushButton::clicked , this , &ParserWindow::on_Detectbtn_clicked);
    ui->listView->setModel(model_1);
}

ParserWindow::~ParserWindow()
{

    delete ui;
}

void ParserWindow::on_ImportButton_clicked()
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




void ParserWindow::loadXMLAsPlainText(const QString &filePath)
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

void ParserWindow::displayVectorInListWidget(const std::vector<Error> &errors, QListWidget *listWidget) {
    listWidget->clear();
    for (const auto &item : errors) {
        listWidget->addItem(QString::fromStdString(item.toString()));
    }
}

void ParserWindow::on_textEdit_textChanged()
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




void ParserWindow::on_Prettifybtn_clicked()
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


void ParserWindow::on_Minifybtn_clicked() {
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

void ParserWindow::on_Detectbtn_clicked()
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

*/




void ParserWindow::on_correctbtn_clicked()
{

    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFileName = QDir::currentPath() + "/temp_input.xml";
        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Corrected XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Decompressed XML file.");
            return;
        }

        if (saveToFile(inputFileName, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFileName;

            vector<string> xmlLines = readXmlFile(inputFileName.toStdString());
            vector<string> correctedXml = correctXml(xmlLines) ;
            writeXmlFile(outputFileName.toStdString(), correctedXml);
            loadXMLAsPlainText(outputFileName);

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


        vector<string> xmlLines = readXmlFile(inputFileName.toStdString());
        vector<string> correctedXml = correctXml(xmlLines) ;
        writeXmlFile(outputFileName.toStdString(), correctedXml);
        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Correction Completed", "The XML file has been corrected and saved.");
    }

}

/*


void ParserWindow::on_Decompressbtn_clicked()
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


*/





void ParserWindow::on_JsonExpButton_clicked()
{
    QString textContent = ui->textEdit->toPlainText();

    /*if (!textContent.isEmpty()) {
        QString inputFileName = QDir::currentPath() + "/temp_input.xml";
        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Corrected XML File", "", "XML Files (*.xml)");

        if (inputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the Decompressed XML file.");
            return;
        }


            vector<string> xmlLines = readXmlFile(inputFileName.toStdString());
            vector<string> correctedXml = correctXml(xmlLines) ;
            writeXmlFile(outputFileName.toStdString(), c        if (saveToFile(inputFileName, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFileName;
orrectedXml);
            loadXMLAsPlainText(outputFileName);

        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {*/
    QString inputFileName = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

    if (inputFileName.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please select an XML file to Decompressed.");
        return;
    }

    QString outputFileName = QFileDialog::getSaveFileName(this, "Save Decompressed XML File", "", "XML Files (*.json)");

    if (outputFileName.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please select a location to save the Decompressed XML file.");
        return;
    }


    //XmlParser::prettifyXML(inputFileName.toStdString(), outputFileName.toStdString());


    std::string inputFileNameStr = inputFileName.toStdString();
    std::string outputFileNameStr = outputFileName.toStdString();
    //XmlParser::json(inputFileNameStr, outputFileNameStr);
    XmlParser::json(inputFileNameStr , outputFileNameStr);
    loadXMLAsPlainText(outputFileName);
    QMessageBox::information(this, "Correction Completed", "The XML file has been corrected and saved.");

}



void ParserWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}





void ParserWindow::on_textEdit_copyAvailable(bool b)
{

}


void ParserWindow::on_listView_activated(const QModelIndex &index)
{

}







void ParserWindow::on_listView_windowTitleChanged(const QString &title)
{

}

void on_listWidget_currentItemChanged (QListWidgetItem *current, QListWidgetItem *previous){

}



void ParserWindow::on_Compressbtn_clicked()
{

    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFileName = QDir::currentPath() + "/temp_input.xml";
        QString outputFileName = QFileDialog::getSaveFileName(this, "Save Minified XML File", "", "XML Files (*.xml)");

        if (outputFileName.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the minified XML file.");
            return;
        }

        if (saveToFile(inputFileName, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFileName;


            string content = read_file(inputFileName.toStdString());
            string result = XmlParser::byte_pair_compress(content);

            write_file(outputFileName.toStdString(), result);

            for (const auto& pair : mapping) {
                cout << pair.first << " -> " << pair.second << endl;
            }

            loadXMLAsPlainText(outputFileName);
            QMessageBox::information(this, "Compression Complete", "The XML file has been Compressed and saved.");
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

        string content = read_file(inputFileName.toStdString());
        string result = XmlParser::byte_pair_compress(content);

        write_file(outputFileName.toStdString(), result);

        for (const auto& pair : mapping) {
            cout << pair.first << " -> " << pair.second << endl;
        }

        loadXMLAsPlainText(outputFileName);
        QMessageBox::information(this, "Compression Complete", "The XML file has been Compressed and saved.");


    }

}


void ParserWindow::on_XMLExpButton_clicked()
{
    QString outputFilePath = QFileDialog::getSaveFileName(this, "Save XML File", "", "XML Files (*.xml)");
    qDebug() << "Failed to open file for writing:" << outputFilePath  ;
    if (outputFilePath.isEmpty()) {
        QMessageBox::warning(this, "No File Selected", "Please select a location to save the XML file.");
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

/*
void ParserWindow::on_Detectbtn_clicked()
{

    QString textContent = ui->textEdit->toPlainText();


    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";



        if (saveToFile(inputFilePath, textContent)) {

            vector <Error> errors = XmlParser::XML_error_detection(inputFilePath.toStdString());
            displayVectorInListWidget(errors , ui->listWidget);

        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFilePath = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");

        if (inputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file to minify.");
            return;
        }




        vector <Error> errors = XmlParser::XML_error_detection(inputFilePath.toStdString());
        displayVectorInListWidget(errors , ui->listWidget);





    }

}*/

void ParserWindow::on_Detectbtn_clicked() {
    QString textContent =ui-> textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        // Case 1: User entered XML content in QTextEdit
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        if (saveToFile(inputFilePath, textContent)) {
            auto errors = XmlParser::XML_error_detection(inputFilePath.toStdString());
            displayVectorInListWidget(errors,ui-> listWidget);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }
    } else {
        // Case 2: No content in QTextEdit, prompt for file selection
        QString inputFilePath = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");
        if (inputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file.");
            return;
        }

        auto errors = XmlParser::XML_error_detection(inputFilePath.toStdString());
        displayVectorInListWidget(errors,ui-> listWidget);
    }
}
/*
void ParserWindow::on_Detectbtn_clicked() {
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        if (saveToFile(inputFilePath, textContent)) {
            auto errors = XmlParser::XML_error_detection(inputFilePath.toStdString());
            displayVectorInListWidget(errors, ui->listWidget);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }
    }
}

*/

void ParserWindow::on_Decompressbtn_clicked()
{
    QString textContent = ui->textEdit->toPlainText();

    if (!textContent.isEmpty()) {
        QString inputFilePath = QDir::currentPath() + "/temp_input.xml";
        QString mappingFile = QFileDialog::getOpenFileName(this, "Open TXT File", "", "XML Files (*.txt)");
        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the prettified XML file.");
            return;
        }

        if (saveToFile(inputFilePath, textContent)) {
            qDebug() << "Content of textEdit saved to:" << inputFilePath;
            XmlParser::decompress(inputFilePath.toStdString() , mappingFile.toStdString() , outputFilePath.toStdString()) ;
            qDebug() << "XML. Output saved to:" << outputFilePath;
            loadXMLAsPlainText(outputFilePath);
        } else {
            QMessageBox::critical(this, "Error", "Failed to save the temporary input file.");
        }

    } else {
        QString inputFilePath = QFileDialog::getOpenFileName(this, "Open XML File", "", "XML Files (*.xml)");
        QString mappingFile = QFileDialog::getOpenFileName(this, "Open TXT File", "", "XML Files (*.txt)");

        if (inputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file.");
            return;
        }
        if (mappingFile.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select an XML file.");
            return;
        }

        QString outputFilePath = QFileDialog::getSaveFileName(this, "Save XML File", "", "XML Files (*.xml)");

        if (outputFilePath.isEmpty()) {
            QMessageBox::warning(this, "No File Selected", "Please select a location to save the XML file.");
            return;
        }


        XmlParser::decompress(inputFilePath.toStdString() , mappingFile.toStdString() , outputFilePath.toStdString()) ;
        loadXMLAsPlainText(outputFilePath);
        QMessageBox::information(this, "Complete", "The XML file has been saved.");
    }

}
