#include <iostream>
#include <string>
#include <vector>

namespace HashTable {

void Test(int& argc, char* argv[]);

template <typename T>
struct Node;

template <typename T>
class HashTable {
 public:
  HashTable(int size) : table(size) {}
  ~HashTable();

  /// <summary>
  /// Insert data using integer key
  /// </summary>
  /// <param name="key"></param>
  /// <param name="value"></param>
  void insert(int key, T value);

  /// <summary>
  /// Insert data using string
  /// </summary>
  /// <param name="key"></param>
  /// <param name="value"></param>
  void insert(const char* key, T value);

  T get(int key);

  T get(const char* key);

  void print();

 private:
  /// <summary>
  /// Main data holder
  /// </summary>
  std::vector<Node<T>*> table;

  /// <summary>
  /// In this hash function, the capacity of the table is multiplied by the key
  /// before taking the modulo with the table size. This helps to distribute the
  /// keys more evenly across the table, especially when the table is not
  /// completely full.
  /// </summary>
  /// <param name="key"></param>
  /// <returns></returns>
  int hash(int key);

  /// <summary>
  /// This hash function uses the popular djb2 algorithm, which is simple and
  /// efficient. It iterates over each character in the key and multiplies the
  /// current hash value by 33 (a prime number) and adds the ASCII value of the
  /// character. This ensures that small changes in the key result in vastly
  /// different hash values, which helps to distribute the keys evenly across
  /// the hash table.
  /// </summary>
  /// <param name="key"></param>
  /// <returns></returns>
  int hash(const char* key);

  /// <summary>
  /// convert using asci table and adding those  numbers
  /// </summary>
  /// <param name="key"></param>
  /// <returns></returns>
  int str_num(const char* key);
};

// Add new templates here if you wanna use another data types
template class HashTable<int>;
template class HashTable<char>;
template class HashTable<char*>;

}  // namespace HashTable