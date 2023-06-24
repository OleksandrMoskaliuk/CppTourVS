//C++11:
//
//Lambda expressions
//Range-based for loops
//Move semantics
//Smart pointers
//constexpr keyword
//Variadic templates
//Uniform initialization syntax
//Type inference using auto keyword
//nullptr keyword
//Delegating constructors
//Lambda expression:
//
//C++14:
//
//Generic lambdas
//Return type deduction for functions
//Binary literals
//Variable templates
//Digit separators
//decltype(auto) keyword
//Polymorphic lambdas
//Generic lambda
//
//C++ 20 :
//
//    Concepts Ranges library Coroutines Modules Three -
//    way comparison operator std::span type std::format function
//        std::stop_token type Synchronized output streams Example of concepts :
//
//    template <typename T>
//    concept Integral = std::is_integral_v<T>;
//
//template <Integral T>
//T add(T x, T y) {
//  return x + y;
//}
//
//int result1 = add(3, 4);         // result1 is 7
//double result2 = add(3.5, 4.2);  // error: double is not an Integral type

//#include "Cpp11 Smart Pointers/WeakPointer.h"
#include "Cpp11 Uniform Initialization/UniformInit.h"

int main() 
{ 
  uniformInit::example8();
 return 0;
}