#include "MoveSemantics.h"
#include <iostream>
#include <vector>

/*
* 
            lvalue   const lvalue   rvalue   const rvalue
---------------------------------------------------------
X&         | yes     |             |        |
const X&   | yes     | yes         | yes    | yes
X&&        |         |             | yes    |
const X&&  |         |             | yes    | yes

*/

template<class T> class vector {
    // ...
    vector(const vector&);            // copy constructor
    vector(vector&&) noexcept;        // move constructor
    vector& operator=(const vector&); // copy assignment
    vector& operator=(vector&&);      // move assignment
};



template <typename T>
class unique_ptr {
  T *ptr;

 public:
  T *operator->() const { return ptr; }

  T &operator*() const { return *ptr; }

  explicit unique_ptr(T *p = nullptr) { ptr = p; }

  ~unique_ptr() { delete ptr; }

  // move constructor
  unique_ptr(unique_ptr &&source) noexcept  // note the rvalue reference
  {
    ptr = source.ptr;
    source.ptr = nullptr;
  }

  //Assignment operator. Its job is to release the old resource and acquire the new resource from its argument:
  unique_ptr &operator=(unique_ptr &&source)  // note the rvalue reference
  {
    if (this != &source)  // beware of self-assignment
    {
      delete ptr;  // release the old resource

      ptr = source.ptr;  // acquire the new resource
      source.ptr = nullptr;
    }
    return *this;
    // Also can be implemented as:
    // std::swap(ptr, source.ptr);
    // return *this;
  }
};


char chret() 
{ return 'c'; }


template <typename T>
void universal(T &&a) {
  int b = a;
  std::cout << b;
  
}

namespace move_semantics 
{

 void example() 
 { 
  char *p = new char[5]{'a', 'b', 'c', 'd',};
  char &r = *p;

  const char &dr = chret();
  int a = 20;
  int &&T = 10;
  // can hold xvalues
  universal(T);
  universal(a);
  universal(chret());
 }

 void example2() 
 { 
  // use lvalues to run copy constructor
  int *i = new int(10);
  unique_ptr<int> unique_var_p1(i);

  // obtain resources by move constructor using rvalue
  unique_ptr<int> unique_var_p2(std::move(unique_var_p1));
 }

 

}