#include "SharedPtr.h"
#include <iostream>

namespace shared_pointers 
{

 /*
 Shared pointers provide several benefits over raw pointers, including:

1. Automatic memory management: Shared pointers automatically release the memory when it is no longer referenced, preventing memory leaks.

2. Shared ownership: Multiple shared pointers can point to the same object, and the object will be deleted only when all shared pointers are destroyed or reset.

3. Reference counting: Shared pointers internally maintain a reference count to keep track of the number of shared pointers pointing to the object. This allows them to manage the object's lifetime correctly.

4. Exception safety: Shared pointers provide exception safety by ensuring that the object is properly deleted even if an exception is thrown.
 */
void example() 
{
  // Create a shared pointer to an integer
  SharedPtr<int> sharedPtr1(new int(42));

  // Copy the shared pointer
  SharedPtr<int> sharedPtr2 = sharedPtr1;

  // Check the reference counts
  std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << std::endl;
  std::cout << "sharedPtr2 use count: " << sharedPtr2.use_count() << std::endl;

  // Use the shared pointers
  std::cout << "Value of sharedPtr1: " << *sharedPtr1 << std::endl;
  std::cout << "Value of sharedPtr2: " << *sharedPtr2 << std::endl;

  // Release the shared pointers
  sharedPtr1.reset();
  sharedPtr2.reset();
}

}