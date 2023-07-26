#include "VariadicTemplates.h"

namespace variadic_templates 
{

 int Sum() 
 { 
  return 0;
 } 
  
  template <typename T, typename... Params>
float Sum(const T& arg, const Params&... args) 
{
   return arg + Sum(args...);
}
  
void example1() 
{
 std::cout << Sum(10, 22, 34, 56);
}

 void example2() 
 { 

  // Tuple custom class trying out
  Tuple<int, char,float > tp(10,'c',12.5f);
  tp.print();

  // Trying out ostream console out operator owerload
  std::tuple myTuple{25, "Hello", 9.31f, 'c'};
  std::cout << myTuple << '\n';

 }



 template <typename T>
 T bar(T t) { /*...*/
  return T();
 }

 template <typename... Args>
 void foo(Args... args) {
  //...
 }

 template <typename... Args>
 void foo2(Args... args) {
  foo(bar(args)...);
 }


 template <typename T, typename... S>
 void ex3(T t, S... s)
 {

  std::tuple tp {s...};
  std::cout << *std::get<0>(tp);
 /* std::apply(
      [](auto&&... xs) {
        [](...) {}(([](auto&& x) { std::cout << x << "\n"; }(
                        std::forward<decltype(xs)>(xs)),
                    false)...);
      },
      std::make_tuple());*/
 };

 void example3() { 

  //ex3('a', 1, 2.f);
  foo2("ac", 1, 2.4f);
 }
 
}