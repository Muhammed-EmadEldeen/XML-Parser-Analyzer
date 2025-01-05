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
    Tag() : name(""), line(0) {}
    Tag(const string &tagName, int lineNumber)
        : name(tagName), line(lineNumber) {}
};

enum ErrorType { UnClosed, UnOpened };
inline string errorTypeToString(ErrorType type) {
    switch (type) {
    case UnClosed: return "UnClosed";
    case UnOpened: return "UnOpened";
    default: return "Unknown";
    }
}

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



    string toString() const {
        return "Line: " + to_string(tagLine) + " : Tag : " + tagName + " : " + errorTypeToString(errType);
    }
};
/*struct Error {
    string tagName;
    int tagLine;
    ErrorType errType;
    Error() : tagName(""), tagLine(0), errType(UnClosed) {}

    Error(string t, int l, ErrorType e) {
        tagName = t;
        tagLine = l;
        errType = e;
    }
};*/


struct tree_node {
    string title;
    string content = "";
    vector<tree_node> children;
};


// Helper function to check if a tag is a closing tag
bool isClosingTag(const string& tag);

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string& tag);



