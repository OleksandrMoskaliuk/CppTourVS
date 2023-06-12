#include "SmartPointers.h"

#include <iostream>
#include <memory>
namespace smart_pointers {
TestEntity::TestEntity() {
  std::cout << " TestEntity constructor " << std::endl;
}

TestEntity::~TestEntity() {
  std::cout << " TestEntity destructor " << std::endl;
}

void TestEntity::DoWork() { std::cout << " TestEntity Do work " << std::endl; }

void example() {
  {
    // unique_ptr has no copy assignment operator and copy constructor
    std::unique_ptr<TestEntity> TE = std::make_unique<TestEntity>();
    TE->DoWork();
  }

  // Scope 1
  // Shared pointer can hold data and share with multiple pointers
  // data will be save until last poiter die
  {
    std::shared_ptr<TestEntity> SharedTE = std::make_shared<TestEntity>();
    // Scope 2
    {
      // At the end of scope 2 AnotherSharedTE wil not erese data because we
      // have backup at scope 1
      std::shared_ptr<TestEntity> AnotherSharedTE = SharedTE;
      // Weak ptr will not be takken into account so ref counter will not be
      // increased.
      std::weak_ptr do_smth = AnotherSharedTE;
    }
  }
  // Decrease last ref count and erase data in SharedTE

}

}  // namespace smart_pointers