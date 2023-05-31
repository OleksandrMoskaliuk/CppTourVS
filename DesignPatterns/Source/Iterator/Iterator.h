#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
Iterator is a behavioral design pattern that allows sequential traversal through a complex data structure without exposing its internal details.
Thanks to the Iterator, clients can go over elements of different collections in a similar fashion using a single iterator interface.
*/

namespace IteratorPattern {

 int IteratorPattern();

/**
 * Iterator Design Pattern
 *
 * Intent: Lets you traverse elements of a collection without exposing its
 * underlying representation (list, stack, tree, etc.).
 */


/**
 * C++ has its own implementation of iterator that works with a different
 * generics containers defined by the standard library.
 */

template <typename T, typename U>
class Iterator {
 public:
  typedef typename std::vector<T>::iterator iter_type;
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
   // to get m_data this calass should be friend to Container class
    m_it_ = m_p_data_->m_data_.begin();
  }

  void First() { m_it_ = m_p_data_->m_data_.begin(); }

  void Next() { m_it_++; }

  bool IsDone() { return (m_it_ == m_p_data_->m_data_.end()); }

  iter_type Current() { return m_it_; }

 private:
  U *m_p_data_;
  iter_type m_it_;
};

/**
 * Generic Collections/Containers provides one or several methods for retrieving
 * fresh iterator instances, compatible with the collection class.
 */

template <class T>
class Container {
  friend class Iterator<T, Container>;

 public:
  void Add(T a) { m_data_.push_back(a); }

  Iterator<T, Container> *CreateIterator() {
    return new Iterator<T, Container>(this);
  }

 private:
  std::vector<T> m_data_;
};

class Data {
 public:
  Data(int a = 0) : m_data_(a) {}

  void set_data(int a) { m_data_ = a; }

  int data() { return m_data_; }

 private:
  int m_data_;
};

}  // namespace IteratorPattern
