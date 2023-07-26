#include "UniformInit.h"
#include <iostream>


namespace uniformInit {

// C++ program to demonstrate how to
// initialize a function parameter
// using Uniform Initialization

// declaring a class 'A'
class A {
  // a and b are data members
  int a;
  int b;

 public:
  A(int x, int y) : a(x), b(y) {}
  void show() { std::cout << a << " " << b; }
};

void f(A x) { x.show(); }

// Driver Code
void example6() {
  // calling function and initializing it's argument
  // using brace initialization
  f({1, 2});
}

}  // namespace uniformInit