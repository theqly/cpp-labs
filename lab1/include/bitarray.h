#ifndef LAB1
#define LAB1

#include <string>


class BitArray {
public:
  BitArray();
  ~BitArray();

  explicit BitArray(size_t num_bits, unsigned char value = 0);
  BitArray(const BitArray& b);

  void swap(BitArray& b);

  BitArray& operator=(const BitArray& b);

  void resize(size_t num_bits);

  void clear();

  void push_back(bool bit);

  BitArray& operator&=(const BitArray& b);
  BitArray& operator|=(const BitArray& b);
  BitArray& operator^=(const BitArray& b);

  BitArray& operator<<=(int n);
  BitArray& operator>>=(int n);
  BitArray operator<<(int n) const;
  BitArray operator>>(int n) const;

  BitArray& set(size_t n, bool val = true);

  BitArray& set();

  BitArray& reset(int n);

  BitArray& reset();

  [[nodiscard]] bool any() const;

  [[nodiscard]] bool none() const;

  BitArray operator~() const;

  [[nodiscard]] size_t count() const;

  bool operator[](size_t i) const;

  [[nodiscard]] size_t size() const;
  [[nodiscard]] bool empty() const;

  [[nodiscard]] std::string to_string() const;

  friend bool operator==(const BitArray& a, const BitArray& b);
  friend bool operator!=(const BitArray& a, const BitArray& b);

  friend BitArray operator&(const BitArray& b1, const BitArray& b2);
  friend BitArray operator|(const BitArray& b1, const BitArray& b2);
  friend BitArray operator^(const BitArray& b1, const BitArray& b2);

private:
  const int resizing_rate = 2;

  size_t _capacity;
  size_t _cur_size;

  unsigned char *_array;
};

#endif// LAB1
