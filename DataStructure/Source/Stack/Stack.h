#pragma once

/*
Advantages:

1.Easy to implement: Stacks are a simple data structure that can be easily
implemented using an array or a linked list.
2.Fast operations: Stacks have fast
push and pop operations that take constant time, O(1). 
3.Useful in recursive algorithms: Stacks are often used to implement recursive algorithms, such as depth-first search, because they can be used to keep track of the function call
stack. 
4.Memory efficient: Stacks use memory efficiently because they only store
the data that is currently needed.

Disadvantages:

1.Limited functionality: Stacks are a relatively simple data structure and are
limited in functionality compared to other data structures like trees or graphs.
2.Limited access: Stacks only allow access to the topmost element, which can be
limiting in some situations.
3.Size limitations: The size of a stack is fixed at
the time of creation, which can be a disadvantage if the size needs to change
dynamically. (Only array based stack class).
4.Stack overflow: If too many elements are pushed onto a stack, it
can overflow and cause a program crash or other issues.
*/

namespace Stack
{

void Test(int& argc, char* argv[]);

template <typename T>
class Stack {
 public:

  struct Node {
    T data;
    Node* next;
  };

  Stack() : head_(nullptr) {}
  Stack(const Stack& other);
  ~Stack(); 

  void push(T value);
  void pop();
  T top() const;
  bool empty() const;
  size_t size() const; 

 private:
  Node* head_;
};

// Generate this basic template clases
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;

}  // namespace Stack