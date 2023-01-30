#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace agorithms {
namespace sorting {
class Sorting {
 private:
 public:
  Sorting();
  ~Sorting();

  // example for sorting list
  void list_sorting();
  // example for sorting vector
  void vector_sorting();
  // example for sorting vector with custom data type
  void custom_vector_sort();
};

// For custom sorting example
class person {
 public:
  person();
  person(const char* name, int score);

  ~person();
  bool operator()(person& ps);
  std::string getname();
  int getscore();

 private:
  std::string name;
  int score;
};

}  // namespace sorting
}  // namespace agorithms
#endif  // !VECTOR_SORTING_H
