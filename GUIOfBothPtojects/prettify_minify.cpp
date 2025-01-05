#include "XmlParser.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>
#include <vector>

using namespace std;



// Function to prettify XML



 void XmlParser::minifyXML(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) { 
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return; 
    }


    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) { 
        cerr << "Error: Unable to open output file: " << outputFileName << endl;
        return; 
    }

    string line; 
    vector<string> xmlContent; // Vector to hold all lines from the input file
    while (getline(inputFile, line)) { 
        xmlContent.push_back(line); 
    }
    inputFile.close(); 

    string result; // String to store the minified XML content

    for (const auto& l : xmlContent) {
        int j = 0;
        // Remove leading whitespace from the line
        while (l.size() && isspace(static_cast<unsigned char>(l[j]))) {
            j++;
        }
        result += l.substr(j);
    }
    outputFile << result;
}
