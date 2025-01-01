#include "XmlAnalyzer/UsersData.h"
#include "XmlParser/XmlParser.h"
#include <iostream>
#include <string.h>
#include <system_error>

using namespace std;

int read_input_output(int argc, char *argv[], string &input_file,
                      string &output_file) {

  for (int i = 2; i < argc; ++i) {
    if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
      input_file = argv[++i];
    } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
      output_file = argv[++i];
    } else {
      std::cerr << "Error: Invalid argument or missing value: " << argv[i]
                << "\n";
      return 1;
    }
  }

  if (input_file.empty() || output_file.empty()) {
    std::cerr << "Error: Both input and output files must be specified.\n";
    return 1;
  }
  return 0;
}

int read_input(int argc, char *argv[], string &input_file) {

  for (int i = 2; i < argc; ++i) {
    if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
      input_file = argv[++i];
    } else {
      std::cerr << "Error: Invalid argument or missing value: " << argv[i]
                << "\n";
      return 1;
    }
  }

  if (input_file.empty()) {
    std::cerr << "Error: Input file must be specified.\n";
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << "Function -i <File Input> -o <File Output>" << std::endl;
    return 1;
  } else {
    std::string input_file, output_file;

    if (!strcmp("verify", argv[1])) {
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
      read_input_output(argc, argv, input_file, output_file);
    } else if (!strcmp("compress", argv[1])) {
      read_input_output(argc, argv, input_file, output_file);
      XmlParser::byte_pair_compress(input_file, output_file);
    } else if (!strcmp("decompress", argv[1])) {
      read_input_output(argc, argv, input_file, output_file);
      XmlParser::decompress(input_file, "mapping.txt", output_file);
    } else if (!strcmp("format", argv[1])) {
      read_input_output(argc, argv, input_file, output_file);
      XmlParser::prettifyXML(input_file, output_file);
    } else if (!strcmp("json", argv[1])) {
      read_input_output(argc, argv, input_file, output_file);
      XmlParser::json(input_file, output_file);
    } else if (!strcmp("mini", argv[1])) {
      read_input_output(argc, argv, input_file, output_file);
      XmlParser::minifyXML(input_file, output_file);
    } else if (!strcmp("most_active", argv[1])) {
      read_input(argc, argv, input_file);
      UsersData usersData;
      usersData.parseXmlFile(input_file);
      usersData.getMostFollowingUser();
    } else if (!strcmp("most_influencer", argv[1])) {
      read_input(argc, argv, input_file);
      UsersData usersData;
      usersData.parseXmlFile(input_file);
      usersData.getMostFollowedUser();
    }

    else {
      std::cout << "Invalid function" << std::endl;
      return 1;
    }
  }

  return 0;
}
