#pragma once


#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

struct tree_node {
    string title;
    string content = "";
    vector<tree_node> children;
};

vector<string> split(string str, char splitter);
tree_node parse_xml(string xml);
string transform_to_json(tree_node node);