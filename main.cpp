#include "XmlAnalyzer/UsersData.h"
#include "XmlParser/XmlParser.h"
#include <iostream>
#include <sstream>
#include <string.h>

#include <system_error>

using namespace std;

vector<string> divideString(string input) {
  stringstream ss(input);
  vector<string> output;
  string word;
  while (!ss.eof()) {
    getline(ss, word, ',');
    output.push_back(word);
  }
  return output;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << "Function -i <File Input> -o <File Output>" << std::endl;
    return 1;
  } else {

    std::string input_file, output_file, searchBy;
    bool topic = false;
    int id;
    string ids;
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-i") == 0) {
        if (i + 1 < argc) {
          input_file = argv[i + 1];

        } else {
          std::cerr << "Error: Missing value for -i\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-o") == 0) {
        if (i + 1 < argc) {
          output_file = argv[i + 1];
        } else {
          std::cerr << "Error: Missing value for -o\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-w") == 0) {
        if (i + 1 < argc) {
          searchBy = argv[i + 1];
          topic = false;
        } else {
          std::cerr << "Error: Missing value for -w\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-t") == 0) {
        if (i + 1 < argc) {
          searchBy = argv[i + 1];
          topic = true;
        } else {
          std::cerr << "Error: Missing value for -t\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-id") == 0) {
        if (i + 1 < argc) {
          id = stoi(argv[i + 1]);
        } else {
          std::cerr << "Error: Missing value for -id\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-ids") == 0) {
        ids = argv[i + 1];
      }
    }

    for (int i = 0; i < argc; i++) {
      if (!strcmp("verify", argv[i])) {
        bool fix = false;
        if (argc > 2) {
          for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-f") == 0)
              fix = true;
          }
        }
        XmlParser::XML_error_detection(input_file);
        if (fix) {
          XmlParser::correct(input_file, output_file);
        }
        break;
      } else if (!strcmp("compress", argv[1])) {
        XmlParser::byte_pair_compress(input_file, output_file);
        break;
      } else if (!strcmp("decompress", argv[1])) {
        XmlParser::decompress(input_file, "mapping.txt", output_file);
        break;
      } else if (!strcmp("format", argv[1])) {
        XmlParser::prettifyXML(input_file, output_file);

        break;

      } else if (!strcmp("json", argv[1])) {
        XmlParser::json(input_file, output_file);

        break;
      } else if (!strcmp("mini", argv[1])) {
        XmlParser::minifyXML(input_file, output_file);

        break;
      } else if (!strcmp("most_active", argv[1])) {
        UsersData usersData;
        usersData.getUsersFromXml(input_file);
        cout << usersData.getMostFollowingUser().getID() << endl;

        break;
      } else if (!strcmp("most_influencer", argv[1])) {
        UsersData usersData;
        usersData.getUsersFromXml(input_file);
        cout << usersData.getMostFollowedUser().getID() << endl;

        break;
      } else if (!strcmp("mutual", argv[1])) {
        UsersData usersData;
        usersData.getUsersFromXml(input_file);
        vector<string> ans = usersData.findMutualFollowers(divideString(ids));
        for (auto a : ans)
          cout << a << " " << endl;

        break;
      } else if (!strcmp("suggest", argv[1])) {
        UsersData usersData;
        usersData.getUsersFromXml(input_file);
        vector<int> ans = usersData.suggestFollow(id);
        for (auto a : ans)
          cout << a << " " << endl;

        break;
      } else if (!strcmp("search", argv[1])) {
        UsersData usersData;
        usersData.getUsersFromXml(input_file);
        if (topic) {
          vector<Post> ans = usersData.getPostsByTopic(searchBy);
          for (Post p : ans) {
            cout << p.body << endl;
          }
        } else {
          vector<Post> ans = usersData.getPostsByWord(searchBy);

          for (Post p : ans) {
            cout << p.body << endl;
          }
        }

        break;
      }
    }
  }

  return 0;
}
