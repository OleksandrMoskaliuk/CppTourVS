// Program to demonstrate init if-else
// feature introduced in C++17
#include "If_switch_initializers.h"

#include <cstdlib>
#include <iostream>

namespace if_switch_init {

void example() {
  using namespace std;
  // Set up rand function to be used
  // later in program
  srand(time(NULL));

  // Before C++17
  int i = 2;
  if (i % 2 == 0) cout << i << " is even number" << endl;

  // After C++17
  // if(init-statement; condition)
  if (int i = 4; i % 2 == 0) cout << i << " is even number" << endl;

  // Switch statement
  // switch(init;variable)
  switch (int i = rand() % 100; i) {
    default:
      cout << "i = " << i << endl;
      break;
  }
}

}  // namespace if_switch_init