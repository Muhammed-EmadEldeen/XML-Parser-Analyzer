#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "XmlParser.cpp"

using namespace std;

void XmlParser::decompress(const string& compressedFile, const string& mappingFile,const string& outputFile) {
    // Open the mapping file
    ifstream myMap(mappingFile);
    if (!myMap.is_open()) {
        cerr << "Error: Unable to open mapping file: " << mappingFile << endl;
        return;
    }

    // Read the mapping file and populate the map
    unordered_map<string, string> decompMap;
    string key, value;
    while (getline(myMap, key) && getline(myMap, value)) {
        decompMap[key] = value;
    }
    myMap.close();

    // Open the compressed file
    ifstream myDecompFile(compressedFile);
    if (!myDecompFile.is_open()) {
        cerr << "Error: Unable to open compressed file: " << compressedFile << endl;
        return;
    }

    // Open the output file for decompressed content
    ofstream decompressedFile(outputFile);
    if (!decompressedFile.is_open()) {
        cerr << "Error: Unable to create decompressed output file." << endl;
        return;
    }

    // Decompress the file
    string line;
    while (getline(myDecompFile, line)) {
        string outputLine;
        for (size_t i = 0; i < line.size(); ++i) {
            string currentChar(1, line[i]);
            if (decompMap.find(currentChar) != decompMap.end()) {
                outputLine += decompMap[currentChar];
            }
            else {
                outputLine += currentChar;
            }
        }
        decompressedFile << outputLine << '\n';
    }

    // Close the files
    myDecompFile.close();
    decompressedFile.close();
}

// int main() {
//     string compressedFile = "output_file.comp";
//     string mappingFile = "mapping.txt";
//     string decompressed = "decompressed.xml";
//     XmlParser::decompress(compressedFile, mappingFile,decompressed);
//     return 0;
// }
