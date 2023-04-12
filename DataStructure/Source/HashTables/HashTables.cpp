#include "HashTables.h"

namespace HashTable 
{

template <typename T>
struct Node {
  int key;
  T value;
  Node<T>* next;
  Node(int k, T v) : key(k), value(v), next(nullptr) {}
};

template <typename T>
HashTable<T>::~HashTable() 
{
  for (size_t i = 0; i < table.size(); i++) {
    Node<T>* nd = table[i];
    while (nd != nullptr) {
      // make buffer to have acces to next node
      Node<T>* buf = nd->next;
      // delete  current node
      delete nd;
      // save access to other nodes if there is one
      nd = buf;
    }
  }
}

template <typename T>
void HashTable<T>::insert(int key, T value) {
  int index = hash(key);
  Node<T>* node = table[index];

  // approach called chaining
  // When a collision occurs, the new value is added to the linked list at that
  // index.
  while (node != nullptr) {
    if (node->key == key) {
      node->value = value;
      return;
    }
    node = node->next;
  }
  // making new node
  node = new Node<T>(key, value);
  // bound last created node to other element of list
  node->next = table[index];
  // bound chain of nodes to certain index
  table[index] = node;
  // now we can acces to newly created node
  // old node > table[index].next
  // new node > table[index]
}

template <typename T>
void HashTable<T>::insert(const char* key, T value) {
  int index = hash(key);
  Node<T>* node = table[index];

  // approach called chaining
  // When a collision occurs, the new value is added to the linked list at
  // that index.
  while (node != nullptr) {
    if (node->key == str_num(key)) {
      node->value = value;
      return;
    }
    node = node->next;
  }
  // making new node
  node = new Node<T>(str_num(key), value);
  // bound last created node to other element of list
  node->next = table[index];
  // bound chain of nodes to certain index
  table[index] = node;
  // now we can acces to newly created node
  // old node > table[index].next
  // new node > table[index]
}

template <typename T>
T HashTable<T>::get(int key) {
  int index = hash(key);
  Node<T>* node = table[index];
  while (node != nullptr) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return T();  // key not found
}

template <typename T>
 T HashTable<T>::get(const char* key) {
  int index = hash(key);
  Node<T>* node = table[index];
  while (node != nullptr) {
    if (node->key == str_num(key)) {
      return node->value;
    }
    node = node->next;
  }
  return T();  // key not found
}

template <typename T>
void HashTable<T>::print() {
  for (size_t i = 0; i < table.size(); i++) {
    Node<T>* nd = table[i];
    while (nd != nullptr) {
      std::cout << " | " << nd->value << " | > ";
      nd = nd->next;
    }
    std::cout << "\n";
  }
}

template <typename T>
int HashTable<T>::hash(int key) {
  return ((unsigned int)key * table.capacity()) % table.size();
}

template <typename T>
int HashTable<T>::hash(const char* key) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash % table.size();
}

template <typename T>
int HashTable<T>::str_num(const char* key) {
  int num = 0;
  for (size_t i = 0; i < std::strlen(key); ++i) {
    num += (unsigned int)key[i];
  }
  return num;
}

} // namespace HashTable 