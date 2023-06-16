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

 /*template <typename Arg, typename... Args>
 void tst(Args&... args) 
 {
  concatenate(args);
  return;
 }*/


 void example3() { 

 }
 
}