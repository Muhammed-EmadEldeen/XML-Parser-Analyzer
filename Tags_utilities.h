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

enum ErrorType{UnClosed,UnOpened};


struct Error {

    string tagName;
    int tagLine;
    ErrorType errType;
    //string errType;
    /*
                * errType *
   "Closing tag has no matching opening tag." at the end of the code
   "Opening tag has no matching closing tag." at the start of the code
   "Opening tag unclosed properly."
   "Closed tag unopened properly."
   */
};


// Helper function to check if a tag is a closing tag
bool isClosingTag(const string& tag);

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string& tag);
