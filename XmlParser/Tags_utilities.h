#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Helper function to check if a tag is a closing tag
bool isClosingTag(const string &tag);

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string &tag);
