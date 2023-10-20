#include "bitarray.h"

#include <iostream>

int main(){
  BitArray arr1 = BitArray(8);
  BitArray arr2 = BitArray(8);
  arr1.set(3, true);
  for(size_t i = 0; i < 8; ++i){
    std::cout << arr1[i];
  }
  std::cout << std::endl;
  arr1 <<= 1;
  for(size_t i = 0; i < 8; ++i){
    std::cout << arr1[i];
  }
  std::cout << std::endl;
  return 0;
}