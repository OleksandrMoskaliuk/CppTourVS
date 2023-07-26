#include "UniformInit.h"
#include <iostream>
/*
In C++, an aggregate is a type of class or struct that has no user-declared
constructors, no private or protected non-static data members, no base classes,
and no virtual functions. Aggregates are primarily used to group related data
together.
*/

namespace uniformInit 
{
 
 struct Point {
  int x;
  int y;
};

 void example() 
 {
  /*
  * Aggregates can be initialized using aggregate initialization syntax,
  which allows you to provide initial values for the data members using braces {}:
  */
  Point p = {10, 20};
  Point ps[] = {3, 4, 5};
  return;
 }
 struct X {
  X(){};
  X(int){};
 };

 void example1() 
 {
  /*
  Aggregates can also be designated as constexpr, allowing
  their initialization to be evaluated at compile-time:
  */
  constexpr Point p3 = {30, 40};  // Compile-time initialization
 }

 void example2() 
 {
  // uninitialized built-in type
  int i;

  // initialized built-in type
  int j = 10;

  // initialized built-in type
  int k(10);

  // Aggregate initialization
  int a[] = {1, 2, 3, 4};

  // default constructor
  X x1;

  // Parameterized constructor
  X x2(1);

  // Parameterized constructor with single argument
  X x3 = 3;

  // copy-constructor
  X x4 = x3; 


 // If initialized using brace initialization, the above code can be re-written as: 

 int i1{};  // initialized built-in type, equals to int i{0};

 int j1{10};  // initialized built-in type

 int a1[]{1, 2, 3, 4};  // Aggregate initialization

 X x11{};  // default constructor

 X x21{1};  // Parameterized constructor;

 X x41{x3};  // copy-constructor
 }

 void example3() 
 {
 // C++ program to demonstrate initialization
 // of dynamic array in C++ using uniform initialization
 const int array_size = 3;
 int* p_arr = new int[array_size] {1, 3, 34};

 for (int i = 0; i < array_size; i++) {
   std::cout << *p_arr;
 }

 }

 // Initialization of an array data member of a class:
 // an array data member of a class
 // with uniform initialization
 class A {
 int arr[3];

public:
 // initializing array using
 // uniform initialization
 A(int x, int y, int z) : arr{x, y, z} {};

 void show() {
   // printing the contents of the array
   for (int i = 0; i < 3; i++) std::cout << *(arr + i) << " ";
 }
 };

 void example4() 
 {
 A a(1, 2, 3);
 a.show();
 }



}