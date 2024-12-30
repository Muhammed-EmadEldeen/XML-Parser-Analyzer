#include "XmlParser.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Function to prettify XML
void XmlParser::prettifyXML(const string &inputFileName,
                            const string &outputFileName) {
  ifstream inputFile(inputFileName);
  if (!inputFile.is_open()) {
    cerr << "Error: Unable to open input file: " << inputFileName << std::endl;
    return;
  }

  ofstream outputFile(outputFileName);
  if (!outputFile.is_open()) {
    cerr << "Error: Unable to open output file: " << outputFileName
         << std::endl;
    return;
  }

  string line, xmlContent;
  vector<string> xmlContentSec; // Vector to hold all lines from the input file
  while (getline(inputFile, line)) {
    xmlContentSec.push_back(line);
  }
  inputFile.close();

  // Variables to hold the prettified XML content, tags, and normal text
  string normal;
  string tag;

  stack<int> in; // Stack to manage indentation levels for nested tags
  bool insideTag =
      false; // Flag to check if the current character is within a tag
  int indentationLevel = 0; // Keeps track of the current indentation level
  int f = 0;                // Flag to manage single line tags

  for (const auto &l :
       xmlContentSec) { // minify the input first to remove already indentations
    int j = 0;
    // Remove leading whitespace from the line
    while (l.size() && isspace(static_cast<unsigned char>(l[j]))) {
      j++;
    }
    xmlContent += l.substr(j);
  }

  unsigned int size = xmlContent.size();

  // Iterate over each character in the XML content
  for (unsigned int i = 0; i < size; i++) {
    char ch = xmlContent[i];

    // Detect opening of a tag
    if (ch == '<') {
      if (!normal.empty() && !tag.empty()) {
        // Handle normal text inside tags
        if (normal.length() > 20) {
          outputFile << string(indentationLevel * 4, ' ') << tag << endl;
          outputFile << string((indentationLevel + 1) * 4, ' ') << normal
                     << endl;
          in.push(indentationLevel); // Push current indentation level onto the
                                     // stack
        } else {
          outputFile << string(indentationLevel * 4, ' ') << tag;
          outputFile << normal;
          in.push(indentationLevel);
          f = 1;
        }
        normal.clear(); // Clear normal text buffer
        tag.clear();    // Clear tag buffer
      } else if (!tag.empty() && !insideTag) {
        // Handle tag closing
        if (tag[1] != '/') {
          in.push(indentationLevel);
          outputFile << string(indentationLevel * 4, ' ') << tag << endl;
          indentationLevel++; // Increase indentation for nested tags
          tag.clear();
        } else {
          indentationLevel = in.top(); // Pop the last indentation level
          in.pop();
          if (f == 0) {
            outputFile << string(indentationLevel * 4, ' ') << tag << endl;
          } else {
            outputFile << tag << endl;
            f = 0; // Reset flag for single line tags
          }
          tag.clear();
        }
      }
      insideTag = true; // Mark that we are inside a tag
    }

    if (insideTag) {
      tag += ch; // Append character to tag if inside a tag
    } else {
      normal += ch; // Append character to normal text if outside a tag
    }

    // Detect closing of a tag
    if (ch == '>') {
      insideTag = false;   // Mark that we are no longer inside a tag
      if (i == size - 1) { // Handle the last tag in the XML content
        outputFile << tag;
        in.pop();
      }
    }
  }
}

void XmlParser::minifyXML(const string &inputFileName,
                          const string &outputFileName) {
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

  for (const auto &l : xmlContent) {
    int j = 0;
    // Remove leading whitespace from the line
    while (l.size() && isspace(static_cast<unsigned char>(l[j]))) {
      j++;
    }
    result += l.substr(j);
  }
  outputFile << result;
}
