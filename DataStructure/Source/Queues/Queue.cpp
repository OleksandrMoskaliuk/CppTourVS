#include "Queue.h"
namespace Queues {

template <typename T>
Queue<T>::Queue() {
  front = nullptr;
  rear = nullptr;
}

template <typename T>
Queue<T>::Queue(const Queue &other) 
{
  Node* temp = other.front;
  while (temp) {
    enqueue(temp->val);
    temp = temp->next;
  }
}

template <typename T>
Queue<T>::~Queue() 
{
  while (!isEmpty()) {
    Node* temp = front;
    front = front->next;
    delete temp;
  }
}

template <typename T>
bool Queue<T>::isEmpty() { return front == nullptr; }


template <typename T>
void Queue<T>::enqueue(int val) {
  Node* newNode = new Node(val);
  if (isEmpty()) {
    front = rear = newNode;
    return;
  }
  rear->next = newNode;
  rear = newNode;
}

template <typename T>
int Queue<T>::dequeue() {
  if (isEmpty()) {
    // Queue underflow!
    return -1;
  }
  int val = front->val;
  Node* temp = front;
  front = front->next;
  delete temp;
  return val;
}

template <typename T>
int Queue<T>::peek() {
  if (isEmpty()) {
    // Queue is empty!
    return -1;
  }
  return front->val;
}



}
