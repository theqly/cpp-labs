#include "word.h"

namespace word{
  word::word(string str, int freq) {
    context = str;
    frequency = freq;
  }

  string word::getContext() {
    return context;
  }

  int word::getFrequency() const {
    return frequency;
  }
}


