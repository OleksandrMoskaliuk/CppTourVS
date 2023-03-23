#include "LinkedList.h"

namespace LinkedList 
{

template <typename Data>
inline List<Data>::List() : head(nullptr) {}


template <typename Data>
inline List<Data>::List(Data data) {
  this->head = new Node<Data>(data);
  this->head->p_next = nullptr;
}

template <typename Data>
List<Data>::List(const List& other) 
{
  if (other.head == nullptr) {
    return;
  }
  // SetUp head
  this->head = new Node<Data>(other.head->data);
  // Handle with other p_next pointers
  Node<Data>* other_ptr = other.head->p_next;
  Node<Data>* this_ptr = this->head; 
  while (other_ptr) {
    this_ptr->p_next = new Node<Data>(other_ptr->data);
    this_ptr = this_ptr->p_next;
    // step to next node
    other_ptr = other_ptr->p_next;
  }
}

template <typename Data>
inline List<Data>::~List() {
  this->clean();
}

template <typename Data>
inline int List<Data>::get_size() {
  int size = 0;
  Node<Data>* current = head;
  while (current) {
    ++size;
    current = current->p_next;
  }
  return size;
}

template <typename Data>
inline void List<Data>::push_front(Data dt) {
  if (this->head == nullptr) {
    this->head = new Node<Data>(dt);
    return;
  }
  Node<Data>* next = this->head;
  this->head = new Node<Data>(dt, next);
}

template <typename Data>
inline void List<Data>::push_back(Data dt) {
  // check if we already have first element
  if (this->head == nullptr) {
    this->head = new Node<Data>(dt);
    return;
  }
  Node<Data>* current = this->head;
  while (current->p_next != nullptr) current = current->p_next;
  current->p_next = new Node<Data>(dt);
}

template <typename Data>
inline void List<Data>::insert(int index, Data dt) {
  if (index <= 0) {
    this->push_front(dt);
    return;
  }
  if (index >= get_size()) {
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
}

template <typename Data>
inline Data& List<Data>::operator[](int index) {
  Node<Data>* current = this->head;
  for (size_t i = 0; i < index; i++) current = current->p_next;
  return current->data;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_front() {
  if (get_size() == 0) return;
  Node<Data>* to_delete = head;
  head = head->p_next;
  delete to_delete;
  to_delete = nullptr;
}

template <typename Data>
inline void LinkedList::List<Data>::pop_back() {
 // head   //
 // p_next // -> // head   //    //         //
 // data   //    // p_next // -> // nullptr //
                 // data   //    //         //
  if (head == nullptr) {
    return;
  }
  if (head->p_next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  Node<Data>* current = head;
  while (current->p_next->p_next != nullptr) {
    current = current->p_next;
  }
  delete current->p_next;
  current->p_next = nullptr;
}

template <typename Data>
inline void LinkedList::List<Data>::remove(int index) {
  if (index == 0) {
    this->pop_front();
    return;
  }
  Node<Data>* previous = head;
  Node<Data>* current = head->p_next;
  for (size_t i = 0; i < index - 1; i++) {
    previous = current;
    current = current->p_next;
  }
  Node<Data>* saved = current->p_next;
  delete current;
  previous->p_next = saved;
}

template <typename Data>
inline void List<Data>::clean() {
  while (this->head != nullptr) this->pop_front();
}

}