#ifndef XMLPARSER
#define XMLPARSER
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum ErrorType { UnClosed, UnOpened };

struct Error {
  string tag;
  int line;
  ErrorType error;

  Error(string t, int l, ErrorType e) {
    tag = t;
    line = l;
    error = e;
  }
};

struct Tag {
  string name;
  int line; // Line number of the tage
  Tag(const string &tagName, int lineNumber)
      : name(tagName), line(lineNumber) {}
};

class XmlParser {
public:
  ~XmlParser();

  static vector<Error> XML_error_detection();
  static string byte_pair_compress(const string &input);
  static stack<Tag> readXmlTagsWithLineNumbers(const string &filename);
  static void decompress();
  static void json(string filename);
  static void prettifyXML(const string &inputFileName,
                          const string &outputFileName);
  static void minifyXML(const string &inputFileName,
                        const string &outputFileName);
  static void correct(string fileName, string outputFile);
};
#endif
