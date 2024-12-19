#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "help_func.cpp"
#include "XmlParser.h"

using namespace std;

enum ErrorType{UnClosed,UnOpened};

struct Error{
    string tag;
    int line;
    ErrorType error;

    Error(string t,int l,ErrorType e){
        tag = t;
        line = l;
        error = e;
    }
};

void correct(string fileName, string outputFile){
    vector<Error>  errors = XmlParser::XML_error_detection();

    vector<string> correctedXml;
    stack<string> tagStack;
    vector<string> xmlLines = readXmlFile(fileName);
    for (int i = 0; i < xmlLines.size(); ++i) {
    string line = xmlLines[i];
    bool temp=true;
    for(Error error:errors){
        if(i+1==error.line){
            if(error.error== ErrorType::UnClosed)
            {
                 correctedXml.push_back(line);
                 correctedXml.push_back("</" + error.tag + ">");

            }
            else if(error.error == ErrorType::UnOpened)
            {
                correctedXml.push_back("<" + error.tag + ">");
                correctedXml.push_back(line);
            }
            temp = false;
            break;
        }
    }
    if(temp){
        correctedXml.push_back(line);
    }


    }
    writeXmlFile(outputFile, correctedXml);
}