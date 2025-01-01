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
    if (argc < 2) {
        std::cout << "Usage: " << argv[0]
                  << "Function -i <File Input> -o <File Output>" << std::endl;
        return a.exec();                                  /////////////////////////////////////  RETURN 1 CHANGED TO RETURN a.exec()
    } else {
        if (!strcmp("verify", argv[1])) {
            // function is verify
        } else if (!strcmp("compress", argv[1])) {
            // function is compress
        } else if (!strcmp("decompress", argv[1])) {
            // function is decompress
        } else if (!strcmp("format", argv[1])) {
            // function is format
        } else if (!strcmp("json", argv[1])) {
            // function is json
        } else if (!strcmp("mini", argv[1])) {
            // function is mini
        } else {
            std::cout << "Invalid function" << std::endl;
            return 1;
        }
    }



    /* string mode = argv[1];
    string input_file = argv[3];
    string output_file = argv[5];
    string content = read_file(input_file);
    string result;

    if (mode == "compress") {
        result = XmlParser::byte_pair_compress(content);
    }
    write_file(output_file, result);
    if (mode == "compress") {
        for (const auto& pair : mapping) {
            cout << pair.first << " -> " << pair.second << endl;
        }

    }

*/



}






