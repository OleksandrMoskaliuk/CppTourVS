/*
Arrays - a collection of elements of the same type, stored in contiguous memory
locations.

Linked lists - a data structure consisting of a sequence of nodes, where each
node contains a value and a reference to the next node.

Stacks - a data structure that follows the Last-In-First-Out (LIFO) principle,
where the last element added to the stack is the first one to be removed.

Queues - a data structure that follows the First-In-First-Out (FIFO) principle,
where the first element added to the queue is the first one to be removed.

Trees - a data structure consisting of nodes linked by edges, where each node
has zero or more child nodes.

Hash tables - a data structure that maps keys to values using a hash function to
compute an index into an array of buckets or slots.
*/

#include <iostream>
#include <string>

// #include "TwoWayList/test/test.h"
#include "Array/Array.h"
#include "byte/byte.h"
#include "LinkedList/LinkedList.h"
#include "Stack/Stack.h"


int main(int argc, char* argv[]) {
  // Array::Test(argc, argv);
  // byte::Test(argc, argv);
  //LinkedList::Test(argc, argv);
  Stack::Test(argc, argv);
  
  

  

  return 0;
}
