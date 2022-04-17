#ifndef SORTING_H
#define SORTING_H

#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

namespace my_sort {
// entry point for Sorting.cpp
int entry_point();
// example for sorting list
void list_sorting();
// example for sorting vector
void vector_sorting();
// example for sorting vector with custom data type
void custom_vector_sort();

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

}  // namespace my_sort
#endif  // !VECTOR_SORTING_H
