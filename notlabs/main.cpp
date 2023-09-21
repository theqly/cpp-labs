#include <stdlib.h>
#include <string.h>
#include <iostream>

class string {
 public:
  string(size_t initial_capacity) {
    capacity = initial_capacity;
    memory = (char*)malloc(capacity);
    std::cout << "constructor" << std::endl;
  }

  string(char* char_array){
    capacity = strlen(char_array);
    size = capacity;
    memory = (char*)malloc(capacity);
    strcpy(memory, char_array);
    std::cout << "constructor 2" << std::endl;
  }

  string(const string& other_str){
    capacity = other_str.capacity;
    size = other_str.size;
    memory = (char*)malloc(capacity);
    for(int i = 0; i < size; ++i){
      memory[i] = other_str.memory[i];
    }
    std::cout << "copy ctor!" << std::endl;
  }

  void append(char c) {
    if (size < capacity) {
      memory[size] = c;
      size++;
    }
    else {
      char* tmp;
      tmp = (char*)realloc(memory, capacity);
      if (tmp == nullptr) {
        std::cout << "error" << std::endl;
        return;
      }
      memory = tmp;
      capacity *= 2;
      memory[size] = c;
      size++;
    }
  }

  string& operator=(const string& other_str){
    capacity = other_str.capacity;
    size = other_str.size;
    memory = (char*)malloc(capacity);
    for(int i = 0; i < size; ++i){
      memory[i] = other_str.memory[i];
    }
    std::cout << "operator" << std::endl;
    return *this;
  }

  void operator[](int n) {
    std::cout << memory[n] << std::endl;
  }

  void show() {
    for (int i = 0; i < size; i++) {
      std::cout << memory[i];
    }
    std::cout << std::endl;
  }

  //деструктор
  ~string() {
    free(memory);
    std::cout << "destructor" << std::endl;
  }
 private:
  size_t capacity = 0;
  size_t size = 0;
  char* memory = nullptr;
};

int main() {

  string s1 = string(4);
  char c;
  for (int i = 0; i < 8; i++) {
    std::cin >> c;
    s1.append(c);
  }
  std::cout << "s1" << std::endl;
  s1.show();

  string s2 = string(s1);
  std::cout << "s2" << std::endl;
  s2.show();

  string s3 = string(8);
  s3.operator=(s1);
  std::cout << "s3" << std::endl;
  s3.show();

  string s4 = string((char*)"mishahui");
  std::cout << "s4" << std::endl;
  s4.show();

  s1.operator[](2);
  return 0;
}
