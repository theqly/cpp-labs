#ifndef LAB1
#define LAB1

#include <string>


class BitArrayIterator {
 public:
  BitArrayIterator(unsigned char* ptr, size_t current_bit = 0);

 private:
  unsigned char* _m_ptr;
  size_t _current_bit;
};

class BitArray
{
 public:
  BitArray();
  ~BitArray();

  explicit BitArray(int num_bits, unsigned char value = 0);
  BitArray(const BitArray& b);

  void swap(BitArray& b);

  BitArray& operator=(const BitArray& b);

  void resize(int num_bits);

  void clear();

  void push_back(bool bit);

  BitArray& operator&=(const BitArray& b);
  BitArray& operator|=(const BitArray& b);
  BitArray& operator^=(const BitArray& b);

  BitArray& operator<<=(int n);
  BitArray& operator>>=(int n);
  BitArray operator<<(int n) const;
  BitArray operator>>(int n) const;

  BitArray& set(int n, bool val = true);

  BitArray& set();

  BitArray& reset(int n);

  BitArray& reset();

  [[nodiscard]] bool any() const;

  [[nodiscard]] bool none() const;

  BitArray operator~() const;

  [[nodiscard]] int count() const;

  bool operator[](int i) const;

  [[nodiscard]] int size() const;
  [[nodiscard]] bool empty() const;

  [[nodiscard]] std::string to_string() const;

  friend bool operator==(const BitArray & a, const BitArray & b);
  friend bool operator!=(const BitArray & a, const BitArray & b);

  friend BitArray operator&(const BitArray& b1, const BitArray& b2);
  friend BitArray operator|(const BitArray& b1, const BitArray& b2);
  friend BitArray operator^(const BitArray& b1, const BitArray& b2);


  [[nodiscard]] BitArrayIterator begin() const;

  [[nodiscard]] BitArrayIterator end() const;

 private:

  const int resizing_rate = 2;

  size_t _capacity;
  size_t _cur_size;

  unsigned char* _array;

};


#endif //LAB1
