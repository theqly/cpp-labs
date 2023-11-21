#include "CSV_parser.h"
#include "tuple_printing.h"
#include <iostream>

int main(){
  const std::tuple tp{10, 10.5, "Hell", "o"};
  std::cout << tp << std::endl;
  return 0;
}