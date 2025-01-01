#include "XmlParser.h"
#include "help_func.h"
#include <stack>
#include <string>
#include <vector>

using namespace std;

void correct(string fileName, string outputFile) {
  vector<Error> errors = XmlParser::XML_error_detection(fileName);

  vector<string> correctedXml;
  stack<string> tagStack;
  vector<string> xmlLines = readXmlFile(fileName);
  for (int i = 0; i < xmlLines.size(); ++i) {
    string line = xmlLines[i];
    bool temp = true;
    for (Error error : errors) {
      if (i + 1 == error.tagLine) {
        if (error.errType == ErrorType::UnClosed) {
          correctedXml.push_back(line);
          correctedXml.push_back("</" + error.tagName + ">");

        } else if (error.errType == ErrorType::UnOpened) {
          correctedXml.push_back("<" + error.tagName + ">");
          correctedXml.push_back(line);
        }
        temp = false;
        break;
      }
    }
    if (temp) {
      correctedXml.push_back(line);
    }
  }
  writeXmlFile(outputFile, correctedXml);
}
