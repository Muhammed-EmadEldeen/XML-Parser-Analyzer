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
    Tag() {}
    Tag(const string& tagName, int lineNumber) : name(tagName), line(lineNumber) {}

};


struct Error {

    string tagName;
    int tagLine;

    string errType;

    string toString() const{
        return "Line: " + to_string(tagLine) + " : Tag : "+ tagName + " : " + errType ;
    }
    /*

                * errType *

   "Closing tag has no matching opening tag." at the end of the code

   "Opening tag has no matching closing tag." at the start of the code

   "Opening tag unclosed properly."

   "Closed tag unopened properly."


   */
};


struct tree_node {
    string title;
    string content = "";
    vector<tree_node> children;
};


// Helper function to check if a tag is a closing tag
bool isClosingTag(const string& tag);

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string& tag);



