#include <iostream>
#include <vector>
#include <stack>
#include <regex>
#include <string>
#include <fstream>
#include "help_func.cpp"
using namespace std;

vector<string> correctXml(const vector<string>& xmlLines) {
    vector<string> correctedXml;
    stack<string> tagStack;
    stack<string> ctagStack;
    regex openingTagPattern(R"(<([a-zA-Z0-9_:]+)[^>/]*>)");
    regex selfClosingTagPattern(R"(<([a-zA-Z0-9_:]+)[^>]*\/>)");
    regex closingTagPattern(R"(</([a-zA-Z0-9_:]+)>)");
    regex commentTagPattern(R"(<!--.*?-->)");

    for (size_t i = 0; i < xmlLines.size(); ++i) {
    const auto& line = xmlLines[i];
    smatch match;

    // Handle comment tags (e.g., <!-- This is a comment -->)
        if (regex_search(line, match, commentTagPattern)) {
            correctedXml.push_back(line);
            continue;
        }

    // Handle self-closing tags (e.g., <tag/>)
    if (regex_search(line, match, selfClosingTagPattern)) {
        correctedXml.push_back(line);
        continue;
    }

    // Handle opening tags (e.g., <tag>)
    if (regex_search(line, match, openingTagPattern)) {
        if((!ctagStack.empty() && !tagStack.empty()) && ctagStack.top() == tagStack.top())
        {
            correctedXml.push_back("</" + ctagStack.top() + ">");
            while(!ctagStack.empty()) {ctagStack.pop();};
            tagStack.pop();
        }
        string tag = match[1].str();
        tagStack.push(tag);
        correctedXml.push_back(line);
        continue;
    }

    // Handle closing tags (e.g., </tag>)
    if (regex_search(line, match, closingTagPattern)) {
        string tag = match[1].str();
        if (!tagStack.empty() && tagStack.top() == tag) {
            // Correctly matched closing tag, pop the stack
            tagStack.pop();
            correctedXml.push_back(line);
        } else if (!tagStack.empty() && tagStack.top() != tag) {
            // Mismatched closing tag: correct it by inserting the right one
            ctagStack.push(tag);
            correctedXml.push_back("</" + tagStack.top() + ">");
            tagStack.pop();
        }
        
        continue;
    }
    if ((i - 1) < xmlLines.size() && std::regex_search(xmlLines[i - 1], match, closingTagPattern))
    {
        if(!tagStack.empty())
        {
            regex_search(xmlLines[i + 1], match, closingTagPattern);
            string x = match[1].str();
            correctedXml.push_back( "<" + x + ">" );
            tagStack.push(x);
        }
    }

    // Handle content lines (text between tags)
    correctedXml.push_back(line);

    // Check if the next line is an opening tag
    if ((i + 1) < xmlLines.size() && std::regex_search(xmlLines[i + 1], match, openingTagPattern))
    {
        if(!tagStack.empty())
        {
            correctedXml.push_back( "</" + tagStack.top() + ">" );
            tagStack.pop();
        }
        
    }
    
}


    // Add closing tags for unmatched opening tags in the stack
        while (!tagStack.empty()) {
            correctedXml.push_back("</" + tagStack.top() + ">");
            tagStack.pop();
        }

    return correctedXml;
}

int main() {
    string firstFile = "input.xml";
    string inputFilename = "separated.xml";
    string outputFilename = "output.xml";

    parseXMLToString(firstFile, inputFilename);

    vector<string> xmlLines = readXmlFile(inputFilename);
    vector<string> correctedXml = correctXml(xmlLines);
    writeXmlFile(outputFilename, correctedXml);

    cout << "XML correction completed. Check the output file: " << outputFilename << std::endl;

    return 0;
}