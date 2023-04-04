#include "BinaryTree.h"

namespace BinaryTree
{

template <typename T>
Node<T>* BinaryTree<T>::createNode(T data) {
  Node<T>* newNode = new Node<T>;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

template<typename T>
void BinaryTree<T>::insert(Node<T>*& root, T data) 
{
  if (root == nullptr) {
    root = createNode(data);
  } else if (data <= root->data) {
    insert(root->left, data);
  } else {
    insert(root->right, data);
  }
}

template<typename T>
Node<T>* BinaryTree<T>::search(Node<T>* root, T data) 
{
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

template <typename T>
void BinaryTree<T>::inorder(Node<T>* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
  cout << "\n";
}

template <typename T>
void BinaryTree<T>::clear(Node<T>* root) {
  if (root == nullptr) {
    return;
  }
  clear(root->left);
  clear(root->right);
  delete root;
  root = nullptr;
}

template<typename T>
 void BinaryTree<T>::erase(Node<T>*& root, T value) {
  if (root == nullptr) {
    return;
  }
  // Looking for data, if this two 'if' condition failed then maybe we find
  // data
  if (value < root->data) {
    erase(root->left, value);
  } else if (value > root->data) {
    erase(root->right, value);
  } else
  // do not chech whether 2 of node is nullptr , first of all if one node
  // nullptr is enought to make is as root
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

template<typename T>
Node<T>* BinaryTree<T>::findSuccessor(Node<T>* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

} // namespace BinaryTree