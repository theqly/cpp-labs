#include "csv_parser.h"
#include <iostream>

int main(int argc, char** argv){
  auto in = std::string(argv[1]);
  auto out = std::string(argv[2]);
  std::ifstream fin(in);
  std::ofstream fout(out);
  CVSParser<std::string, int, std::string> parser(fin, 1);
  for(auto& it : parser) {
    fout << it << std::endl;
  }
  return 0;
}