#include "bitarray.h"

typedef unsigned long T;

BitArray::BitArray() : _capacity(0), _cur_size(0), _array(nullptr){};

BitArray::~BitArray(){
  delete[] _array;
};

BitArray::BitArray(int num_bits, T value){
  if(num_bits < 0) return;
  unsigned long long num_of_T = (num_bits / sizeof(T)) + sizeof(T);
  _capacity = num_of_T * sizeof(T);
  _cur_size = num_bits;
  _array = new unsigned long[num_of_T];
  _array[0] = value;
}

BitArray::BitArray(const BitArray& b) {
  T* tmp = new T[b._capacity / sizeof(T)];
  for(size_t i = 0; i != (b._capacity / sizeof(T)) - 1; ++i){
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;
};

void BitArray::swap(BitArray& b){
  auto tmp = std::move(b);
  b = std::move(*this);
  *this = std::move(tmp);
};

BitArray& BitArray::operator=(const BitArray& b){
  if(this == &b){
    return *this;
  }
  T* tmp = new T[b._capacity / sizeof(T)];
  for(size_t i = 0; i != (b._capacity / sizeof(T)) - 1; ++i){
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;

  return *this;
};


//доделать для num_bits < или == cur_size
void BitArray::resize(int num_bits, bool value){
  unsigned long long num_of_T = (num_bits / sizeof(T)) + sizeof(T);
  T* tmp = new T[num_of_T];
  for(size_t i = 0; i != (_capacity / sizeof(T)) - 1; ++i){
    tmp[i] = _array[i];
  }

  _capacity = num_of_T * sizeof(T);
  _array = std::move(tmp);
}

void BitArray::clear(){
  //????
}

void BitArray::push_back(bool bit){
  if(_capacity == _cur_size){
    resize(static_cast<int>(static_cast<double>(_capacity) * resizing_rate));
    _array[(_capacity / sizeof(T)) - 1] |= (bit << sizeof(T));
    _cur_size++;
  }else{
    _array[(_cur_size / sizeof(T)) - 1] |= (bit << (sizeof(T) - (_cur_size % sizeof(T))));
    _cur_size++;
  };
}

BitArray& BitArray::operator&=(const BitArray& b){
  T* tmp = new T[b._capacity / sizeof(T)];
  for(size_t i = 0; i != (b._capacity / sizeof(T)) - 1; ++i){
    tmp[i] &= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

BitArray& BitArray::operator|=(const BitArray& b){
  T* tmp = new T[b._capacity / sizeof(T)];
  for(size_t i = 0; i != b._capacity / sizeof(T); ++i){
    tmp[i] |= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

BitArray& BitArray::operator^=(const BitArray& b){
  T* tmp = new T[b._capacity / sizeof(T)];
  for(size_t i = 0; i != b._capacity / sizeof(T); ++i){
    tmp[i] ^= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

//Битовый сдвиг с заполнением нулями.
BitArray& BitArray::operator<<=(int n){}
BitArray& BitArray::operator>>=(int n){}
BitArray BitArray::operator<<(int n) const{}
BitArray BitArray::operator>>(int n) const{}


//Устанавливает бит с индексом n в значение val.
BitArray& BitArray::set(int n, bool val){}
//Заполняет массив истиной.
BitArray& BitArray::set(){}

//Устанавливает бит с индексом n в значение false.
BitArray& BitArray::reset(int n){}
//Заполняет массив ложью.
BitArray& BitArray::reset(){}

//true, если массив содержит истинный бит.
bool BitArray::any() const{
  for(size_t i = 0; i != _capacity /)
}
//true, если все биты массива ложны.
bool BitArray::none() const{}
//Битовая инверсия
BitArray BitArray::operator~() const{}
//Подсчитывает количество единичных бит.
int BitArray::count() const{}


//Возвращает значение бита по индексу i.
bool BitArray::operator[](int i) const{}

int BitArray::size() const{}
bool BitArray::empty() const{}

//Возвращает строковое представление массива.
std::string BitArray::to_string() const{}