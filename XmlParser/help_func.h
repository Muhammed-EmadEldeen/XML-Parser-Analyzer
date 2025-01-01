#ifndef HELP_FUNC_H
#define HELP_FUNC_H
#include <string>
#include <vector>

using namespace std;

vector<string> readXmlFile(const string &filename);

void parseXMLToString(const string &inputFilePath,
                      const string &outputFilePath);

void writeXmlFile(const string &filename, const vector<string> &xmlLines);
#endif
