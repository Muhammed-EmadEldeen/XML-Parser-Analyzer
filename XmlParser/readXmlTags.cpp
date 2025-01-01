#include "XmlParser.h"
#include <fstream>
#include <regex>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

stack<Tag> XmlParser::readXmlTagsWithLineNumbers(const string &filename) {
  stack<Tag> resultStack;
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
  return resultStack;
}
