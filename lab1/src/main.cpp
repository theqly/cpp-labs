#include "bitarray.h"

int main(){
  BitArray arr1 = BitArray(16);
  BitArray arr2 = BitArray(16);
  arr1.reset();
  arr2.reset();
  bool a = arr1 == arr2;
  arr1.push_back(true);
  bool b = arr1 == arr2;
  arr2.push_back(true);
  bool c = arr1 == arr2;
  printf("%d %d %d", a, b, c);
  return 0;
}