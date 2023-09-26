#include "handler.h"
#include "word.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

namespace handler{

  bool operator>(word::word& a, word::word& b){
    return a.getFrequency() > b.getFrequency();
  }

  handler::handler(const string& file_in, const string& file_out) {
    fin = ifstream(file_in);
    fout = ofstream(file_out);
    if(!fin || !fout){
      std::cout << "error with files" << std::endl;
      //what i need to do?
    }
  }

  void handler::reading(unordered_map<std::string, int> &mp) {
    string line;
    while(getline(fin, line)){
      string word;
      for(char i : line){
        if(i != ',') {
          word.push_back(i);
          continue;
        } else {
          mp[word]++;
          word.clear();
        }
      }
      mp[word]++;
    }
  }

  void handler::writing(const unordered_map<std::string, int> &mp) {
    vector<word::word> vec;
    vec.reserve(mp.size());
    int nwords = 0;
    for(const auto& item : mp){
      nwords += item.second;
      vec.emplace_back(item.first, item.second);
    }
    sort(vec.begin(), vec.end(), operator>);
    for(auto item : vec){
      fout << item.getContext() << "," << item.getFrequency() <<"," << float(item.getFrequency()) / nwords * 100 << "%" << std::endl;
    }
  }

}
