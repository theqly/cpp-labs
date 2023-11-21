#ifndef LAB5
#define LAB5
#include <tuple_printing.h>
#include <fstream>
#include <tuple>

template<typename... Args>
class CVSParser {
  public:
  class InputIterator {
    public:
    using reference = std::tuple<Args...>&;
    using pointer = std::tuple<Args...>*;

    InputIterator(CVSParser& parser, const size_t index) : _parser(parser) , _index(index){
    }
    reference operator*();
    InputIterator& operator++();

    bool operator==(const InputIterator& other);
    bool operator!=(const InputIterator& other);

    private:
    std::string read_row();
    CVSParser _parser;
    size_t _index;
    std::tuple<Args...> _tuple;
  };

  explicit CVSParser(std::ifstream& stream, const size_t skip_lines = 0) : _stream(stream), _skip_lines(skip_lines) {
    if(!stream.is_open()) {
      throw std::ifstream::failure("no input file");
    }
  }

  InputIterator begin();

  InputIterator end();

  private:
  std::ifstream& _stream;
  size_t _skip_lines;
};

#endif //LAB5
