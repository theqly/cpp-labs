#pragma once
#include "word.h"

#include <fstream>
#include <unordered_map>
#include <string>


using std::unordered_map;
using std::string;

namespace writer{
    class writer{
    public:

        explicit writer(const string& file_out);

        friend bool operator>(word::word& a, word::word& b);

        void writing(const unordered_map<string, int>& mp);

    private:
        std::ofstream fout;
    };

}