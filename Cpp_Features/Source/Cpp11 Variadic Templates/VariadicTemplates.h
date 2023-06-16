#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

namespace variadic_templates 
{

void example1();
void example2();
void example3();


template <typename... Args>
class Tuple {
 private:
  std::tuple<Args...> values;

  static void printValues(Args... args) {
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
  }

  void callVariadicFunctionWithTuple(const std::tuple<Args...>& tuple) {
    std::apply([](auto... args) { printValues(args...); }, tuple);
  }

 public:

  Tuple(const Args&... args) : values{args...} {}

  void print() {
    //std::tuple values = this->values;
    callVariadicFunctionWithTuple(values);
    std::cout << std::endl;
  }
};


// ostream operator overload to console out tuple with different arguments
template <typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& theTuple) {
  std::apply(
      [&os](Ts const&... tupleArgs) {
        os << '[';
        std::size_t n{0};
        ((os << tupleArgs << (++n != sizeof...(Ts) ? ", " : "")), ...);
        os << ']';
      },
      theTuple);
  return os;
}

} // namesapce variadic_templates
