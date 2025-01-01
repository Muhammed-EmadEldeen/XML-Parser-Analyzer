#include "XmlParser.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tree_node {
  string title;
  string content = "";
  vector<tree_node> children;
};
vector<string> split(string str, char splitter) {
  vector<string> result;
  int str_size = str.size();
  string parser = "";
  for (int i = 0; i < str_size; i++) {
    if (str[i] == splitter) {
      result.push_back(parser);
      parser = "";
      continue;
    }
    parser += str[i];
  }

  result.push_back(parser);

  return result;
}

tree_node parse_xml(string xml) {
  int i = 0;
  int xml_size = xml.size();

  while (true) {
    if (xml[i] == '<')
      break;
    i++;
  }

  string element = "";

  while (true) {
    i++;
    if (xml[i] == '>')
      break;
    element += xml[i];
  }

  // extract xml content till the end
  string xml_inside = "";
  i++;
  string element_end = "</" + element + ">";
  int end_size = element_end.size();

  for (; i < xml_size; i++) {
    if (xml.substr(i, end_size) == element_end)
      break;
    xml_inside += xml[i];
  }

  tree_node node;
  node.title = element;

  // if (xml_inside[0] != '<') {
  //   node.content = xml_inside;
  //   return node;
  // }
  int j =0;
  while(true){
    if(xml_inside[j] == ' ' || xml_inside[j] =='\n' || xml_inside[j] =='\r'){
      j++;
      continue;
    }
    if(xml_inside[j] !='<'){
      node.content = xml_inside;
      return node;
    } else{
      break;
    }
  }

  // take the string divide into tree nodes

  int xml_inside_size = xml_inside.size();
  bool element_parse_start = false;
  bool element_parse_end = false;
  vector<string> elements;
  string element_inside = "";
  string element_inside_end = "";
  string parser = "";

  for (int k = 0; k < xml_inside_size; k++) {
    parser += xml_inside[k];

    if (xml_inside[k] == '<' && !element_parse_start) {
      element_parse_start = true;
      element_inside = "";
      continue;
    }

    if (xml_inside[k] == '>' && element_parse_start) {
      element_parse_end = true;
      continue;
    }

    if (element_parse_start && !element_parse_end) {
      element_inside += xml_inside[k];
    }

    if (element_parse_start && element_parse_end) {
      string element_end = "</" + element_inside + ">";
      int element_end_size = element_end.size();
      // cout<<parser;
      if (xml_inside.substr(k, element_end_size) == element_end) {
        parser += xml_inside.substr(k + 1, element_end_size - 1);
        k += element_end_size - 1;
        elements.push_back(parser);
        parser = "";
        element_parse_start = false;
        element_parse_end = false;
        element_inside = "";
      }
    }
  }

  int elements_size = elements.size();

  for (int l = 0; l < elements_size; l++) {
    node.children.push_back(parse_xml(elements[l]));
  }

  return node;
}

string transform_to_json(tree_node node) {
  // check for children
  // if no children retutn {title : content}
  // if one child return {title : transform}
  // if more than one child return title : [ transform for each child]
  int children_size = node.children.size();
  if (children_size == 0 && node.content != "") {
    return "{\"" + node.title + "\": \"" + node.content + "\"}";
  }
  if (children_size == 1) {
    return "{\"" + node.title + "\": " + transform_to_json(node.children[0]) +
           "}";
  }

  if (children_size > 1) {
    string result = "{\"" + node.title + "\": [";
    for (int i = 0; i < children_size; i++) {
      result += transform_to_json(node.children[i]);
      if (i != children_size - 1) {
        result += ",";
      }
    }
    result += "]}";

    return result;
  }

  return "{}";
}

void XmlParser::json(string input_file , string output_file) {

  string text, line;
  
  ifstream file(input_file);

  if (file.is_open()) {
      while (getline(file, line)) {
          text += line + "\n";
      }
      file.close();
  } else {
      cerr << "Unable to open file: " << input_file << endl;
  }

  tree_node root = parse_xml(text);
  string json = transform_to_json(root);

  ofstream json_file(output_file);

  if (json_file.is_open()) {
    json_file << json;
    json_file.close();
  }
  // cout<<"{" + json + "}";
}
