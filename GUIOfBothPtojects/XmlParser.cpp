

/********  This file contains all the team functions for liniking simplicity
 * with the gui *////////
/********  This file contains all the team functions for liniking simplicity
 * with the gui *////////
/********  This file contains all the team functions for liniking simplicity
 * with the gui *////////
/********  This file contains all the team functions for liniking simplicity
 * with the gui *////////
/********  This file contains all the team functions for liniking simplicity
 * with the gui *////////

#include <stack>
#include <string>
#include <vector>

#include "Tags_utilities.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

#include <iostream>
#include <queue>
#include <regex>
#include <unordered_map>
#include <unordered_set>

#include <stdexcept>

#include <unordered_map>

using namespace std;
inline unordered_map<string, string> mapping;

class XmlParser {
public:
  ~XmlParser();

  static string byte_pair_compress(const string &input);
  static stack<Tag> readXmlTagsWithLineNumbers(const string &filename);
  static void decompress();
  static void format(); //////////////////////////
  static void mini();
  static void prettifyXML(const string &inputFileName,
                          const string &outputFileName);
  static void minifyXML(const string &inputFileName,
                        const string &outputFileName);

  static vector<string> correctXml(const vector<string> &xmlLines);
  static void parseXMLToString(const string &inputFilePath,
                               const string &outputFilePath);
  static vector<string> readXmlFile(const string &filename);
  static void writeXmlFile(const string &filename,
                           const vector<string> &xmlLines);

  /////////detect

  static vector<Error> XML_error_detection(const string &filename);

  /////////json

  static void json(string input_file, string output_file);

  /////////decompress
  static void decompress(const string &compressedFile,
                         const string &mappingFile, const string &outputFile);
};

inline void XmlParser::prettifyXML(const string &inputFileName,
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
////////////////////////////////////////////////////////////////////////////////////////////////////Minify
inline void XmlParser::minifyXML(const string &inputFileName,
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

//////////////////////////////////////////////////////////////////////////////////////////////////////Compress

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////Read
///Tags

////////////////////////////////////////////////////////////////////////////////////////////////////////////DETECT
///ERROR

// Define a struct to store a tag and its line number

// Helper function to check if a tag is a closing tag
inline bool isClosingTag(const string &tag) { return tag[0] == '/'; }

// Helper function to extract the name of a tag (without angle brackets)
inline string getTagName(const string &tag) {
  if (isClosingTag(tag)) {
    return tag.substr(1, tag.size() - 2);
  }
  return tag.substr(0, tag.size() - 1);
}

// *******Function to simulate reading an XML file as a stack of tags with line
// numbers****************

inline stack<Tag>
XmlParser::readXmlTagsWithLineNumbers(const string &filename) {
  stack<Tag> resultStack;
  /* cout << "Reading file: " << filename << endl; */
  ifstream file(filename);

  if (!file.is_open()) {
    throw runtime_error("Failed to open file: " + filename);
  }

  string line;
  int lineNumber = 0;
  regex tagRegex("<([a-zA-Z0-9:_-]+)(\\s[^>]*)?>|</"
                 "([a-zA-Z0-9:_-]+)>|<!\\[CDATA\\[(.*?)\\]\\]>|<!--(.*?)-->");
  smatch match;

  while (getline(file, line)) {
    lineNumber++;

    string::const_iterator searchStart(line.cbegin());
    while (regex_search(searchStart, line.cend(), match, tagRegex)) {
      if (match[1].matched) { // Opening tag
        resultStack.emplace(match[1].str(), lineNumber);
      } else if (match[3].matched) { // Closing tag
        resultStack.emplace("/" + match[3].str(), lineNumber);
      } else if (match[4].matched) { // CDATA content
        resultStack.emplace("CDATA: " + match[4].str(), lineNumber);
      } else if (match[5].matched) { // Comment
        resultStack.emplace("Comment: " + match[5].str(), lineNumber);
      }
      searchStart = match.suffix().first;
    }
  }

  file.close();
  /* while (resultStack.size() > 1) { */
  /*   cout << resultStack.top().name << resultStack.top().line << endl; */
  /*   resultStack.pop(); */
  /* } */
  return resultStack;
}

// Function to detect XML errors
inline vector<Error> XmlParser::XML_error_detection(const string &filename) {
  stack<Tag> tags =
      readXmlTagsWithLineNumbers(filename); // Input stack with line numbers
  stack<Tag> reversedTags;                  // To reverse the input stack
  vector<Error> errors;                     // To store error messages
  stack<Tag> openTagsStack;                 // To track unmatched opening tags

  // Reverse the stack
  while (!tags.empty()) {
    reversedTags.push(tags.top());
    tags.pop();
  }

  // Process reversed tags
  while (!reversedTags.empty()) {
    Tag currentTag = reversedTags.top(); // Get the struct (tag, line)
    string tag = currentTag.name;        // Extract the tag
    int line = currentTag.line;          // Extract the line number
    reversedTags
        .pop(); //////////////////////////////////////////////////////////////////////

    if (!isClosingTag(tag)) {
      // Opening tag, push onto stack
      openTagsStack.push(currentTag);
    }

    else {
      // Closing tag

      Tag topTag = openTagsStack.top(); // Get the top opening tag
      string topTagStr = topTag.name;   // Extract the opening tag
      int topLine = topTag.line; // Extract the line number for opening tag

      if (openTagsStack.empty()) {
        // No matching opening tag
        Error currentError;
        currentError.tagName = tag;
        currentError.tagLine = line;
        currentError.errType = UnOpened; //
                                         //
        cout << "There is an error in line: " << topLine
             << " of type unopedned tag." << endl;
        // currentError.errType = "Closing tag has no matching opening tag.";
        errors.push_back(currentError);

        // errors.push_back("Error: Closing tag " + tag + " on line " +
        // to_string(line) + " has no matching opening tag.");
      } else {
        // Check if closing tag matches the most recent opening tag

        if (getTagName(topTagStr) == getTagName(tag)) {
          openTagsStack.pop(); // Matched
        } else {               // errrrrrrrrrrrrrrrrrr

          // Mismatch

          Error currentError;
          currentError.tagName = topTagStr;
          currentError.tagLine = topLine;
          currentError.errType = UnClosed; //
          // currentError.errType = "Opening tag unclosed properly.";

          cout << "There is an error in line: " << topLine
               << " of type unclosed tag." << endl;
          errors.push_back(currentError);
          // errors.push_back("Error: the opening tag " + topTagStr + " on line
          // " + to_string(topLine) + " unclosed properly.");
          openTagsStack.pop(); // Remove incorrect opening tag

          // try
          // stack<Tag> checkTag;
          Tag tempTag;

          for (int i = 0; i < 2; i++) {
            if (getTagName(openTagsStack.top().name) != getTagName(tag)) {
              if (i == 0) {
                tempTag = openTagsStack.top();
                openTagsStack.pop(); // not Matched
              }
              if (i == 1) {
                Error currentError;
                currentError.tagName = tag;
                currentError.tagLine = line;
                currentError.errType = UnOpened; //
                // currentError.errType = "Closed tag unopened properly." ;
                //
                cout << "There is an error in line: " << topLine
                     << " of type unclosed tag." << endl;

                errors.push_back(currentError);
                // errors.push_back("Error: the closed tag " + tag + " on line "
                // + to_string(line) + " unopened properly.");
                openTagsStack.push(tempTag);
              }
            } else {
              if (i == 0) {
                openTagsStack.pop(); // handle this matching
                break;
              }

              if (i == 1) {
                openTagsStack.pop(); // handle this matching
                openTagsStack.push(
                    tempTag); // re-push the not matched opening tag again
              }
            }
          }
        }
      }
    }
  }

  ////////////////////////////////////////////////////
  // Check for unmatched opening tags
  while (!openTagsStack.empty()) {
    auto topTag = openTagsStack.top();
    string topTagStr = topTag.name;
    int topLine = topTag.line;

    Error currentError;
    currentError.tagName = topTagStr;
    currentError.tagLine = topLine;
    currentError.errType = UnClosed; //
    cout << "There is an error in line: " << topLine << " of type unclosed tag."
         << endl;
    // currentError.errType = "Opening tag has no matching closing tag.";

    errors.push_back(currentError);
    // errors.push_back("Error: Opening tag " + topTagStr + " on line " +
    // to_string(topLine) + " has no matching closing tag.");
    openTagsStack.pop();
  }
  ///////////////////////////////////////////////////

  return errors;
}

////////////////////////////////////////////////////////////////////////////////////////////CORRECT
///ERROR
///
///
///
///
///
inline void parseXMLToString(const string &inputFilePath,
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

inline vector<string> readXmlFile(const string &filename) {
  vector<string> xmlLines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    xmlLines.push_back(line);
  }
  return xmlLines;
}

inline void writeXmlFile(const string &filename,
                         const vector<string> &xmlLines) {
  ofstream file(filename);
  for (const auto &line : xmlLines) {
    file << line << endl;
  }
}

inline vector<string> correctXml(const vector<string> &xmlLines) {
  vector<string> correctedXml;
  stack<string> tagStack;
  stack<string> ctagStack;
  regex openingTagPattern(R"(<([a-zA-Z0-9_:]+)[^>/]*>)");
  regex selfClosingTagPattern(R"(<([a-zA-Z0-9_:]+)[^>]*\/>)");
  regex closingTagPattern(R"(</([a-zA-Z0-9_:]+)>)");
  regex commentTagPattern(R"(<!--.*?-->)");

  for (size_t i = 0; i < xmlLines.size(); ++i) {
    const auto &line = xmlLines[i];
    smatch match;

    // Handle comment tags (e.g., <!-- This is a comment -->)
    if (regex_search(line, match, commentTagPattern)) {
      correctedXml.push_back(line);
      continue;
    }

    // Handle self-closing tags (e.g., <tag/>)
    if (regex_search(line, match, selfClosingTagPattern)) {
      correctedXml.push_back(line);
      continue;
    }

    // Handle opening tags (e.g., <tag>)
    if (regex_search(line, match, openingTagPattern)) {
      if ((!ctagStack.empty() && !tagStack.empty()) &&
          ctagStack.top() == tagStack.top()) {
        correctedXml.push_back("</" + ctagStack.top() + ">");
        while (!ctagStack.empty()) {
          ctagStack.pop();
        };
        tagStack.pop();
      }
      string tag = match[1].str();
      tagStack.push(tag);
      correctedXml.push_back(line);
      continue;
    }

    // Handle closing tags (e.g., </tag>)
    if (regex_search(line, match, closingTagPattern)) {
      string tag = match[1].str();
      if (!tagStack.empty() && tagStack.top() == tag) {
        // Correctly matched closing tag, pop the stack
        tagStack.pop();
        correctedXml.push_back(line);
      } else if (!tagStack.empty() && tagStack.top() != tag) {
        // Mismatched closing tag: correct it by inserting the right one
        ctagStack.push(tag);
        correctedXml.push_back("</" + tagStack.top() + ">");
        tagStack.pop();
      }

      continue;
    }
    if ((i - 1) < xmlLines.size() &&
        std::regex_search(xmlLines[i - 1], match, closingTagPattern)) {
      if (!tagStack.empty()) {
        regex_search(xmlLines[i + 1], match, closingTagPattern);
        string x = match[1].str();
        correctedXml.push_back("<" + x + ">");
        tagStack.push(x);
      }
    }

    // Handle content lines (text between tags)
    correctedXml.push_back(line);

    // Check if the next line is an opening tag
    if ((i + 1) < xmlLines.size() &&
        std::regex_search(xmlLines[i + 1], match, openingTagPattern)) {
      if (!tagStack.empty()) {
        correctedXml.push_back("</" + tagStack.top() + ">");
        tagStack.pop();
      }
    }
  }

  // Add closing tags for unmatched opening tags in the stack
  while (!tagStack.empty()) {
    correctedXml.push_back("</" + tagStack.top() + ">");
    tagStack.pop();
  }

  return correctedXml;
}

/////////////////////////////////////////////////////////////////////////////////////JSON
///
///
///

inline vector<string> split(string str, char splitter) {
  vector<string> result;
  int str_size = str.size();
  string parser = "";
  for (int i = 0; i < str_size; i++) {
    if (str[i] == splitter) {
      result.push_back(parser);
      parser = "";
      continue;
    }
    parser += str[i];
  }

  result.push_back(parser);

  return result;
}

inline tree_node parse_xml(string xml) {
  int i = 0;
  int xml_size = xml.size();

  while (true) {
    if (xml[i] == '<')
      break;
    i++;
  }

  string element = "";

  while (true) {
    i++;
    if (xml[i] == '>')
      break;
    element += xml[i];
  }

  // extract xml content till the end
  string xml_inside = "";
  i++;
  string element_end = "</" + element + ">";
  int end_size = element_end.size();

  for (; i < xml_size; i++) {
    if (xml.substr(i, end_size) == element_end)
      break;
    xml_inside += xml[i];
  }

  tree_node node;
  node.title = element;

  if (xml_inside[0] != '<') {
    node.content = xml_inside;
    return node;
  }

  // take the string divide into tree nodes

  int xml_inside_size = xml_inside.size();
  bool element_parse_start = false;
  bool element_parse_end = false;
  vector<string> elements;
  string element_inside = "";
  string element_inside_end = "";
  string parser = "";

  for (int k = 0; k < xml_inside_size; k++) {
    parser += xml_inside[k];

    if (xml_inside[k] == '<' && !element_parse_start) {
      element_parse_start = true;
      element_inside = "";
      continue;
    }

    if (xml_inside[k] == '>' && element_parse_start) {
      element_parse_end = true;
      continue;
    }

    if (element_parse_start && !element_parse_end) {
      element_inside += xml_inside[k];
    }

    if (element_parse_start && element_parse_end) {
      string element_end = "</" + element_inside + ">";
      int element_end_size = element_end.size();
      // cout<<parser;
      if (xml_inside.substr(k, element_end_size) == element_end) {
        parser += xml_inside.substr(k + 1, element_end_size - 1);
        k += element_end_size - 1;
        elements.push_back(parser);
        parser = "";
        element_parse_start = false;
        element_parse_end = false;
        element_inside = "";
      }
    }
  }

  int elements_size = elements.size();

  for (int l = 0; l < elements_size; l++) {
    node.children.push_back(parse_xml(elements[l]));
  }

  return node;
}

inline string transform_to_json(tree_node node) {
  // check for children
  // if no children retutn {title : content}
  // if one child return {title : transform}
  // if more than one child return title : [ transform for each child]
  int children_size = node.children.size();
  if (children_size == 0 && node.content != "") {
    return "{\"" + node.title + "\": \"" + node.content + "\"}";
  }
  if (children_size == 1) {
    return "{\"" + node.title + "\": " + transform_to_json(node.children[0]) +
           "}";
  }

  if (children_size > 1) {
    string result = "{\"" + node.title + "\": [";
    for (int i = 0; i < children_size; i++) {
      result += transform_to_json(node.children[i]);
      if (i != children_size - 1) {
        result += ",";
      }
    }
    result += "]}";

    return result;
  }

  return "{}";
}

inline void XmlParser::json(string input_file, string output_file) {

  string text, line;

  ifstream file(input_file);

  if (file.is_open()) {
    while (getline(file, line)) {
      text += line + "\n";
    }
    file.close();
  } else {
    cerr << "Unable to open file: " << input_file << endl;
  }

  tree_node root = parse_xml(text);
  string json = transform_to_json(root);

  ofstream json_file(output_file);

  if (json_file.is_open()) {
    json_file << json;
    json_file.close();
  }
  // cout<<"{" + json + "}";
}

/////////////////////////////////////////////////////////////////Decompress
///
///

inline void XmlParser::decompress(const string &compressedFile,
                                  const string &mappingFile,
                                  const string &outputFile) {
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
      } else {
        outputLine += currentChar;
      }
    }
    decompressedFile << outputLine << '\n';
  }

  // Close the files
  myDecompFile.close();
  decompressedFile.close();
}
