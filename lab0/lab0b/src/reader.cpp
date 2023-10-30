#include "reader.h"
#include "word.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

namespace reader{

  reader::reader(const string& file_in) {
    fin = ifstream(file_in);
    if(!fin){
      std::cout << "error with files" << std::endl;
    }
  }

  void reader::reading() {
    string line;
    while(getline(fin, line)){
      string word;
      for(char i : line){
        if(isalnum(i)) {
          word.push_back(i);
          continue;
        } else {

          stat[word]++;
          word.clear();
        }
      }
      stat[word]++;
    }
  }

}
