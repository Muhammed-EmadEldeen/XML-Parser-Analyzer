#include <fstream>
#include <iostream>
#include <regex>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void parseXMLToString(const string &inputFilePath,
                      const string &outputFilePath) {
  ifstream inputFile(inputFilePath);
  ofstream outputFile(outputFilePath);

  if (!inputFile.is_open()) {
    cerr << "Error: Cannot open input file!" << endl;
    return;
  }
  if (!outputFile.is_open()) {
    cerr << "Error: Cannot open output file!" << endl;
    return;
  }

  string line;
  regex tagRegex(R"(<[^>]+>)");
  smatch match;

  while (getline(inputFile, line)) {
    // Trim the line to check if it's empty or contains only spaces
    line.erase(0, line.find_first_not_of(" \t"));
    line.erase(line.find_last_not_of(" \t") + 1);

    // Skip lines that are empty or contain only whitespace
    if (line.empty()) {
      continue;
    }

    size_t pos = 0;
    while (pos < line.size()) {
      string remaining =
          line.substr(pos); // Process the remaining part of the line
      if (regex_search(remaining, match, tagRegex)) {
        size_t tagStart = match.position();
        size_t tagEnd = tagStart + match.length();

        // Extract and write data before the tag (if any)
        if (tagStart > 0) {
          string data = remaining.substr(0, tagStart);
          if (!data.empty()) {
            outputFile << data << endl;
          }
        }

        // Write the tag itself
        outputFile << match.str() << endl;

        // Move position past the processed tag
        pos += tagEnd;
      } else {
        // Write remaining part as data if no more tags are found
        string data = remaining;
        if (!data.empty()) {
          outputFile << data << endl;
        }
        break;
      }
    }
  }

  inputFile.close();
  outputFile.close();

  cout << "XML file successfully parsed into: " << outputFilePath << endl;
}

vector<string> readXmlFile(const string &filename) {
  vector<string> xmlLines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    xmlLines.push_back(line);
  }
  return xmlLines;
}

void writeXmlFile(const string &filename, const vector<string> &xmlLines) {
  ofstream file(filename);
  for (const auto &line : xmlLines) {
    file << line << endl;
  }
}
