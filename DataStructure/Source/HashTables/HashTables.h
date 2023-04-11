#include <vector>
#include <string>
#include <iostream>

namespace HashTable {

 void Test(int& argc, char* argv[]);

 template <typename T>
 struct Node {
  int key;
  T value;
  Node<T>* next;
  Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

 template <typename T>
class HashTable {
 public:
  HashTable(int size) : table(size) {}

  void insert(int key, T value) {
    int index = hash(key);
    Node<T>* node = table[index]; 

    // approach called chaining
    // When a collision occurs, the new value is added to the linked list at that index.
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

  void insert(const char* key, T value) {

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

  int get(int key) {
    int index = hash(key);
    Node<T>* node = table[index];
    while (node != nullptr) {
      if (node->key == key) {
        return node->value;
      }
      node = node->next;
    }
    return -1;  // key not found
  }

   T get(const char* key) {
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

  void print() { 
   for (size_t i = 0; i < table.size(); i++) {
      Node<T>* nd = table[i];
      while (nd != nullptr) {
        std::cout << " | " << nd->value << " | > ";
        nd = nd->next;
      }
      std::cout << "\n";
   }
  }

 private:
  std::vector<Node<T>*> table;

  int hash(int key) { return key % table.size(); }

  /// <summary>
  /// This hash function uses the popular djb2 algorithm, which is simple and efficient. It iterates over each character in the key and multiplies the current hash value by 33 (a prime number) and adds the ASCII value of the character. This ensures that small changes in the key result in vastly different hash values, which helps to distribute the keys evenly across the hash table.
  /// </summary>
  /// <param name="key"></param>
  /// <returns></returns>
  int hash(const char* key) {
   unsigned int hash = 5381;
   int c;
   while ((c = *key++)) {
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
   }
   return hash % table.size();
  }

  int str_num(const char* key ) 
  { 
    int num = 0;
    for (size_t i = 0; i < std::strlen(key); ++i) {
      num += (unsigned int) key[i];
   }
    return num;
  }

 };

template class HashTable<int>;
template class HashTable<char>;


}  // namespace HashTable