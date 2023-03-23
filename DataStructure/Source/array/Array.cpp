#include "Array.h"

#include <iostream>

namespace Array {

template <typename T>
MyDinamicArray<T>::MyDinamicArray() : MyDinamicArray(0)
{

}

template <typename T>
MyDinamicArray<T>::MyDinamicArray(int size)
    : m_data(new T[size]{}), m_size(size), m_capacity(size * 2 + 1) {
 // m_data(new T[size]{}) -> writing zero to each cell at init
}


template <typename T>
MyDinamicArray<T>::MyDinamicArray(const MyDinamicArray& other)
    : m_data(new T[other.capacity()]), m_size(other.m_size), m_capacity(other.capacity()) {
  for (int i = 0; i < m_size; ++i) m_data[i] = other.m_data[i];
}

template <typename T>
MyDinamicArray<T>::~MyDinamicArray() {
  delete[] m_data;
  m_data = nullptr;
}

template <typename T>
T& MyDinamicArray<T>::operator[](int index) {
  return m_data[index];
}


template <typename T>
const T& MyDinamicArray<T>::operator[](int index) const {
  return m_data[index];
}

template <typename T>
void MyDinamicArray<T>::push_back(const T& element) {
  if (m_size == m_capacity) {
    resize(m_capacity * 2);
  }
  m_data[m_size++] = element;
}

template <typename T>
void MyDinamicArray<T>::pop_back() {
  if (m_size != 0) {
     m_data[--m_size] = 0;
  }
  else if (m_size == 0) {
     erase();
  }
}

template <typename T>
int MyDinamicArray<T>::size() const {
  return m_size;
}

template <typename T>
int MyDinamicArray<T>::capacity() const {
  return m_capacity;
}

template <typename T>
void MyDinamicArray<T>::resize(int newCapacity) {
  T* newData = new T[newCapacity];
  for (int i = 0; i < m_size; ++i) {
    newData[i] = m_data[i];
  }
  delete[] m_data;
  m_data = newData;
  m_capacity = newCapacity;
}

template <typename T>
const T* MyDinamicArray<T>::get_base_pointer() {
  return m_data;
}

template <typename T>
void MyDinamicArray<T>::erase() 
{
    delete[] m_data;
    m_size = 0;
    resize(0);
}

}  // namespace Array
