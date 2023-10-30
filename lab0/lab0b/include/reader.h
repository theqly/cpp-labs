#pragma once

#include "word.h"

#include <fstream>
#include <unordered_map>
#include <string>

using std::ifstream;
using std::unordered_map;
using std::string;

namespace reader{
  class reader{

   public:
    explicit reader(const string& fin);

    const unordered_map<string, int>& getStat() const {
        return stat;
    }

    void reading();

   private:
    ifstream fin;
    unordered_map<string, int> stat;
  };
}

