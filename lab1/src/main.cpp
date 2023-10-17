#include "bitarray.h"

int main(){
  /*BitArray arr1 = BitArray(8);
  BitArray arr2 = BitArray(8);
  arr1.reset();
  arr2.set();
  arr2 &= arr1;
  arr1.set(3, true);
  arr2.set();
  for(size_t i = 0; i < 8; ++i){
    printf("%d", arr2[i]);
  }
  arr2 &= arr1;
  for(size_t i = 0; i < 8; ++i){
    printf("%d", arr2[i]);
  }*/
  BitArray arr1 = BitArray(8);
  arr1.set(3, true);
  arr1.set(4, true);
  arr1.set(5, true);
  std::string str1 = arr1.to_string();
  std::string str2 = "00011100";
  return 0;
}