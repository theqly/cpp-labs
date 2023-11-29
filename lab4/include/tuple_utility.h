#ifndef tuple_utility
#define tuple_utility
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

template <typename Ch, typename Tr, typename... Args>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& tp) {
  os << "(";
  std::apply([&os](const auto& first, const auto& ... rest) {
    auto printElem = [&os](const auto& x) {
      os << ", " << x;
    };
    os << first;
    (printElem(rest), ...);
  }, tp);
  os << ")";
  return os;
}

template<typename T>
  T type_conversion(const std::string& str) {
  std::stringstream tmp(str);
  T value;
  tmp >> value;
  return value;
}

template<typename... Args, size_t... Indices>
std::tuple<Args...> unite(const std::vector<std::string>& vec, std::index_sequence<Indices...>) {
  auto tmp = std::make_tuple(type_conversion<Args>(vec[Indices])...);
  return tmp;
}

template<typename... Args>
std::tuple<Args...> create_tuple(const std::vector<std::string>& str) {
  return unite<Args...>(str, std::make_index_sequence<sizeof...(Args)>{});
}

#endif //tuple_utility
