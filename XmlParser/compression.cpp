#include "XmlParser.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<string, string> mapping;

// Read file and return string
string read_file(const string &file_path) {
  ifstream file(file_path);
  stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

// Write string content to file
void write_file(const string &file_path, const string &content) {
  ofstream file(file_path);
  file << content;
}

// Keep track of the frequency of each pair
struct PairFrequency {
  string pair;
  int frequency;
  bool operator<(const PairFrequency &rhs) const {
    return frequency < rhs.frequency;
  }
};

unordered_map<string, int> count_byte_pairs(const string &input) {

  // initialize a map to store the frequency of each pair
  unordered_map<string, int> pair_count;

  // iterate through the input string
  for (size_t i = 0; i < input.length() - 1; ++i) {

    // check if the pair is already in the mapping "very important" to avoid
    // infinite loop
    if (mapping.find(input.substr(i, 1)) != mapping.end() ||
        mapping.find(input.substr(i + 1, 1)) != mapping.end()) {
      continue; // skip if already in the mapping
    }

    // get the pair of bytes
    string pair = input.substr(i, 2);

    // increment the frequency of the pair
    pair_count[pair]++;
  }
  return pair_count;
}

string replace_byte_pair(string &input, const string &pair,
                         const string &placeholder) {
  size_t pos = 0; // start from the beginning

  // replace all occurrences of the pair with the placeholder
  while ((pos = input.find(pair, pos)) != string::npos) {
    input.replace(pos, pair.length(), placeholder);
    pos += placeholder.length();
  }
  return input;
}

void XmlParser::byte_pair_compress(const string &input_file,
                                   const string &output_file) {
  string compressed = read_file(input_file);
  // dynamic placeholders generation
  vector<string> placeholders;
  for (char c = 33; c <= 126; ++c) {
    placeholders.push_back(string(1, c));
  }

  while (!placeholders.empty()) {
    auto pair_count = count_byte_pairs(compressed);
    if (pair_count.empty())
      break;

    // priority queue to keep track of most repeated pair
    priority_queue<PairFrequency> pq;
    for (const auto &pair : pair_count) {
      pq.push({pair.first, pair.second});
    }

    // get the most frequent pair
    auto most_frequent_pair = pq.top().pair;
    int max_frequency = pq.top().frequency;
    if (max_frequency < 2)
      break; // exit if all pairs are unique

    // get next placeholder
    string placeholder = placeholders.back();
    placeholders.pop_back();

    // store the pair in the mapping
    mapping[placeholder] = most_frequent_pair;

    // replace the most repeated pair with placeholders
    compressed = replace_byte_pair(compressed, most_frequent_pair, placeholder);
  }
  write_file(output_file, compressed);
  cout << "File compressed successfully to a file named " << output_file
       << endl;
  string s = "mapping.txt";
  ofstream file(s);

  for (const auto &pair : mapping) {
    file << pair.first << endl;
    file << pair.second << endl;
  }
  file.close();
}
