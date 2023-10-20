#include "bitarray.h"
#include <iostream>

const unsigned char k_full_true = 255;
const size_t k_type_size = 8;
const unsigned char full_zero = 0;

static unsigned char mask(size_t pos) {
  return 1 << (k_type_size - 1 - (pos % k_type_size));
};

static unsigned char assigment_zero(const size_t i) {
  return ~(1 << ((k_type_size - 1) - (i % k_type_size)));
}

static unsigned char assigment_bit(const size_t i) {
  return (1 << ((k_type_size - 1) - (i % k_type_size)));
}

BitArray::BitArray()
    : _capacity(0)
    , _cur_size(0)
    , _array(nullptr) {
}

BitArray::~BitArray() {
  delete[] _array;
}

BitArray::BitArray(size_t num_bits, unsigned char value) {
  if( num_bits < 0 )
    return;
  if( num_bits % k_type_size == 0 )
    _capacity = num_bits;
  else
    _capacity = num_bits + (k_type_size - (num_bits % k_type_size));
  _cur_size = num_bits;
  _array = new unsigned char[_capacity / k_type_size];
  _array[0] = value;
}

BitArray::BitArray(const BitArray& b) {
  auto *tmp = new unsigned char[b._capacity / k_type_size];
  for( size_t i = 0; i < b._capacity / k_type_size; ++i ) {
    tmp[i] = b._array[i];
  }

  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;
}

void BitArray::swap(BitArray& b) {
  std::swap(_array, b._array);

  size_t tmp_cap = b._capacity;
  size_t tmp_csize = b._cur_size;

  b._capacity = _capacity;
  b._cur_size = _cur_size;

  _capacity = tmp_cap;
  _cur_size = tmp_csize;
}

BitArray& BitArray::operator=(const BitArray& b) {
  if( &b == this )
    return *this;

  auto *tmp = new unsigned char[b._capacity / k_type_size];
  for( size_t i = 0; i < b._capacity / k_type_size; ++i ) {
    tmp[i] = b._array[i];
  }

  delete[] _array;
  _array = std::move(tmp);
  _capacity = b._capacity;
  _cur_size = b._cur_size;

  return *this;
}

// доделать для num_bits < или == cur_size
void BitArray::resize(size_t num_bits) {
  size_t new_capacity;
  if( num_bits % k_type_size == 0 )
    new_capacity = num_bits;
  else
    new_capacity = num_bits + (k_type_size - (num_bits % k_type_size));
  auto tmp = new unsigned char[new_capacity / k_type_size];
  for( size_t i = 0; i != _capacity / k_type_size; ++i ) {
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
  if( _capacity == _cur_size ) {
    size_t tmp = _cur_size;
    resize(static_cast<int>(_capacity * resizing_rate));
    set(static_cast<int>(tmp), bit);
    _cur_size++;
  }
  else {
    set(static_cast<int>(_cur_size), bit);
    _cur_size++;
  }
}

BitArray& BitArray::operator&=(const BitArray& b) {
  if( _cur_size != b._cur_size )
    throw std::bad_array_new_length();
  for( size_t i = 0; i < b._capacity / k_type_size; ++i ) {
    _array[i] &= b._array[i];
  }
  return *this;
}

BitArray& BitArray::operator|=(const BitArray& b) {
  if( _cur_size != b._cur_size )
    throw std::bad_array_new_length();
  for( size_t i = 0; i < b._capacity / k_type_size; ++i ) {
    _array[i] |= b._array[i];
  }
  return *this;
}

BitArray& BitArray::operator^=(const BitArray& b) {
  if( _cur_size != b._cur_size )
    throw std::bad_array_new_length();
  for( size_t i = 0; i < b._capacity / k_type_size; ++i ) {
    _array[i] ^= b._array[i];
  }
  return *this;
}

BitArray& BitArray::operator<<=(int n) {
  if( !n ) {
    return *this;
  }

  for( size_t i = 0; i < _cur_size - n; i++ ) {
    unsigned char bit = (mask(i + n) & _array[(i + n) / k_type_size]);
    _array[i / k_type_size] &= (~mask(i));
    bit = (i % k_type_size <= (i + n) % k_type_size)
                ? (bit << ((i % k_type_size) - ((i + n) % k_type_size)))
                          | ((~full_zero)
                             >> (k_type_size - ((i % k_type_size) - ((i + n) % k_type_size))))
                : bit >> (((i + n) % k_type_size) - (i % k_type_size))
                          | ((~full_zero)
                             << (k_type_size - (((i+n) % k_type_size) - (i  % k_type_size))));
    _array[i / k_type_size] |= bit;
  }

  for( size_t i = _cur_size - n; i < _cur_size; i++ ) {
    _array[i / k_type_size] &= (~mask(i));
  }

  return *this;
}

BitArray& BitArray::operator>>=(int n) {
  if( !n ) {
    return *this;
  }
  for( size_t i = _cur_size - 1; i >= n; i-- ) {
    _array[i / k_type_size] &= (~mask(i));
    unsigned char bit = (mask(i - n) & _array[(i - n) / k_type_size]);
    bit = (i % k_type_size <= (i - n) % k_type_size)
                ? bit << ((i % k_type_size) - ((i - n) % k_type_size))
                : bit >> (((i - n) % k_type_size) - (i % k_type_size));
    _array[i / k_type_size] |= bit;
    _array[i / k_type_size] |= mask(i) & _array[i / k_type_size];
  }
  for( size_t i = 0; i < n; i++ ) {
    _array[i / k_type_size] &= (~mask(i));
  }
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

BitArray& BitArray::set(size_t n, bool val) {
  if( n > _cur_size )
    throw std::bad_array_new_length();
  if( val )
    _array[n / k_type_size] |= mask(n);
  else
    _array[n / k_type_size] &= ~mask(n);
  return *this;
}

BitArray& BitArray::set() {
  for( size_t i = 0; i < _capacity / k_type_size; ++i ) {
    _array[i] = k_full_true;
  }
  return *this;
}

BitArray& BitArray::reset(int n) {
  if( n > _cur_size )
    throw std::bad_array_new_length();
  set(n, false);
  return *this;
}

BitArray& BitArray::reset() {
  for( size_t i = 0; i < _capacity / k_type_size; ++i ) {
    _array[i] = 0;
  }
  return *this;
}

bool BitArray::any() const {
  for( size_t i = 0; i < _capacity / k_type_size; ++i ) {
    if( _array[i] != 0 ) {
      return true;
    }
  }
  return false;
}

bool BitArray::none() const {
  return !any();
}

BitArray BitArray::operator~() const {
  for( size_t i = 0; i < _capacity / k_type_size; ++i ) {
    _array[i] = ~_array[i];
  }
  return *this;
}

size_t BitArray::count() const {
  size_t counter = 0;
  for( size_t i = 0; i != _capacity / k_type_size; ++i ) {
    if( (_array[i / k_type_size] & mask(i % k_type_size)) != 0 )
      counter++;
  }
  return counter;
}

bool BitArray::operator[](size_t i) const {
  if( i > _cur_size )
    throw std::bad_array_new_length();
  return (mask(i) & _array[i / 8]) != 0;
}

size_t BitArray::size() const {
  return (int)_cur_size;
}

bool BitArray::empty() const {
  if( _cur_size == 0 )
    return true;
  return false;
}

std::string BitArray::to_string() const {
  std::string str;
  for( size_t i = 0; i < _capacity; ++i ) {
    if( _array[i / k_type_size] & mask(i % k_type_size) )
      str.push_back('1');
    else
      str.push_back('0');
  }

  return str;
}

bool operator==(const BitArray& a, const BitArray& b) {
  return (a._array == b._array);
}

bool operator!=(const BitArray& a, const BitArray& b) {
  return !(a == b);
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
  BitArray tmp(b1);
  return tmp &= b2;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
  BitArray tmp(b1);
  return tmp |= b2;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
  BitArray tmp(b1);
  return tmp ^= b2;
}