#include "shared_ptr.h"

struct A{

};

int main(){
  shared_ptr<A> ptr1();
  shared_ptr<A> ptr2 = ptr1;
  return 0;
}
