#ifndef lab0b
#define lab0b

#include <string>

using std::string;

class word{

 public:
  word(string str, int freq);

  string getContext();
  int getFrequency();

 private:
  string context;
  int frequency;

};

#endif //lab0b
