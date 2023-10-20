#include "bitarray.h"

#define full_true 255

BitArray::BitArray() : _capacity(0), _cur_size(0), _array(nullptr) {}

BitArray::~BitArray() {
  delete[] _array;
}

BitArray::BitArray(int num_bits, unsigned char value) {
  if (num_bits < 0) return;
  if (num_bits % type_size == 0) _capacity = num_bits;
  else _capacity = num_bits + (type_size - (num_bits % type_size));
  _cur_size = num_bits;
  _array = new unsigned char[_capacity / type_size];
  _array[0] = value;
}

BitArray::BitArray(const BitArray &b) {
  auto *tmp = new unsigned char[b._capacity / type_size];
  for (size_t i = 0; i < b._capacity / type_size; ++i) {
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;
}

void BitArray::swap(BitArray &b) {
  std::swap(_array, b._array);

  size_t tmp_cap = b._capacity;
  size_t tmp_csize = b._cur_size;

  b._capacity = _capacity;
  b._cur_size = _cur_size;

  _capacity = tmp_cap;
  _cur_size = tmp_csize;
}

BitArray &BitArray::operator=(const BitArray &b) {
  if (&b == this) return *this;

  auto *tmp = new unsigned char[b._capacity / type_size];
  for (size_t i = 0; i < b._capacity / type_size; ++i) {
    tmp[i] = b._array[i];
  }

  delete[] _array;
  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;

  return *this;
}

//доделать для num_bits < или == cur_size
void BitArray::resize(int num_bits) {
  size_t new_capacity;
  if (num_bits % type_size == 0) new_capacity = num_bits;
  else new_capacity = num_bits + (type_size - (num_bits % type_size));
  auto tmp = new unsigned char[new_capacity / type_size];
  for (size_t i = 0; i != _capacity / type_size; ++i) {
    tmp[i] = _array[i];
  }
  delete[] _array;
  _array = std::move(tmp);
  _cur_size = num_bits;
  _capacity = new_capacity;
}

void BitArray::clear() {
  delete[] _array;
  _capacity = 0;
  _cur_size = 0;
  _array = nullptr;
}

void BitArray::push_back(bool bit) {
  if (_capacity == _cur_size) {
    size_t tmp = _cur_size;
    resize(static_cast<int>(_capacity * resizing_rate));
    set(static_cast<int>(tmp), bit);
    _cur_size++;
  } else {
    set(static_cast<int>(_cur_size), bit);
    _cur_size++;
  }
}

BitArray &BitArray::operator&=(const BitArray &b) {
  if (_cur_size != b._cur_size) throw std::bad_array_new_length();
  for (size_t i = 0; i < b._capacity / type_size; ++i) {
    _array[i] &= b._array[i];
  }
  return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
  if (_cur_size != b._cur_size) throw std::bad_array_new_length();
  for (size_t i = 0; i < b._capacity / type_size; ++i) {
    _array[i] |= b._array[i];
  }
  return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
  if (_cur_size != b._cur_size) throw std::bad_array_new_length();
  for (size_t i = 0; i < b._capacity / type_size; ++i) {
    _array[i] ^= b._array[i];
  }
  return *this;
}

BitArray &BitArray::operator<<=(int n) {
  if (n >= _cur_size) return reset();
  else if(n <= 0) return *this;
  int byte_shift = n / type_size;
  if(n % type_size != 0){
    for(size_t i = _cur_size / type_size; i > 0; --i){

    }
  } else {
    for(size_t i = 0; i < _capacity / type_size - byte_shift; ++i){
      _array[i] = _array[i + byte_shift];
      
    }
  }
  return *this;
}
BitArray &BitArray::operator>>=(int n) {
  if (n >= _cur_size) return reset();

  return *this;
}
BitArray BitArray::operator<<(int n) const {
  BitArray tmp(*this);
  return tmp <<= n;
}
BitArray BitArray::operator>>(int n) const {
  BitArray tmp(*this);
  return tmp >>= n;
}

BitArray &BitArray::set(int n, bool val) {
  if (n > _cur_size) throw std::bad_array_new_length();
  if (val) _array[n / type_size] |= mask(n);
  else _array[n / type_size] &= ~mask(n);
  return *this;
}

BitArray &BitArray::set() {
  for (size_t i = 0; i < _capacity / type_size; ++i) {
    _array[i] = full_true;
  }
  return *this;
}

BitArray &BitArray::reset(int n) {
  if (n > _cur_size) throw std::bad_array_new_length();
  set(n, false);
  return *this;
}

BitArray &BitArray::reset() {
  for (size_t i = 0; i < _capacity / type_size; ++i) {
    _array[i] = 0;
  }
  return *this;
}

bool BitArray::any() const {
  for (size_t i = 0; i < _capacity / type_size; ++i) {
    if (_array[i] != 0) {
      return true;
    }
  }
  return false;
}

bool BitArray::none() const {
  return !any();
}

BitArray BitArray::operator~() const {
  for (size_t i = 0; i < _capacity / type_size; ++i) {
    _array[i] = ~_array[i];
  }
  return *this;
}

int BitArray::count() const {
  int counter = 0;
  for (size_t i = 0; i != _capacity / type_size; ++i) {
    for (size_t k = 0; k < type_size; ++k) {
      if ((_array[i] & mask(k)) != 0) counter++;
    }
  }
  return counter;
}

bool BitArray::operator[](int i) const {
  if (i > _cur_size) throw std::bad_array_new_length();
  return (mask(i) & _array[i / 8]) != 0;
}

int BitArray::size() const {
  return (int) _cur_size;
}

bool BitArray::empty() const {
  if (_cur_size == 0) return true;
  return false;
}

std::string BitArray::to_string() const {
  std::string str;
  for (size_t i = 0; i < _capacity / type_size; ++i) {
    for (size_t k = 0; k < type_size; ++k) {
      if ((_array[i] & mask(k)) != 0) str.push_back('1');
      else str.push_back('0');
    }
  }
  return str;
}

bool operator==(const BitArray & a, const BitArray & b){
  return (a._array == b._array);
}

bool operator!=(const BitArray & a, const BitArray & b){
  return !(a == b);
}

BitArray operator&(const BitArray& b1, const BitArray& b2){
  BitArray tmp(b1);
  return tmp &= b2;
}

BitArray operator|(const BitArray& b1, const BitArray& b2){
  BitArray tmp(b1);
  return tmp |= b2;
}

BitArray operator^(const BitArray& b1, const BitArray& b2){
  BitArray tmp(b1);
  return tmp ^= b2;
}