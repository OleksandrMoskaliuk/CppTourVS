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
/*Concepts: Concepts are a way to specify requirements on template arguments. They allow you to define predicates that templates must satisfy, improving template error messages and enabling more explicit and precise template constraints.

Ranges: Ranges provide a new library for working with sequences of elements. The ranges library introduces new range-based algorithms and range adaptors, making it easier to write concise and expressive code when working with collections of data.

Coroutines: Coroutines allow for the creation of lightweight concurrent or asynchronous code. They provide a new way to write functions that can be suspended and resumed, enabling more readable and efficient asynchronous programming.

Modules: Modules are a new way to organize and manage C++ code. They improve build times by providing a more efficient alternative to include files, and they enable faster compilation and better separation of implementation details.

Three-Way Comparisons (Spaceship Operator): C++20 introduces the "spaceship" operator (<=>), which enables concise and efficient three-way comparisons between objects. It simplifies the implementation of comparison operations and provides a standard way to define ordering for user-defined types.

Calendar and Time Zone: C++20 introduces new library components for working with calendars, time zones, and date/time calculations. The <chrono> library now includes support for calendrical calculations and time zone conversions, making it easier to work with dates and times.

Improved constexpr: C++20 enhances the capabilities of constexpr, allowing it to be used in more contexts. constexpr functions can now have non-void return types, and loops and conditionals are more broadly supported, enabling more compile-time evaluation and optimization.

Lambdas in Unevaluated Contexts: C++20 allows lambdas to appear in unevaluated contexts, such as within decltype expressions or type traits. This enables more concise and expressive code in template metaprogramming.*/

//#include "Cpp11 Smart Pointers/WeakPointer.h"
//#include "Cpp11 Uniform Initialization/UniformInit.h"

#include "Cpp11 Type inference using auto keyword/Type inference.h"
#include "Cpp11 Smart Pointers/SharedPtr.h"

#include <iostream>
#include <functional>

int main() 
{ 
 using namespace std;

  int i = 3;
  int j = 5;

  // The following lambda expression captures i by value and
  // j by reference.
  auto f = [i, &j] { return (i + j); };

  // Change the values of i and j.
  i = 22;
  j = 44;

  // Call f and print its result.
  cout << f() << endl;

 return 0;
}