#include "handler.h"
#include "word.h"

int main(int argc, char** argv){
  string in = string(argv[1]);
  string out = string(argv[2]);
  handler::handler hndl(in, out);

  unordered_map<string, int> mp;
  hndl.reading(mp);
  hndl.writing(mp);
  return 0;
}