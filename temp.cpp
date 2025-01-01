#include "XmlAnalyzer/UsersData.h"
#include "XmlParser/XmlParser.h"

vector<Error> XmlParser::XML_error_detection() { return vector<Error>(); }
User UsersData::getMostFollowingUser() { return User("hi"); }
User UsersData::getMostFollowedUser() { return User("hi"); }
stack<pair<string, int>>
XmlParser::readXmlTagsWithLineNumbers(const string &filename) {
  stack<pair<string, int>> tags;
  return tags;
}
void XmlParser::decompress() {};
