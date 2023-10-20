#ifndef LAB1
#define LAB1

#include <string>

#define type_size 8

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

 private:
  const int resizing_rate = 2;

  size_t _capacity;
  size_t _cur_size;

  unsigned char* _array;

  static unsigned char mask(size_t pos){
    unsigned char one = 1;
    return one << (7 - (pos % type_size));
  };

};

#endif //LAB1
