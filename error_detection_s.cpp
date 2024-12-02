#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;



// Function to simulate reading an XML file as a stack of tags
stack<string> readxml() {

}

// Helper function to check if a tag is a closing tag
bool isClosingTag(const string& tag) {
    return tag[1] == '/';
}

// Helper function to extract the name of a tag (without angle brackets)
string getTagName(const string& tag) {
    if (isClosingTag(tag)) {
        return tag.substr(2, tag.size() - 3); // Remove </ and >
    }
    return tag.substr(1, tag.size() - 2); // Remove < and >
}

// Function to detect XML errors
vector<string> XML_error_detection() {
    stack<string> tags = readxml(); // Input stack
    stack<string> reversedTags;     // To reverse the input stack
    vector<string> errors;          // To store error messages
    stack<string> openTagsStack;    // To track unmatched opening tags

    // Reverse the stack
    while (!tags.empty()) {
        reversedTags.push(tags.top());
        tags.pop();
    }

    // Process reversed tags
    while (!reversedTags.empty()) {
        string tag = reversedTags.top();
        reversedTags.pop();

        if (!isClosingTag(tag)) {
            // Opening tag, push onto stack
            openTagsStack.push(tag);
        }
        else {
            // Closing tag
            if (openTagsStack.empty()) {
                // No matching opening tag
                errors.push_back("Error: Closing tag " + tag + " found without a matching opening tag.");
            }
            else {
                // Check if closing tag matches the most recent opening tag
                string topTag = openTagsStack.top();
                if (getTagName(topTag) == getTagName(tag)) {
                    openTagsStack.pop(); // Matched
                }
                else {

                    errors.push_back("Error: the openning tag : " + topTag + " hasn't closed .");
                    openTagsStack.pop(); // Remove incorrect opening tag
                }
            }
        }
    }

    return errors;
}

