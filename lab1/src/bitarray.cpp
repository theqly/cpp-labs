#include "bitarray.h"

#define full_true 255

BitArray::BitArray() : _capacity(0), _cur_size(0), _array(nullptr){};

BitArray::~BitArray(){
  delete[] _array;
};

BitArray::BitArray(int num_bits, unsigned char value){
  if(num_bits < 0) return;
  if(num_bits % type_size == 0) _capacity = num_bits;
  else _capacity = num_bits + (type_size-(num_bits % type_size));
  _cur_size = num_bits;
  _array = new unsigned char[_capacity / type_size];
  _array[0] = value;
}

BitArray::BitArray(const BitArray& b) {
  auto* tmp = new unsigned char[b._capacity / type_size];
  for(size_t i = 0; i < b._capacity / type_size; ++i){
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;
};

void BitArray::swap(BitArray& b){
  std::swap(_array, b._array);

  size_t tmp_cap = b._capacity;
  size_t tmp_csize = b._cur_size;

  b._capacity = _capacity;
  b._cur_size = _cur_size;

  _capacity = tmp_cap;
  _cur_size = tmp_csize;
};

BitArray& BitArray::operator=(const BitArray& b){
  auto* tmp = new unsigned char[b._capacity / type_size];
  for(size_t i = 0; i < b._capacity / type_size; ++i){
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;

  return *this;
};


//доделать для num_bits < или == cur_size
void BitArray::resize(int num_bits, bool value){
  size_t new_capacity;
  if(num_bits % type_size == 0) new_capacity = num_bits;
  else new_capacity = num_bits + (type_size-(num_bits % type_size));
  auto tmp = new unsigned char[new_capacity / type_size];
  for(size_t i = 0; i != _capacity / type_size; ++i){
    tmp[i] = _array[i];
  }

  _cur_size = num_bits;
  _capacity = new_capacity;
  _array = std::move(tmp);
}

void BitArray::clear(){
  delete[] _array;
  _capacity = 0;
  _cur_size = 0;
  _array = nullptr;
}

void BitArray::push_back(bool bit){
  if(_capacity == _cur_size){
    size_t tmp = _cur_size;
    resize(static_cast<int>(_capacity * resizing_rate));
    set(static_cast<int>(tmp), bit);
    _cur_size++;
  }else{
    set(static_cast<int>(_cur_size), bit);
    _cur_size++;
  };
}

BitArray& BitArray::operator&=(const BitArray& b){
  auto tmp = new unsigned char[b._capacity / type_size];
  for(size_t i = 0; i < b._capacity / type_size; ++i){
    tmp[i] &= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

BitArray& BitArray::operator|=(const BitArray& b){
  auto tmp = new unsigned char[b._capacity / type_size];
  for(size_t i = 0; i < b._capacity / type_size; ++i){
    tmp[i] |= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

BitArray& BitArray::operator^=(const BitArray& b){
  auto tmp = new unsigned char[b._capacity / type_size];
  for(size_t i = 0; i < b._capacity / type_size; ++i){
    tmp[i] ^= b._array[i];
  }
  _array = std::move(tmp);
  return *this;
}

//Битовый сдвиг с заполнением нулями.
BitArray& BitArray::operator<<=(int n){
  return *this;
}
BitArray& BitArray::operator>>=(int n){
  return *this;
}
BitArray BitArray::operator<<(int n) const{
  return *this;
}
BitArray BitArray::operator>>(int n) const{
  return *this;
}


//Устанавливает бит с индексом n в значение val.
BitArray& BitArray::set(int n, bool val){
  if(val) _array[n / type_size] |= mask(n);
  else _array[n / type_size] &= ~mask(n);
  return *this;
}
//Заполняет массив истиной.
BitArray& BitArray::set(){
  for(size_t i = 0; i < _capacity / type_size; ++i){
    _array[i] = full_true;
  }
  return *this;
}

//Устанавливает бит с индексом n в значение false.
BitArray& BitArray::reset(int n){
  set(n, false);
  return *this;
}
//Заполняет массив ложью.
BitArray& BitArray::reset(){
  for(size_t i = 0; i < _capacity / type_size; ++i){
    _array[i] = 0;
  }
  return *this;
}

//true, если массив содержит истинный бит.
bool BitArray::any() const{
  for(size_t i = 0; i < _capacity / type_size; ++i){
    if(_array[i] != 0){
      return true;
    }
  }
  return false;
}
//true, если все биты массива ложны.
bool BitArray::none() const{
  return !any();
}
//Битовая инверсия
BitArray BitArray::operator~() const{
  for(size_t i = 0; i < _capacity / type_size; ++i){
    _array[i] = ~_array[i];
  }
  return *this;
}
//Подсчитывает количество единичных бит.
int BitArray::count() const{
  int counter = 0;
  for(size_t i = 0; i != _capacity / type_size; ++i){
    for(size_t k = 0; k < type_size; ++k){
      if((_array[i] & mask(k)) != 0) counter++;
    }
  }
  return counter;
}


//Возвращает значение бита по индексу i.
bool BitArray::operator[](int i) const{
  return (mask(i) & _array[i/8]) != 0;
}

int BitArray::size() const{
  return (int)_cur_size;
}

bool BitArray::empty() const{
  if(_cur_size == 0) return true;
  return false;
}

//Возвращает строковое представление массива.
std::string BitArray::to_string() const{
  std::string str;
  for(size_t i = 0; i < _capacity / type_size; ++i){
    for(size_t k = 0; k < type_size; ++k){
      if((_array[i] & mask(k)) != 0) str.push_back('1');
      else str.push_back('0');
    }
  }
  return str;
}