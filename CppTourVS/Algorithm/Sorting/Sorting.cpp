#include "Sorting.h"

namespace my_sort {

person::person() {
  this->name = "No Name";
  this->score = 0;
}

person::person(const char* name, int score) {
  this->name = name;
  this->score = score;
}

person::~person() {}

bool person::operator()(person& ps) { return this->getscore() > ps.getscore(); }

std::string person::getname() { return this->name; }

int person::getscore() { return this->score; }



void list_sorting() {
  std::list<int> l_arr = {0, 1, 2, 3, 45, 4, 37};
  // std::minmax_element will return max and min elements of array
  std::pair<std::list<int>::iterator, std::list<int>::iterator> list_wrapper =
      std::minmax_element(l_arr.begin(), l_arr.end());
  std::cout << " Min  element: " << *list_wrapper.first << '\n';
  std::cout << " Max element: " << *list_wrapper.second << '\n';
  // sort from min to max
  l_arr.sort([](int& first, int& last) { return first < last; });
  // print result on console
  for (int& rangebased : l_arr) {
    std::cout << rangebased << '\n';
  }
}

void vector_sorting() {
  std::vector<int> v_arr = {0, 1, 2, 3, 22, 4, 18};

  // getting max and min element of vector array
  std::vector<int>::iterator max_el =
      std::max_element(v_arr.begin(), v_arr.end());
  std::cout << "\nMax element:" << *max_el << '\n';

  std::vector<int>::iterator min_el =
      std::min_element(v_arr.begin(), v_arr.end());
  std::cout << "\Min element:" << *min_el << '\n';

  // sorting vector array
  std::sort(v_arr.begin(), v_arr.end(),
            [](int& first, int& second) { return first < second; });

  // print result on console
  for (int& el : v_arr) {
    std::cout << el << '\n';
  }
}

void custom_vector_sort() {
  // vector with person data type
  std::vector<person> v_arr = {person("Tobi", 70), person("Albert", 60),
                               person("Arnold", 140), person("Alex", 199),
                               person("Tom", 150)};

  // sorting vector array
  std::sort(v_arr.begin(), v_arr.end(), [](person& first, person& last) {
    return first.getscore() < last.getscore();
  });

  // print sorted vector on console
  for (person& rangebased : v_arr) {
    std::cout << rangebased.getname() << " = " << rangebased.getscore() << '\n';
  }

  // count if score more than 140
  int count = std::count_if(v_arr.begin(), v_arr.end(),
                            [](person& ps) { return ps.getscore() > 140; });
  std::cout << "People that have more than 140 points = " << count << "\n";

  // copy in new vector array if score more than 150
  std::vector<person> _150_points_array;
  std::copy_if(v_arr.begin(), v_arr.end(),
               std::back_inserter(_150_points_array),
               [](person& ps) { return (ps.getscore() > 150); });
  for (person& ps : _150_points_array) {
    std::cout << ps.getname() << " have more than 150 points"
              << "\n";
  }
}

int entry_point() {
  // list_sorting();
  // vector_sorting();
  // custom_vector_sort();
  return 0;
}

}  // namespace my_sort
