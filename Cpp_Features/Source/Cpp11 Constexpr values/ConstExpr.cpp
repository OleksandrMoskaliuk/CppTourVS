#include "ConstExpr.h"
#include <iostream>

namespace constexpr_values {
/*
constexpr is a keyword in C++ that is used to declare that a variable, function,
or expression can be evaluated at compile time. It stands for "constant
expression."

When a variable is declared as constexpr, its value must be computable at
compile time. This means that it must be initialized with a constant expression,
such as a literal or a result of a constexpr function. The value of a constexpr
variable is determined during compilation and cannot be modified at runtime.

Similarly, when a function is declared as constexpr, it means that the function
can be evaluated at compile time and used in constant expressions. The function
must meet certain criteria, such as having a return type that is a literal type
and having a body that consists of a single return statement or a sequence of
simple computations.

The constexpr keyword allows you to perform computations at compile time, which
can lead to improved performance and more efficient code. It also enables the
use of compile-time constants in various contexts, such as template arguments,
array sizes, and switch statements.

Here's an example of using constexpr to declare a compile-time constant
variable:

cpp
Copy code
constexpr int MaxValue = 100;
In this example, MaxValue is a compile-time constant with a value of 100. It can
be used in contexts that require constant expressions, such as array sizes or
template arguments.

Note that constexpr was introduced in C++11 and has been expanded and improved
in subsequent versions of the C++ standard.

*/

 constexpr int get_value(int val) 
 {
  // Is value calculated at compile time ?
  // Maybe, up to the compiler !
  return val * 2; 
 }

void example1() 
{
 constexpr int i = get_value(2);
 std::cout << i;
}

void example2() 
{
 {
 // constexpr are stack values (unless they are satic)!
 static constexpr int i = get_value(2);
 std::cout << i;
 }
}

}  // namespace constexpr_values