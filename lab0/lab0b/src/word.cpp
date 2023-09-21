#include "word.h"

#include <utility>

word::word(string str, int freq) {
  context = str;
  frequency = freq;
}

string word::getContext() {
  return context;
}

int word::getFrequency() {
  return frequency;
}

