// C++ program to demonstrate use of decltype
#include <iostream>
#include "Type inference.h"

/*
 decltype Keyword: It inspects the declared type of an entity or the type of an
 expression. ‘auto’ lets you declare a variable with a particular type whereas
 decltype lets you extract the type from the variable so decltype is sort of an
 operator that evaluates the type of passed expression.
*/

namespace type_inference {

using namespace std;

// Driver Code
int example2() {
  int x = 5;

  // j will be of type int : data type of x
  decltype(x) j = x + 5;

  cout << typeid(j).name();

  return 0;
}

int func1() { return int(); }
float func2() { return float(); }
 void example3() {
  // Data type of x is same as return type of fun1()
  // and type of y is same as return type of fun2()
  decltype(func1()) x;
  decltype(func2()) y;

  cout << typeid(x).name() << endl;
  cout << typeid(y).name() << endl;
 
 }


 // A generic function which finds minimum of two values
 // return type is type of variable which is minimum
 template <class A, class B>
 auto findMin(A a, B b) -> decltype(a < b ? a : b) {
  return (a < b) ? a : b;
 }

 // driver function to test various inference
 int example4() {
  // This call returns 3.44 of double type
  cout << findMin(4, 3.44) << endl;

  // This call returns 3 of double type
  cout << findMin(5.4, 3) << endl;

  return 0;
 }

}  // namespace type_inference