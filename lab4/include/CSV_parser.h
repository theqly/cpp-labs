#ifndef LAB5
#define LAB5
#include <tuple_printing.h>
#include <fstream>
#include <tuple>

template<typename... Is>
class CVSParser {
  public:
  class InputIterator {
    public:
    InputIterator(CVSParser& parser) : _parser(parser){
    }
    private:
    CVSParser _parser;
    size_t _index;
    std::tuple<Is...> _tuple;
  };
  InputIterator begin() {
    return InputIterator(*this);
  }
  InputIterator end() {
    return InputIterator(*this);
  }

  explicit CVSParser(std::ifstream& stream, const size_t skip_lines) : _stream(stream){
    if(!stream.is_open()) {
      throw std::ifstream::failure("no input file");
    }
  }
  private:
  std::ifstream& _stream;
  size_t _skip_lines;
};

#endif //LAB5
