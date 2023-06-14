#pragma once
#include <iostream>

namespace rule_of_five 
{

 class rule_of_three {
  char* cstring;  // raw pointer used as a handle to a dynamically-allocated
                  // memory block

  rule_of_three(const char* s, std::size_t n)  // to avoid counting twice
      : cstring(new char[n])                   // allocate
  {
    std::memcpy(cstring, s, n);  // populate
  }

 public:
  rule_of_three(const char* s = "") : rule_of_three(s, std::strlen(s) + 1) {}

  ~rule_of_three()  // I. destructor
  {
    delete[] cstring;  // deallocate
  }

  rule_of_three(const rule_of_three& other)  // II. copy constructor
      : rule_of_three(other.cstring) {}

  rule_of_three& operator=(const rule_of_three& other)  // III. copy assignment
  {
    if (this == &other) return *this;

    std::size_t n{std::strlen(other.cstring) + 1};
    char* new_cstring = new char[n];             // allocate
    std::memcpy(new_cstring, other.cstring, n);  // populate
    delete[] cstring;                            // deallocate

    cstring = new_cstring;
    return *this;
  }

  operator const char*() const  // accessor
  {
    return cstring;
  }
};
 

 class rule_of_five {
  char* cstring;  // raw pointer used as a handle to a dynamically-allocated
                  // memory block
 public:
  rule_of_five(const char* s = "") : cstring(nullptr) {
    if (s) {
      std::size_t n = std::strlen(s) + 1;
      cstring = new char[n];       // allocate
      std::memcpy(cstring, s, n);  // populate
    }
  }
  
  ~rule_of_five() { // I. destructor
    delete[] cstring;  // deallocate
  }

  rule_of_five(const rule_of_five& other)  // II. copy constructor
      : rule_of_five(other.cstring) {}

  rule_of_five& operator=(const rule_of_five& other)  // III. copy assignment
  {
    return *this = rule_of_five(other);
  }

  rule_of_five(rule_of_five&& other) noexcept  // IV. move constructor
      : cstring(std::exchange(other.cstring, nullptr)) {}

  rule_of_five& operator=(rule_of_five&& other) noexcept  // V. move assignment
  {
    std::swap(cstring, other.cstring);
    return *this;
  }

  // alternatively, replace both assignment operators with
  //  rule_of_five& operator=(rule_of_five other) noexcept
  //  {
  //      std::swap(cstring, other.cstring);
  //      return *this;
  //  }
};
}