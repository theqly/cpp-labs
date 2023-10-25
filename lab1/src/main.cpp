#include <iostream>
#include "bitarray.h"

int main() {
  BitArray arr1 = BitArray(16);
  arr1.set();
  bool assigment = false;
  const auto itEnd = arr1.end();
  for( auto it = arr1.begin(); it != itEnd; ++it ) {
    it = assigment;
    assigment = !assigment;
  }
  std::cout << arr1.to_string();
  return 0;
}