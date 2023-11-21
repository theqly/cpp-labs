#ifndef tuple_printing
#define tuple_printing

#include <iostream>
#include <tuple>

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



#endif //tuple_printing
