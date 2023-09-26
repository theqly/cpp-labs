#pragma once

#include <string>

using std::string;

namespace word {
  class word {

   public:
    word(string str, int freq);

    string getContext();
    int getFrequency() const;

   private:
    string context;
    int frequency;

  };
}
