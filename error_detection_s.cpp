#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "Tags_utilities.h"
using namespace std;

//temporary function to just simulate
stack<Tag> readxml() {
    stack<Tag> file;
    return file;
}

// Function to detect XML errors
vector<string> XML_error_detection() {
    stack<Tag> tags = readxml(); // Input stack with line numbers
    stack<Tag> reversedTags;     // To reverse the input stack
    vector<string> errors;       // To store error messages
    stack<Tag> openTagsStack;    // To track unmatched opening tags

    // Reverse the stack
    while (!tags.empty()) {
        reversedTags.push(tags.top());
        tags.pop();
    }

    // Process reversed tags
    while (!reversedTags.empty()) {
        Tag currentTag = reversedTags.top(); // Get the struct (tag, line)
        string tag = currentTag.name;         // Extract the tag
        int line = currentTag.line;           // Extract the line number
        reversedTags.pop();

        if (!isClosingTag(tag)) {
            // Opening tag, push onto stack
            openTagsStack.push(currentTag);
        }
        else {
            // Closing tag
            if (openTagsStack.empty()) {
                // No matching opening tag
                errors.push_back("Error: Closing tag " + tag + " on line " + to_string(line) + " has no matching opening tag.");
            }
            else {
                // Check if closing tag matches the most recent opening tag
                Tag topTag = openTagsStack.top();   // Get the top opening tag
                string topTagStr = topTag.name;     // Extract the opening tag
                int topLine = topTag.line;          // Extract the line number for opening tag

                if (getTagName(topTagStr) == getTagName(tag)) {
                    openTagsStack.pop(); // Matched
                }
                else {
                    // Mismatch
                    errors.push_back("Error: the opening tag " + topTagStr + " on line " + to_string(topLine) + " unclosed properly.");
                    openTagsStack.pop(); // Remove incorrect opening tag
                }
            }
        }
    }

    return errors;
}

