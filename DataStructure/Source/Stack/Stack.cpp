#include "Stack.h"

namespace Stack 
{
template <typename T>
Stack<T>::Stack(const Stack& other) 
{
  Node* current = other.head_;
  Stack reversed_stack;
  while (current) {
    reversed_stack.push(current->data);
    current = current->next;
  }
  while (!reversed_stack.empty()) {
    push(reversed_stack.top());
    reversed_stack.pop();
  }

}

template <typename T>
Stack<T>::~Stack() {
  while (!empty()) {
    pop();
  }
}

template <typename T>
void Stack<T>::push(T value) 
{
  Node* new_node = new Node{value, head_};
  head_ = new_node;
}

template <typename T>
void Stack<T>::pop() {
  if (!empty()) {
    Node* old_head = head_;
    head_ = head_->next;
    delete old_head;
  }
}

template <typename T>
T Stack<T>::top() const {
  if (!empty()) {
    return head_->data;
  }
  return T();
}

template <typename T>
bool Stack<T>::empty() const {
  return head_ == nullptr;
}

template <typename T>
size_t Stack<T>::size() const {
  Node* current = head_;
  unsigned int size = 0;
  while (current) {
    current = current->next;
    ++size;
  }
  return size;
}








}
