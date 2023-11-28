#include "CSV_parser.h"
#include "tuple_.h"
#include <iostream>

int main(int argc, char** argv){
  std::string in = std::string(argv[1]);
  std::string out = std::string(argv[2]);
  std::ifstream fin(in);
  std::ifstream fout(out);
  CVSParser<std::string, int, std::string> parser(fin);
  for(auto& it : parser) {
    std::cout << it << std::endl;
  }
  return 0;
}