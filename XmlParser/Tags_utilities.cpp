#include "Tags_utilities.h"
#include <string>
using namespace std;

// Helper function to check if a tag is a closing tag
bool isClosingTag(const string &tag) { return tag[0] == '/'; }

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string &tag) {
  if (isClosingTag(tag)) {
    return tag.substr(2, tag.size() - 3); // Remove </ and >
  }
  return tag.substr(1, tag.size() - 2); // Remove < and >
}
