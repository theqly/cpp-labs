#pragma once

#include "word.h"

#include <fstream>
#include <unordered_map>
#include <string>

using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::string;

namespace handler{
  class handler{

   public:
    handler(const string& fin, const string& fout);

    void reading(unordered_map<string, int>& mp);
    void writing(const unordered_map<string, int>& mp);

    friend bool operator>(word::word& a, word::word& b);

   private:
    ifstream fin;
    ofstream fout;

  };
}

