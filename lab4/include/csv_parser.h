#ifndef LAB5
#define LAB5
#include <tuple_utility.h>
#include <fstream>
#include <limits>
#include <memory>
#include <tuple>

template<typename... Args>
class CVSParser {
  public:
  class InputIterator {
    public:
    using reference = std::tuple<Args...>&;
    using pointer = std::shared_ptr<std::tuple<Args...>>;

    InputIterator(CVSParser& parser, const bool is_ended) : _is_ended(is_ended), _parser(parser) {
      if(is_ended) _tuple = nullptr;
      else put_in_tuple();
    }

    reference operator*() {
      return *_tuple;
    }

    InputIterator operator++() {
      InputIterator tmp = *this;
      put_in_tuple();
      return tmp;
    }

    bool operator==(const InputIterator& other) {
      return _tuple == other._tuple;
    }
    bool operator!=(const InputIterator& other) {
      return _tuple != other._tuple;
    }

    private:
    bool _is_ended;
    CVSParser& _parser;
    pointer _tuple;

    std::string read_row() {
      std::string row;
      std::getline(_parser._stream, row);
      ++_parser._cur_line;
      return row;
    }

    std::vector<std::string> get_data(const std::string& row) {
      std::vector<std::string> data;
      std::string elem;
      for(const char& symbol : row) {
        if(symbol =='\"') {
          _is_ended = true;
          break;
        }
        if(symbol == '\n') break;
        if(symbol == ',') {
          data.push_back(elem);
          elem.clear();
          continue;
        }
        elem.push_back(symbol);
      }
      if(!elem.empty()) data.push_back(elem);
      return data;
    }

    void put_in_tuple() {
      const std::string row = read_row();
      if(row.empty()) {
        _tuple = nullptr;
        _is_ended = true;
      }
      else {
        auto tmp = create_tuple<Args...>(get_data(row));
        _tuple = std::make_shared<std::tuple<Args...>>(tmp);
      }
    }
  };

  explicit CVSParser(std::ifstream& stream, const size_t skip_lines = 0) : _stream(stream), _cur_line(0), _skip_lines(skip_lines) {
    if(!stream.is_open()) {
      throw std::ifstream::failure("no input file");
    }
  }

  InputIterator begin() {
    skip_lines();
    return InputIterator(*this, false);
  }

  InputIterator end() {
    return InputIterator(*this, true);
  }

  private:
  std::ifstream& _stream;
  size_t _cur_line;
  size_t _skip_lines;

  void skip_lines() {
    for(size_t i = 0; i < _skip_lines; ++i) {
      if(!_stream.ignore(std::numeric_limits<std::streamsize>::max(), _stream.widen('\n'))) {
        throw std::exception();
      }
    }
  }
};

#endif //LAB5
