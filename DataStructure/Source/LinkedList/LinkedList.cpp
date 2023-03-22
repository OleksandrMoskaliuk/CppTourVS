#include "LinkedList.h"
namespace LinkedList 
{

template <typename Data>
inline List<Data>::List() : head(nullptr), size_m(0) {}


template <typename Data>
inline List<Data>::List(Data data) {
  this->head = new Node<Data>(data);
  this->head->p_next = nullptr;
  size_m = 1;
}

template <typename Data>
List<Data>::List(const List& other) 
{
  if (other.head == nullptr) {
    return;
  }
  // SetUp head
  this->head = new Node<Data>(other.head->data);
  ++size_m;
  // Handle with other p_next pointers
  Node<Data>* other_ptr = other.head->p_next;
  Node<Data>* this_ptr = this->head; 
  while (other_ptr) {
    this_ptr->p_next = new Node<Data>(other_ptr->data);
    this_ptr = this_ptr->p_next;
    // step to next node
    other_ptr = other_ptr->p_next;
    ++size_m;
  }
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
    this->head = new Node<Data>(dt);
    ++size_m;
    return;
  }
  Node<Data>* next = this->head;
  this->head = new Node<Data>(dt, next);
  ++size_m;
}

template <typename Data>
inline void List<Data>::push_back(Data dt) {
  // check if we already have first element
  if (this->head == nullptr) {
    this->head = new Node<Data>(dt);
    size_m++;
    return;
  }
  Node<Data>* current = this->head;
  while (current->p_next != nullptr) current = current->p_next;
  current->p_next = new Node<Data>(dt);
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
  Node<Data>* previous = this->head;
  Node<Data>* current = previous->p_next;
  for (size_t i = 0; i < index - 1; i++) {
    previous = current;
    current = current->p_next;
  }
  previous->p_next = new Node<Data>(dt, current);
  size_m++;
}

template <typename Data>
inline Data& List<Data>::operator[](int index) {
  Node<Data>* current = this->head;
  for (size_t i = 0; i < index; i++) current = current->p_next;
  return current->data;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_front() {
  if (size_m == 0) return;
  Node<Data>* to_delete = this->head;
  this->head = this->head->p_next;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_back() {
  if (size_m == 0) return;
  Node<Data>* current = this->head;
  for (size_t i = 0; i < size_m - 1; i++) current = current->p_next;
  Node<Data>* to_delete = current->p_next;
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
  Node<Data>* previous = this->head;
  Node<Data>* to_delete = previous->p_next;
  for (size_t i = 0; i < index - 1; i++) {
    previous = to_delete;
    to_delete = to_delete->p_next;
  }
  Node<Data>* buf = to_delete->p_next;
  delete to_delete;
  previous->p_next = buf;
  size_m--;
}

template <typename Data>
inline void List<Data>::clean() {
  while (this->head != nullptr) this->pop_front();
}

}