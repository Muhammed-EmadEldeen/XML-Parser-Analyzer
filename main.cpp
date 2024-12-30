#include <iostream>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << "Function -i <File Input> -o <File Output>" << std::endl;
    return 1;
  } else {
    if (!strcmp("verify", argv[1])) {
      // function is verify
    } else if (!strcmp("compress", argv[1])) {
      // function is compress
    } else if (!strcmp("decompress", argv[1])) {
      // function is decompress
    } else if (!strcmp("format", argv[1])) {
      // function is format
    } else if (!strcmp("json", argv[1])) {
      // function is json
    } else if (!strcmp("mini", argv[1])) {
      // function is mini
    } else {
      std::cout << "Invalid function" << std::endl;
      return 1;
    }
  }

  return 0;
}
