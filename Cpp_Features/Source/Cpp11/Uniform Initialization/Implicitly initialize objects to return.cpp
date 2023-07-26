#include "UniformInit.h"
#include <iostream>

namespace uniformInit 
{

 // declaring a class 'A'
class A {
  // a and b are data members
  int a;
  int b;

  // constructor
 public:
  A(int x, int y) : a(x), b(y) {}
  void show() { std::cout << a << " " << b; }
};

A f(int a, int b) {
  // The compiler automatically
  // deduces that the constructor
  // of the class A needs to be called
  // and the function parameters of f are
  // needed to be passed here
  return {a, b};
}

 void example5() 
 {
  A x = f(1, 2);
  x.show();
 }


}