#include "word.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::unordered_map;
using std::vector;

bool operator<(word& a, word& b){
  return a.getFrequency() > b.getFrequency();
}

unordered_map<string, int> reading(ifstream& fin){
  unordered_map<string, int> mp;
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
  return mp;
}

void writing(ofstream& fout, const unordered_map<string, int>& mp){
  vector<word> vec;
  vec.reserve(mp.size());
  int nwords = 0;
  for(const auto& item : mp){
    nwords += item.second;
    vec.emplace_back(item.first, item.second);
  }
  sort(vec.begin(), vec.end());
  for(auto item : vec){
    fout << item.getContext() << "," << item.getFrequency() <<"," << float(item.getFrequency()) / nwords * 100 << "%" << std::endl;
  }
}

int main(int argc, char** argv){
  string in = string(argv[1]);
  string out = string(argv[2]);
  ifstream fin(in);
  ofstream fout(out);
  if(!fin || !fout){
    std::cout << "error with files" << std::endl;
    return 1;
  }
  unordered_map<string, int> mp = reading(fin);
  writing(fout, mp);
  return 0;
}