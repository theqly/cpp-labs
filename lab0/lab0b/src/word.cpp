#include "word.h"

namespace word{
  word::word(const string* str, int freq) {
    context = str;
    frequency = freq;
  }

  string word::getContext() const {
    return *context;
  }

  int word::getFrequency() const {
    return frequency;
  }
}


