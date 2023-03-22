#pragma once
#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>
/// <summary>
/* 
 Advantages :
 Dynamic size: Unlike arrays, lists can grow or shrink dynamically during runtime, making them more flexible.
 Constant time insertion and removal: Elements can be added or removed from the list in constant time, regardless of their position in the list.
 Efficient memory management: Lists use memory more efficiently than arrays because they allocate memory in small blocks as needed, rather than in a single large block.
 Iteration: Lists can be iterated through efficiently using iterators or range-based for loops.
 Disadvantages:
 Random access: Unlike arrays, elements in a list cannot be accessed randomly. Instead, elements must be accessed sequentially.
 Slow traversal: Because elements in a list are not stored in contiguous memory, accessing elements in a list can be slower than accessing elements in an array.
 Overhead: Lists have some overhead associated with their implementation, such as the memory required for storing pointers to each element and the cost of dynamic memory // allocation.
*/
/// </summary>
namespace LinkedList {

void Test(int& argc, char* argv[]);

 namespace my_Node {

template <typename Data>
class Node {
 public:
  Data data;
  Node<Data>* p_next;
  Node(Data data = Data(), Node<Data>* p_next = nullptr) {
    this->data = data;
    this->p_next = p_next;
  };
};

template <typename Data>
class TwoWayNode {
 public:
  Data data;
  TwoWayNode<Data>* p_next;
  TwoWayNode<Data>* p_prev;
  TwoWayNode<Data>* node_adress;
 public:
  TwoWayNode(Data data = Data(), TwoWayNode<Data>* p_prev = nullptr,
             TwoWayNode<Data>* p_next = nullptr)
      : data(data), p_prev(p_prev), p_next(p_next), node_adress(this) {};
};
}  // namespace my_Node


template <typename Data>
class List {
 private:
  my_Node::Node<Data>* head;
  int size_m;

 public:
  List();
  List(Data data);
  ~List();

 public:
  int get_size();
  void push_front(Data dt);
  void push_back(Data dt);
  void insert(int index, Data dt);
  Data& operator[](int index);
  void pop_front();
  void pop_back();
  void remove(int index);
  void clean();
};

template <typename Data>
inline List<Data>::List() : head(nullptr), size_m(0) {}

template <typename Data>
inline List<Data>::List(Data data) {
  this->head = new my_Node::Node<Data>(data);
  this->head->p_next = nullptr;
  size_m = 1;
}

template <typename Data>
inline List<Data>::~List() {
  this->clean();
}

template <typename Data>
inline int List<Data>::get_size() {
  return this->size_m;
}

template <typename Data>
inline void List<Data>::push_front(Data dt) {
  if (this->head == nullptr) {
    this->head = new my_Node::Node<Data>(dt);
    ++size_m;
    return;
  }
  my_Node::Node<Data>* next = this->head;
  this->head = new my_Node::Node<Data>(dt, next);
  ++size_m++;
}

template <typename Data>
inline void List<Data>::push_back(Data dt) {
  // check if we already have first element
  if (this->head == nullptr) {
    this->head = new my_Node::Node<Data>(dt);
    size_m++;
    return;
  }
  my_Node::Node<Data>* current = this->head;
  while (current->p_next != nullptr) current = current->p_next;
  current->p_next = new my_Node::Node<Data>(dt);
  size_m++;
}

template <typename Data>
inline void List<Data>::insert(int index, Data dt) {
  if (index <= 0) {
    this->push_front(dt);
    return;
  }
  if (index >= size_m) {
    this->push_back(dt);
    return;
  }
  my_Node::Node<Data>* previous = this->head;
  my_Node::Node<Data>* current = previous->p_next;
  for (size_t i = 0; i < index - 1; i++) {
    previous = current;
    current = current->p_next;
  }
  previous->p_next = new my_Node::Node<Data>(dt, current);
  size_m++;
}

template <typename Data>
inline Data& List<Data>::operator[](int index) {
  if (size_m == 0) {
    Data exception = Data();
    return exception;
  }
  if (index > size_m) index = size_m;
  if (index < 0) index = 0;
  my_Node::Node<Data>* current = this->head;
  for (size_t i = 0; i < index; i++) current = current->p_next;
  return current->data;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_front() {
  if (size_m == 0) return;
  my_Node::Node<Data>* to_delete = this->head;
  this->head = this->head->p_next;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_back() {
  if (size_m == 0) return;
  my_Node::Node<Data>* current = this->head;
  for (size_t i = 0; i < size_m - 1; i++) current = current->p_next;
  my_Node::Node<Data>* to_delete = current->p_next;
  current->p_next = nullptr;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void LinkedList::List<Data>::remove(int index) {
  if (index <= 0) {
    this->pop_front();
    return;
  }
  if (index >= size_m) {
    this->pop_back();
    return;
  }
  my_Node::Node<Data>* previous = this->head;
  my_Node::Node<Data>* to_delete = previous->p_next;
  for (size_t i = 0; i < index - 1; i++) {
    previous = to_delete;
    to_delete = to_delete->p_next;
  }
  my_Node::Node<Data>* buf = to_delete->p_next;
  delete to_delete;
  previous->p_next = buf;
  size_m--;
}

template <typename Data>
inline void List<Data>::clean() {
  while (this->head != nullptr) this->pop_front();
}

}  // namespace LinkedList

// void test_LinkedListasdfsavdsavcdsa() {
//   LinkedList::List<int> df;
//   df.push_back(10);
//   df.push_back(20);
//   df.push_back(30);
//   df.push_back(40);
//   df.push_back(50);
//   df.push_back(60);
//   for (int i = 0; i < df.get_size(); i++) {
//     std::cout << df[i] << "\n";
//   }
//
//   std::cout << "result:" << std::endl;
//   df.push_front(56);
//   df.push_front(522);
//   for (int i = 0; i < df.get_size(); i++) {
//     std::cout << df[i] << "\n";
//   }
//   // std::cout << df[0] <<"\n";
//   // std::cout << df[1] << "\n";
//   // std::cout << df[2] << "\n";
// }
#endif  // MY_LIST_H
