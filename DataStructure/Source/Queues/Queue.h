#pragma once
namespace Queues 
{

void Test(int& argc, char* argv[]);

template <typename T>
class Queue {

struct Node {
  T val;
  Node* next;
  Node(T value) {
    val = value;
    next = nullptr;
  }
};

 private:
  Node* front;
  Node* rear;

 public:
  Queue();
  Queue(const Queue &other);
  ~Queue();

  bool isEmpty();

  /// <summary>
  /// creates a new node and adds it to the back of the list
  /// </summary>
  /// <param name="val"></param>
  void enqueue(int val);

  /// <summary>
  /// removes and returns the first node in the list
  /// </summary>
  /// <returns></returns>
  int dequeue();

  /// <summary>
  /// returns the value of the first node without removing it from the list
  /// </summary>
  /// <returns></returns>
  int peek();
};

template class Queue<int>;
template class Queue<double>;
template class Queue<float>;
template class Queue<char>;


} // namespace #include <iostream>

