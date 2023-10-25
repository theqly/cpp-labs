#include <iostream>
#include "bitarray.h"

int main() {
  BitArray arr1 = BitArray(16);
  arr1.set();
  bool bit = false;
  for(auto it = arr1.begin(); it != arr1.end(); ++it){
    it = bit;
    bit = !bit;
  }
  std::cout << arr1.to_string();

  for(auto it : arr1){
    it = true;
  }

  for(auto it = arr1.begin(); it != arr1.end(); ++it){
    it = bit;
    bit = !bit;
  }

  std::cout << arr1.to_string();
  return 0;
}