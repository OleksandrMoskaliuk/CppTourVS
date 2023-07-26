#include "UniformInit.h"
#include <iostream>

namespace uniformInit 
{
/*
Aggregate can
have a default constructor and/or a copy constructor as long as they are
implicitly declared by the compiler, and not explicitly by the user

An aggregate class can have a user-declared/user-defined copy-assignment
operator and/or destructor

An array is an aggregate even if it is an array of non-aggregate class type.
*/

 class Aggregate01 
 {
 public:
  Aggregate01(){};
  Aggregate01(int b, int c) : b(b), c(c) {};
  virtual void do_it(){};
  virtual void print() 
  {
    std::cout << "a = " << a << std::endl << " b = " << b << std::endl;
  }
 private:
  int b;
  int c;
  static int a;
 };

 int Aggregate01::a = 0;

 void example8() 
 { 
  Aggregate01 s = {10,11};
  s.print();

 }

}