#include <stack>
#include <string>
#include <vector>
#include "XmlParser.h"

using namespace std;

class XmlParser {
public:
  ~XmlParser();

  static vector<Error> XML_error_detection();
  static string byte_pair_compress(const string &input);
  static stack<pair<string, int>>
  readXmlTagsWithLineNumbers(const string &filename);
  static void decompress();
  static void format();
  static void json();
  static void mini();
  static void prettifyXML(const string &inputFileName,
                          const string &outputFileName);
  static void minifyXML(const string &inputFileName,
                        const string &outputFileName);
};


