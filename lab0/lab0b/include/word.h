#pragma once

#include <string>

using std::string;

namespace word {
  class word {

   public:
    word(const string* str, int freq);

    [[nodiscard]] string getContext() const;
    [[nodiscard]] int getFrequency() const;

   private:
    const string* context;
    int frequency;

  };
}
