#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>

#include "Node.h"

namespace my_list {
// advantage:
//			fast add , remove, copy , move  operation;
// disadvantage:
//			long iteration time;

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
    size_m++;
    return;
  }
  my_Node::Node<Data>* next = this->head;
  this->head = new my_Node::Node<Data>(dt, next);
  size_m++;
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
inline void my_list::List<Data>::pop_front() {
  if (size_m == 0) return;
  my_Node::Node<Data>* to_delete = this->head;
  this->head = this->head->p_next;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void my_list::List<Data>::pop_back() {
  if (size_m == 0) return;
  my_Node::Node<Data>* current = this->head;
  for (size_t i = 0; i < size_m - 1; i++) current = current->p_next;
  my_Node::Node<Data>* to_delete = current->p_next;
  current->p_next = nullptr;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void my_list::List<Data>::remove(int index) {
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

}  // namespace my_list

#endif  // MY_LIST_H
