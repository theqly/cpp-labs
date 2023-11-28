#ifndef tuple_printing
#define tuple_printing

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
  T convert(const std::string& s) {
  std::stringstream buff(s);
  T value;
  buff >> value;
  return value;
}

template<typename... Args, size_t... Indices>
std::tuple<Args...> crutch(const std::vector<std::string>& v, std::index_sequence<Indices...>) {
  auto tmp = std::make_tuple(convert<Args>(v[Indices])...);
  return tmp;
}

template<typename... Args>
std::tuple<Args...> getResultCVSTuple(
        const std::vector<std::string>& v) {
  return crutch<Args...>(v, std::make_index_sequence<sizeof...(Args)>{});
}

#endif //tuple_printing
