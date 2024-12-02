#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Define a struct to store a tag and its line number
struct Tag {
    string name;
    int line;
};


// Helper function to check if a tag is a closing tag
bool isClosingTag(const string& tag);

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string& tag);