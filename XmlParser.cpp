

#include <stack>
#include <string>
#include <vector>



#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <cctype>
#include "Tags_utilities.h"

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std ;
inline unordered_map<string, string> mapping;



class XmlParser {
public:
  ~XmlParser();

  static vector<string> XML_error_detection();
  static vector<string> correctXml(const vector<string>& xmlLines) ;
  static string byte_pair_compress(const string &input);
  static stack<pair<string, int>>
  readXmlTagsWithLineNumbers(const string &filename); ////////////////////////
  static void decompress();
  static void format();              //////////////////////////
  static void json();
  static void mini();
  static void prettifyXML(const string &inputFileName,
                          const string &outputFileName);
  static void minifyXML(const string &inputFileName,
                        const string &outputFileName);


};

inline void XmlParser::prettifyXML(const string& inputFileName,const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFileName << std::endl;
        return;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file: " << outputFileName << std::endl;
        return;
    }

    string line,xmlContent;
    vector<string> xmlContentSec; // Vector to hold all lines from the input file
    while (getline(inputFile, line)) {
        xmlContentSec.push_back(line);
    }
    inputFile.close();

    // Variables to hold the prettified XML content, tags, and normal text
    string normal;
    string tag;

    stack<int> in;  // Stack to manage indentation levels for nested tags
    bool insideTag = false; // Flag to check if the current character is within a tag
    int indentationLevel = 0;  // Keeps track of the current indentation level
    int f = 0;  // Flag to manage single line tags


    for (const auto& l : xmlContentSec) {//minify the input first to remove already indentations
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
                    outputFile << string((indentationLevel + 1) * 4, ' ') << normal << endl;
                    in.push(indentationLevel);  // Push current indentation level onto the stack
                } else {
                    outputFile << string(indentationLevel * 4, ' ') << tag;
                    outputFile << normal;
                    in.push(indentationLevel);
                    f = 1;
                }
                normal.clear();  // Clear normal text buffer
                tag.clear();  // Clear tag buffer
            } else if (!tag.empty() && !insideTag) {
                // Handle tag closing
                if (tag[1] != '/') {
                    in.push(indentationLevel);
                    outputFile << string(indentationLevel * 4, ' ') << tag << endl;
                    indentationLevel++;  // Increase indentation for nested tags
                    tag.clear();
                } else {
                    indentationLevel = in.top();  // Pop the last indentation level
                    in.pop();
                    if (f == 0) {
                        outputFile << string(indentationLevel * 4, ' ') << tag << endl;
                    } else {
                        outputFile << tag << endl;
                        f = 0;  // Reset flag for single line tags
                    }
                    tag.clear();
                }
            }
            insideTag = true;  // Mark that we are inside a tag
        }

        if (insideTag) {
            tag += ch;  // Append character to tag if inside a tag
        } else {
            normal += ch;  // Append character to normal text if outside a tag
        }

        // Detect closing of a tag
        if (ch == '>') {
            insideTag = false;  // Mark that we are no longer inside a tag
            if (i == size - 1) {  // Handle the last tag in the XML content
                outputFile << tag;
                in.pop();
            }
        }
    }
}

inline void XmlParser::minifyXML(const string& inputFileName, const string& outputFileName) {
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




// Read file and return string
inline string read_file(const string &file_path) {
    ifstream file(file_path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Write string content to file
inline void write_file(const string &file_path, const string &content) {
    ofstream file(file_path);
    file << content;
}

// Keep track of the frequency of each pair
struct PairFrequency {
    string pair;
    int frequency;
    bool operator<(const PairFrequency &rhs) const {
        return frequency < rhs.frequency;
    }
};

inline unordered_map<string, int> count_byte_pairs(const string &input) {

    // initialize a map to store the frequency of each pair
     unordered_map<string, int> pair_count;

    // iterate through the input string
    for (size_t i = 0; i < input.length() - 1; ++i) {

        // check if the pair is already in the mapping "very important" to avoid
        // infinite loop
        if (mapping.find(input.substr(i, 1)) != mapping.end() ||
            mapping.find(input.substr(i + 1, 1)) != mapping.end()) {
            continue; // skip if already in the mapping
        }

        // get the pair of bytes
        string pair = input.substr(i, 2);

        // increment the frequency of the pair
        pair_count[pair]++;
    }
    return pair_count;
}

inline string replace_byte_pair(string &input, const string &pair,
                         const string &placeholder) {
    size_t pos = 0; // start from the beginning

    // replace all occurrences of the pair with the placeholder
    while ((pos = input.find(pair, pos)) != string::npos) {
        input.replace(pos, pair.length(), placeholder);
        pos += placeholder.length();
    }
    return input;
}

inline string XmlParser::byte_pair_compress(const string &input) {
    string compressed = input;
    // dynamic placeholders generation
    vector<string> placeholders;
    for (char c = 33; c <= 126; ++c) {
        placeholders.push_back(string(1, c));
    }

    while (!placeholders.empty()) {
        auto pair_count = count_byte_pairs(compressed);
        if (pair_count.empty())
            break;

        // priority queue to keep track of most repeated pair
        priority_queue<PairFrequency> pq;
        for (const auto &pair : pair_count) {
            pq.push({pair.first, pair.second});
        }

        // get the most frequent pair
        auto most_frequent_pair = pq.top().pair;
        int max_frequency = pq.top().frequency;
        if (max_frequency < 2)
            break; // exit if all pairs are unique

        // get next placeholder
        string placeholder = placeholders.back();
        placeholders.pop_back();

        // store the pair in the mapping
        mapping[placeholder] = most_frequent_pair;

        // replace the most repeated pair with placeholders
        compressed = replace_byte_pair(compressed, most_frequent_pair, placeholder);
    }
    return compressed;
}







