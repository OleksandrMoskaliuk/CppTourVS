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
class BinaryTree 
{

  Node<T>* root;

 public:

  /// <summary>
  /// Deafult constructor
  /// </summary>
  BinaryTree() : root(nullptr) {}

  BinaryTree(T data) : root(new Node<T>(data)) {}

  ~BinaryTree() { clear(); }

  void insert(T data) 
  { 
   insert(root, data);
  }

  Node<T>* search(T data) 
  { 
   return search(root, data);
  }


  void inorder() 
  { 
   inorder(root);
  }

  void remove(T data) 
  { 
   erase(root, data);
  }

  void clear() 
  { 
   clear(this->root);
  }

 private:
  Node<T>* createNode(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  void insert(Node<T>*& root, T data) {
    if (root == nullptr) {
      root = createNode(data);
    } else if (data <= root->data) {
      insert(root->left, data);
    } else {
      insert(root->right, data);
    }
  }

  Node<T>* search(Node<T>* root, T data) {
    if (root == NULL) {
      return nullptr;
    } else if (root->data == data) {
      return root;
    } else if (data <= root->data) {
      return search(root->left, data);
    } else {
      return search(root->right, data);
    }
  }

  Node<T>* search_parent(Node<T>* root, Node<T>*& parent, T data) {
    if (root == this->root) {
      parent = root;
      return root;
    }
   if (root == NULL) {
      return nullptr;
    } else if (root->data == data) {
      return root;
    } else if (data <= root->data) {
      parent = root;
      return search(root->left, data);
    } else {
      parent = root;
      return search(root->right, data);
    }
  }

  void inorder(Node<T>* root) {
    if (root == NULL) {
      return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    cout << "\n";
  }

  void clear(Node<T>* root) 
  {
    if (root == nullptr) {
      return;
    }  
    clear(root->left);
    clear(root->right);
    delete root;
    root = nullptr;
  }

  
  void erase(Node<T>*& root, T value) {
    if (root == nullptr) {
      return;
    }
    // Looking for data, if this two 'if' condition failed then maybe we find data
    if (value < root->data) {
      erase(root->left, value);
    } else if (value > root->data) {
      erase(root->right, value);
    } else
      // do not chech whether 2 of node is nullptr , first of all if one node nullptr is enought to make is as root
      {
      if (root->left == nullptr) {
       Node<T>* temp = root->right;
       delete root;
       root = temp;
      } else if (root->right == nullptr) {
       Node<T>* temp = root->left;
       delete root;
       root = temp;
      } else
       // In this case neither of nodes is not nullptr and have some values.
      {
       Node<T>* successor = findSuccessor(root->right);
       root->data = successor->data;
       erase(root->right, successor->data);
      }
    }
  }

  Node<T>* findSuccessor(Node<T>* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

 };

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;


}  // namespace BinaryTree