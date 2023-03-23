#ifndef ARRAY_H
#define ARRAY_H

namespace Array {

void Test(int& argc, char* argv[]);

/// <summary>
/// Support only -> double, float, int, char;
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class MyDinamicArray {
 public:
  /// <summary>
  /// Default constructor
  /// </summary>
  MyDinamicArray();

  /// <summary>
  /// Constructor with predefined size
  /// </summary>
  /// <param name="size"></param>
  MyDinamicArray(int size);

  /// <summary>
  /// Copy constructor
  /// </summary>
  /// <param name="other"></param>
  MyDinamicArray(const MyDinamicArray& other);

  /// <summary>
  /// Default destructor
  /// </summary>
  ~MyDinamicArray();

  /// <summary>
  /// Insert new element to the end of list
  /// </summary>
  /// <typeparam name="T"></typeparam>
  void push_back(const T& element);

  /// <summary>
  /// Remove element from end of list
  /// </summary>
  /// <typeparam name="T"></typeparam>
  void pop_back();

  /// <summary>
  /// For non const declaration. Read and write
  /// </summary>
  /// <param name="index"></param>
  /// <returns></returns>
  T& operator[](int index);

  /// <summary>
  /// For const declaration. Only read
  /// </summary>
  /// <param name="index"></param>
  /// <returns></returns>
  const T& operator[](int index) const;

  /// <summary>
  /// Get element amount that already in array
  /// </summary>
  /// <returns></returns>
  int size() const;

  /// <summary>
  /// Get how many alocated memory remain
  /// </summary>
  int capacity() const;

  /// <summary>
  /// Erase all data in array
  /// </summary>
  /// <typeparam name="T"></typeparam>
  void erase();

  const T* get_base_pointer();

 private:
  /// <summary>
  /// Hold pointer to first element of array
  /// </summary>
  /// <typeparam name="T"></typeparam>
  T* m_data;
  /// <summary>
  /// CUrrrent size
  /// </summary>
  /// <typeparam name="T"></typeparam>
  int m_size;
  /// <summary>
  /// Total reserved size
  /// </summary>
  /// <typeparam name="T"></typeparam>
  int m_capacity;

  void resize(int newCapacity);
};

// instantiate template explicitly for each template parameter, prevent linker
// error. For using new data type you fitst need to declare it here!.
template class MyDinamicArray<int>;
template class MyDinamicArray<float>;
template class MyDinamicArray<double>;
template class MyDinamicArray<char>;



template <typename T, size_t Size>
class MyStaticArray {
 public:
  MyStaticArray() {}
  ~MyStaticArray() {}

  // Define the iterator classes
  class iterator {
   public:
    explicit iterator(T* ptr) : m_ptr(ptr) {}
    iterator& operator++() {
      m_ptr++;
      return *this;
    }
    iterator operator++(int) {
      iterator i = *this;
      ++(*this);
      return i;
    }
    bool operator==(const iterator& other) const {
      return m_ptr == other.m_ptr;
    }
    bool operator!=(const iterator& other) const { return !(*this == other); }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }

   private:
    T* m_ptr;
  };

  class const_iterator {
   public:
    explicit const_iterator(const T* ptr) : m_ptr(ptr) {}
    const_iterator& operator++() {
      m_ptr++;
      return *this;
    }
    const_iterator operator++(int) {
      const_iterator i = *this;
      ++(*this);
      return i;
    }
    bool operator==(const const_iterator& other) const {
      return m_ptr == other.m_ptr;
    }
    bool operator!=(const const_iterator& other) const {
      return !(*this == other);
    }
    const T& operator*() const { return *m_ptr; }
    const T* operator->() const { return m_ptr; }

   private:
    const T* m_ptr;
  };

  // Define the begin() and end() member functions
  iterator begin() { return iterator(&m_data[0]); }
  iterator end() { return iterator(&m_data[Size]); }
  const_iterator begin() const { return const_iterator(&m_data[0]); }
  const_iterator end() const { return const_iterator(&m_data[Size]); }

  const size_t size() const { return Size; }
  T& operator[](size_t index) { return m_data[index]; }
  const T& operator[](size_t index) const { return m_data[index]; }

 private:
  T m_data[Size];

};


}  // namespace Array

#endif  // ARRAY_H