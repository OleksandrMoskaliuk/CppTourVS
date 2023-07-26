#include "WeakPointer.h"
#include "SharedPtr.h"
#include <iostream>

namespace weak_pointer {

class Resource {
 public:
  Resource() { std::cout << "Resource acquired" << std::endl; }

  ~Resource() { std::cout << "Resource released" << std::endl; }

  void doSomething() {
    std::cout << "Doing something with the resource" << std::endl;
  }
};

void example() {
  WeakPtr<Resource> weakPtr;

  {
    shared_pointers::SharedPtr<Resource> sharedPtr(new Resource());
    //weakPtr = sharedPtr;

    // Access the resource using shared_ptr
    //  if (auto lockedPtr = weakPtr.lock()) {
    //    lockedPtr->doSomething();
    //  } else {
    //    std::cout << "Resource has been released" << std::endl;
    //  }
    //}

    //// Attempt to access the resource again
    // if (auto lockedPtr = weakPtr.lock()) {
    //   lockedPtr->doSomething();
    // } else {
    //   std::cout << "Resource has been released" << std::endl;
    // }

    return;
  }
}

}  // namespace weak_pointer