#include "writer.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::ofstream;

namespace writer{

    writer::writer(const string &file_out) {
        fout = ofstream(file_out);
        if(!fout){
            std::cout << "error with files" << std::endl;
            //what i need to do?
        }
    }

    bool operator>(word::word& a, word::word& b){
        return a.getFrequency() > b.getFrequency();
    }

    void writer::writing(const unordered_map<string, int>& mp) {
        vector<word::word> vec;
        vec.reserve(mp.size());
        int nwords = 0;
        for(const auto& item : mp){
            nwords += item.second;
            word::word curword = word::word(&item.first, item.second);
            vec.push_back(curword);
        }
        sort(vec.begin(), vec.end(), operator>);
        for(auto item : vec){
            fout << item.getContext() << "," << item.getFrequency() <<"," << float(item.getFrequency()) / (float)nwords * 100 << "%" << std::endl;
        }
    }
}
