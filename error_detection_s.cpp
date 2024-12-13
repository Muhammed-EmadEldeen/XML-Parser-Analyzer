#include <iostream>
#include <stack>
#include <string>
#include <vector>


#include "Tags_utilities.h"
#include "XmlParser.cpp"

using namespace std;




// *******Function to simulate reading an XML file as a stack of tags with line numbers****************



stack<Tag> readxml() {
    stack<Tag> file;

    return file;
}


// Function to detect XML errors
vector<Error> XmlParser::XML_error_detection() {
    stack<Tag> tags = readxml(); // Input stack with line numbers
    stack<Tag> reversedTags;     // To reverse the input stack
    vector<Error> errors;       // To store error messages
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
        reversedTags.pop();//////////////////////////////////////////////////////////////////////

        if (!isClosingTag(tag)) {
            // Opening tag, push onto stack
            openTagsStack.push(currentTag);
        }



        else {
            // Closing tag

            Tag topTag = openTagsStack.top();   // Get the top opening tag
            string topTagStr = topTag.name;     // Extract the opening tag
            int topLine = topTag.line;          // Extract the line number for opening tag

            if (openTagsStack.empty()) {
                // No matching opening tag
                Error currentError;
                currentError.tagName = tag;
                currentError.tagLine = line;
                currentError.errType = "Closing tag has no matching opening tag.";
                errors.push_back(currentError);

                //errors.push_back("Error: Closing tag " + tag + " on line " + to_string(line) + " has no matching opening tag.");
            }
            else {
                // Check if closing tag matches the most recent opening tag


                if (getTagName(topTagStr) == getTagName(tag)) {
                    openTagsStack.pop(); // Matched
                }
                else { //errrrrrrrrrrrrrrrrrr

                    // Mismatch

                    Error currentError;
                    currentError.tagName = topTagStr;
                    currentError.tagLine = topLine;
                    currentError.errType = "Opening tag unclosed properly.";
                    errors.push_back(currentError);
                    //errors.push_back("Error: the opening tag " + topTagStr + " on line " + to_string(topLine) + " unclosed properly.");
                    openTagsStack.pop(); // Remove incorrect opening tag

                    // try
                    //stack<Tag> checkTag;
                    Tag tempTag;

                    for (int i = 0; i < 2; i++) {
                        if (getTagName(openTagsStack.top().name) != getTagName(tag)) {
                            if (i == 0) {
                                tempTag = openTagsStack.top();
                                openTagsStack.pop(); // not Matched
                            }
                            if (i == 1) {
                                Error currentError;
                                currentError.tagName = tag;
                                currentError.tagLine = line;
                                currentError.errType = "Closed tag unopened properly." ;
                                errors.push_back(currentError);
                                //errors.push_back("Error: the closed tag " + tag + " on line " + to_string(line) + " unopened properly.");
                                openTagsStack.push(tempTag);
                            }
                        }
                        else {
                            if (i == 0) {
                                openTagsStack.pop(); //handle this matching
                                break;
                            }

                            if (i == 1) {
                                openTagsStack.pop(); //handle this matching 
                                openTagsStack.push(tempTag); //re-push the not matched opening tag again
                            }
                        }

                    }

                }

            }
        }
    }


    ////////////////////////////////////////////////////
         //Check for unmatched opening tags
    while (!openTagsStack.empty()) {
        auto topTag = openTagsStack.top();
        string topTagStr = topTag.name;
        int topLine = topTag.line;
        
        Error currentError;
        currentError.tagName = topTagStr;
        currentError.tagLine = topLine;
        currentError.errType = "Opening tag has no matching closing tag.";
        errors.push_back(currentError);
        //errors.push_back("Error: Opening tag " + topTagStr + " on line " + to_string(topLine) + " has no matching closing tag.");
        openTagsStack.pop();
    }
    ///////////////////////////////////////////////////

    return errors;
}
