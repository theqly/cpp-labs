#include "reader.h"
#include "writer.h"
#include "word.h"

int main(int argc, char** argv){
  string in = string(argv[1]);
  string out = string(argv[2]);
  reader::reader rdr(in);
  writer::writer wrt(out);
  rdr.reading();
  wrt.writing(rdr.getStat());
  return 0;
}