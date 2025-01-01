#include "XmlAnalyzer/UsersData.h"
#include "XmlParser/XmlParser.h"
#include <iostream>
#include <string.h>
#include <system_error>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << "Function -i <File Input> -o <File Output>" << std::endl;
    return 1;
  } else {

    std::string input_file, output_file, word, topic;
    int id;
    vector<int> ids;
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
          word = argv[i + 1];
        } else {
          std::cerr << "Error: Missing value for -w\n";
          return 1;
        }
      } else if (strcmp(argv[i], "-t") == 0) {
        if (i + 1 < argc) {
          topic = argv[i + 1];
        } else {
          std::cerr << "Error: Missing value for -t\n";
          return 1;
        }
      }
    }

    for (int i = 0; i < argc; i++) {
      if (!strcmp("verify", argv[i])) {
        bool fix = false;
        if (argc > 2) {
          for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-f") == 0)
              fix = true;
          }
        }
        XmlParser::XML_error_detection(input_file);
        if (fix) {
          XmlParser::correct(input_file, output_file);
        }
      } else if (!strcmp("compress", argv[1])) {
        XmlParser::byte_pair_compress(input_file, output_file);
      } else if (!strcmp("decompress", argv[1])) {
        XmlParser::decompress(input_file, "mapping.txt", output_file);
      } else if (!strcmp("format", argv[1])) {
        XmlParser::prettifyXML(input_file, output_file);
      } else if (!strcmp("json", argv[1])) {
        XmlParser::json(input_file, output_file);
      } else if (!strcmp("mini", argv[1])) {
        XmlParser::minifyXML(input_file, output_file);
      }
      /* else if (!strcmp("most_active", argv[1])) { */
      /*   read_input(argc, argv, input_file); */
      /*   UsersData usersData; */
      /*   usersData.parseXmlFile(input_file); */
      /*   usersData.getMostFollowingUser(); */
      /* } else if (!strcmp("most_influencer", argv[1])) { */
      /*   read_input(argc, argv, input_file); */
      /*   UsersData usersData; */
      /*   usersData.parseXmlFile(input_file); */
      /*   usersData.getMostFollowedUser(); */
      /* } */
    }
  }

  return 0;
}
