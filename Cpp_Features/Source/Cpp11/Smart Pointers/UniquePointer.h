#pragma once
namespace unique_pointer {

 void example();

template <typename T>
class UniquePointer {
 public:
  // DEFAULT CONSTRUCTOR 
  explicit UniquePointer(T* ptr = nullptr) : m_ptr(ptr) {}
  ~UniquePointer() { 
   if (m_ptr)
   delete m_ptr; }
  // COPY CONSTRUCTOR  <NOT ALLOWED>
  UniquePointer(const UniquePointer&) = delete;
  // ASSIGN OPERATOR LVALUES ONLY <NOT ALLOWED>
  UniquePointer& operator=(const UniquePointer&) = delete;

  // MOVE CONSTRUCTOR RVALUES ONLY
  UniquePointer(UniquePointer&& other) noexcept;

  // ASSIGN OPERATOR RVALUES ONLY 
  UniquePointer& operator=(UniquePointer&& other) noexcept;
  T* operator->() const { return m_ptr; }

  T& operator*() const { return *m_ptr; }

 private:
  T* m_ptr;
};
// MOVE CONSTRUCTOR 
template <typename T>
inline UniquePointer<T>::UniquePointer(UniquePointer&& other) noexcept {
  if (other.m_ptr != nullptr) {
    m_ptr = other.m_ptr;
    delete other.m_ptr;
    // prevent unexpected behaviour
    other.m_ptr = nullptr;
  }
}
// ASSIGN OPERATOR 
template <typename T>
inline UniquePointer<T>& UniquePointer<T>::operator=(
    UniquePointer&& other) noexcept {
  if (this != &other) {
    delete m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
  }
  return *this;
}

}  // namespace unique_pointer
