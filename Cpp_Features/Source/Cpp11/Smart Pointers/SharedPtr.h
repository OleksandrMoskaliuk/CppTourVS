#pragma once
//#include "WeakPointer.h"

namespace shared_pointers 
{

 void example();

template <typename T>
class SharedPtr {
 public:
  // Default constructor
  SharedPtr() : m_ptr(nullptr), m_refCount(nullptr) {}

  // Constructor with raw pointer
  explicit SharedPtr(T* ptr) : m_ptr(ptr), m_refCount(new int(1)) {}

  // Copy constructor
  SharedPtr(const SharedPtr& other)
      : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {
    if (m_refCount) {
      (*m_refCount)++;
    }
  }


  // Move constructor
  SharedPtr(SharedPtr&& other) noexcept
      : m_ptr(other.m_ptr), m_refCount(other.m_refCount) {
    other.m_ptr = nullptr;
    other.m_refCount = nullptr;
  }

  // Destructor
  ~SharedPtr() { release(); }

  // Assignment operator
  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      release();
      m_ptr = other.m_ptr;
      m_refCount = other.m_refCount;
      /*
      In the assignment operator, the if (m_refCount) check is used to prevent incrementing the reference count
      if m_refCount is already null (zero).
      The purpose of this check is to handle the case
      when the source SharedPtr object is empty or has already been released.
      */
      if (m_refCount) {
        (*m_refCount)++;
      }
    }
    return *this;
  }

  // Move assignment operator
  SharedPtr& operator=(SharedPtr&& other) noexcept {
    if (this != &other) {
      release();
      m_ptr = other.m_ptr;
      m_refCount = other.m_refCount;
      other.m_ptr = nullptr;
      other.m_refCount = nullptr;
    }
    return *this;
  }

  // Dereference operator
  T& operator*() const { return *m_ptr; }

  // Arrow operator
  T* operator->() const { return m_ptr; }

  // Get the raw pointer
  T* get() const { return m_ptr; }

  // Check if the shared pointer is valid (not null)
  explicit operator bool() const { return m_ptr != nullptr; }

  // Get the reference count
  int use_count() const { return m_refCount ? *m_refCount : 0; }

  void reset() { release(); };

 private:
  T* m_ptr;         // Pointer to the managed object
  int* m_refCount;  // Reference count

  // Release the shared pointer and decrement the reference count
  void release() {
    if (m_refCount) {
      (*m_refCount)--;
      if (*m_refCount == 0) {
        delete m_ptr;
        delete m_refCount;
      }
    }
  }
};

}