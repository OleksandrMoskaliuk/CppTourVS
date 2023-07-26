#pragma once
#include <iostream>
#include <memory>
namespace circular_references 
{
void example(); 

class Node {
 public:
  std::shared_ptr<Node> next;

  Node() { std::cout << "Node constructor" << std::endl; }

  ~Node() { std::cout << "Node destructor" << std::endl; }
};


/*
In this updated version, we change the next member of the Node class to be of
type std::weak_ptr<Node2>. This indicates that the Node objects should have a
non-owning reference to the next object.

Using std::weak_ptr prevents the circular reference from keeping the objects
alive indefinitely. When all std::shared_ptr references to an object are gone,
the object will be deleted, and the std::weak_ptr references will automatically
become expired.
*/
class Node2 {
 public:
  //Fix memory leak 
  std::weak_ptr<Node2> next;

  Node2() { std::cout << "Node constructor" << std::endl; }

  ~Node2() { std::cout << "Node destructor" << std::endl; }
};



}