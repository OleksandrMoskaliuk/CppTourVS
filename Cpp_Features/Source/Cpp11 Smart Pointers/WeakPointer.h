#pragma once

#include "SharedPtr.h"

namespace weak_pointer 
{
void example();

 template <typename T>
class WeakPtr {
 public:
  // Default constructor
  WeakPtr() : m_ptr(nullptr), m_refCount(nullptr) {}

  // Copy constructor
  WeakPtr(const WeakPtr& other)
      : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {}


  // Move constructor
  WeakPtr(WeakPtr&& other) noexcept
      : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {
    other.m_ptr = nullptr;
    other.m_refCount = nullptr;
  }

  // Destructor
  ~WeakPtr() {}

  // Copy assignment operator
  WeakPtr& operator=(const WeakPtr& other) {
    if (this != &other) {
      m_ptr = other.m_ptr;
      m_refCount = other.m_refCount;
    }
    return *this;
  }

  //void func(shared_pointers::SharedPtr<T>& shp) ;

  // Move assignment operator
  WeakPtr& operator=(WeakPtr&& other) noexcept {
    if (this != &other) {
      m_ptr = other.m_ptr;
      m_refCount = other.m_refCount;
      other.m_ptr = nullptr;
      other.m_refCount = nullptr;
    }
    return *this;
  }

  

  //// Lock the weak pointer to get a shared pointer
  //shared_pointers::SharedPtr lock() const {
  //  return shared_pointers::SharedPtr(*this);
  //}

  // Check if the weak pointer is expired
  bool expired() const { return !m_refCount || (*m_refCount == 0); }

 private:
  T* m_ptr;         // Pointer to the managed object
  int* m_refCount;  // Reference count

  // ...
};

//template <typename T>
//void WeakPtr<T>::func(shared_pointers::SharedPtr<T>& shp)
//{};

}


