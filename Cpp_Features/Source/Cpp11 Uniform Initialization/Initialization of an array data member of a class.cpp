#include "UniformInit.h"
#include <iostream>


namespace uniformInit 
{
// C++ program to initialize
//  an array data member of a class
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

// Driver Code
void example7() {
  // New object created and the numbers
  // to initialize the array with, are passed
  // into it as arguments
  A a(1, 2, 3);
  a.show();
}

}