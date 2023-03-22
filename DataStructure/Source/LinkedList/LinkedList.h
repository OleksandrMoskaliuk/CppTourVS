#pragma once
#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>
/// <summary>
/*
 Advantages :
 Dynamic size: Unlike arrays, lists can grow or shrink dynamically during
 runtime, making them more flexible. Constant time insertion and removal:
 Elements can be added or removed from the list in constant time, regardless of
 their position in the list. Efficient memory management: Lists use memory more
 efficiently than arrays because they allocate memory in small blocks as needed,
 rather than in a single large block. Iteration: Lists can be iterated through
 efficiently using iterators or range-based for loops. Disadvantages: Random
 access: Unlike arrays, elements in a list cannot be accessed randomly. Instead,
 elements must be accessed sequentially. Slow traversal: Because elements in a
 list are not stored in contiguous memory, accessing elements in a list can be
 slower than accessing elements in an array. Overhead: Lists have some overhead
 associated with their implementation, such as the memory required for storing
 pointers to each element and the cost of dynamic memory // allocation.
*/
/// </summary>
namespace LinkedList {

void Test(int& argc, char* argv[]);

template <typename Data>
class List {
  /// <summary>
  /// Internal Node class, assigned to hold data
  /// </summary>
  /// <typeparam name="Data"></typeparam>
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

 private:
  Node<Data>* head;
  int size_m;

 public:
  /// <summary>
  /// Default constructor
  /// </summary>
  List();
  /// <summary>
  /// Parametrized constructor
  /// </summary>
  List(Data data);
  /// <summary>
  /// Copy constructor
  /// </summary>
  /// <param name="data"></param>
  List(const List& lst);
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

// Generate template clases for basic types of data
template class List<int>;
template class List<float>;
template class List<double>;
template class List<char>;


}  // namespace LinkedList

#endif  // MY_LIST_H
