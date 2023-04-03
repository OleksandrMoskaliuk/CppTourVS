#pragma once
#include <iostream>

namespace BinaryTree {

void Test(int& argc, char* argv[]);

using namespace std;

template <typename T>
class Node {
 public:
  Node() : data(T()), left(nullptr), right(nullptr) {}
  Node(T data) : data(data), left(nullptr), right(nullptr) {}
  T data;
  Node<T>* left;
  Node<T>* right;
};

template <typename T>
class BinaryTree {

  Node<T>* root;

 public:
  /// <summary>
  /// Deafult constructor
  /// </summary>
  BinaryTree() : root(nullptr) {}

  BinaryTree(T data) : root(new Node<T>(data)) {}

  ~BinaryTree() { clear(); }

  void insert(T data) { insert(root, data); }

  Node<T>* search(T data) { return search(root, data); }

  void inorder() { inorder(root); }

  void remove(T data) { erase(root, data); }

  void clear() { clear(this->root); }

 private:
  Node<T>* createNode(T data);

  void insert(Node<T>*& root, T data);

  Node<T>* search(Node<T>* root, T data);

  void inorder(Node<T>* root);

  void clear(Node<T>* root);

  void erase(Node<T>*& root, T value);

  Node<T>* findSuccessor(Node<T>* node);

}; // class BinaryTree

  template class BinaryTree<int>;
  template class BinaryTree<float>;
  template class BinaryTree<double>;


}  // namespace BinaryTree