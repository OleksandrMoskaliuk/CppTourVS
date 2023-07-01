#include "CircularReferences.h"
/*
 Circular references can occur when two or more objects reference each other
 using shared pointers. This can lead to a situation where the reference count
 of each object never reaches zero, resulting in a memory leak because the
 objects are never deleted.
*/
namespace circular_references {
 // This code causes memory leak
void example() {
  std::shared_ptr<Node> node1 = std::make_shared<Node>();
  std::shared_ptr<Node> node2 = std::make_shared<Node>();

  node1->next = node2;
  node2->next = node1;
}

void example1() {

  std::shared_ptr<Node2> node1 = std::make_shared<Node2>();
  std::shared_ptr<Node2> node2 = std::make_shared<Node2>();

  node1->next = node2;
  node2->next = node1;

}
}  // namespace circular_references