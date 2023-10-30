#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>

template<class T>
class shared_ptr {
 public:
  shared_ptr(T *p = nullptr) {
    ptr = p;
    counter = new size_t(0);
    (*counter)++;
  }

  ~shared_ptr() {
    (*counter)--;
    if (*counter == 0){
      delete ptr;
      delete counter;
    }
  }

  shared_ptr(const shared_ptr &other) {
    ptr = other.ptr;
    counter = other.counter;
    (*counter)++;
  }

  shared_ptr(shared_ptr &&other) {
    ptr = other.ptr;
    counter = other.counter;
    other.ptr = nullptr;
    other.counter = nullptr;
  }

  shared_ptr &operator=(const shared_ptr &other) {
    if (ptr != other.ptr) ~this; //?
    ptr = other.ptr;
    counter = other.counter;
    (*counter)++;
    return *this;
  }

  shared_ptr &operator=(shared_ptr &&other) {
    if (ptr != other.ptr) ~this; //?
    ptr = other.ptr;
    counter = other.counter;
    other.ptr = nullptr;
    other.counter = nullptr;
    return *this;
  }

  T *get() {
    return ptr;
  }

  T *reset(T *newnew = nullptr) {
    if (ptr) delete ptr;
    ptr = newnew;
    (*counter) = 0;        //???
  }

  T *release() {
    T *tmp = ptr;
    ptr = nullptr;
    (*counter)--;
    return tmp;
  }

  T *operator->() {
    return ptr;
  }

  T &operator*() {
    return *ptr;
  }

 private:
  size_t *counter;
  T *ptr;
};

#endif //SHARED_PTR
