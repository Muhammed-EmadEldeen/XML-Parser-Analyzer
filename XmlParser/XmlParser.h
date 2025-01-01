#ifndef XMLPARSER
#define XMLPARSER
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum ErrorType { UnClosed, UnOpened };

struct Error {
  string tagName;
  int tagLine;
  ErrorType errType;
  Error() : tagName(""), tagLine(0), errType(UnClosed) {}

  Error(string t, int l, ErrorType e) {
    tagName = t;
    tagLine = l;
    errType = e;
  }
};

struct Tag {
  string name;
  int line; // Line number of the tage
  Tag() : name(""), line(0) {}
  Tag(const string &tagName, int lineNumber)
      : name(tagName), line(lineNumber) {}
};

class XmlParser {
public:
  ~XmlParser();
  static void byte_pair_compress(const string &inputfile,
                                 const string &outputfile);
  static vector<Error> XML_error_detection(const string &filename);
  static stack<Tag> readXmlTagsWithLineNumbers(const string &filename);
  static void decompress(const string &compressedFile,
                         const string &mappingFile, const string &outputFile);
  static void json(string input_file, string output_file);
  static void prettifyXML(const string &inputFileName,
                          const string &outputFileName);
  static void minifyXML(const string &inputFileName,
                        const string &outputFileName);
  static void correct(string fileName, string outputFile);
};

#endif
