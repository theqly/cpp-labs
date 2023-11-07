#ifndef LAB1
#define LAB1

#include <string>

class BitArray {
 private:
  const int resizing_rate = 2;

  size_t _capacity;
  size_t _cur_size;

  unsigned char *_array;

 public:
  class Iterator {
   public:
    Iterator(BitArray* tmp, size_t index);
    Iterator& operator=(const Iterator& other) = default;
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
    bool operator==(bool bit) const;
    bool operator!=(bool bit) const;
    Iterator& operator++();
    Iterator& operator=(const bool& bit);
    Iterator& operator*();

   private:
    BitArray *_bit_array;
    size_t _cur_index;
  };

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
  Iterator operator[](int i);

  [[nodiscard]] int size() const;
  [[nodiscard]] bool empty() const;

  [[nodiscard]] std::string to_string() const;

  friend bool operator==(const BitArray& a, const BitArray& b);
  friend bool operator!=(const BitArray& a, const BitArray& b);

  friend BitArray operator&(const BitArray& b1, const BitArray& b2);
  friend BitArray operator|(const BitArray& b1, const BitArray& b2);
  friend BitArray operator^(const BitArray& b1, const BitArray& b2);


  [[nodiscard]] Iterator begin();

  [[nodiscard]] Iterator end();
};


#endif// LAB1
