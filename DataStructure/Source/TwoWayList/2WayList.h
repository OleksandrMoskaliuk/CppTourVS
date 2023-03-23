#ifndef TWO_WAY_LIST_H
#define TWO_WAY_LIST_H


namespace TwoWayList {

 template <typename Data>
class Node {
 public:
  Data data; //current node
  Node<Data>* p_next; //pointer to the next node
  // default constructor
  Node(Data data = Data(), Node<Data>* p_next = nullptr) {
    this->data = data;
    this->p_next = p_next;
  };
};

template <typename Data>
class TwoWayNode {
 public:
  Data data;
  TwoWayNode<Data>* p_next;
  TwoWayNode<Data>* p_prev;
  TwoWayNode<Data>* node_adress;

 public:
  TwoWayNode(Data data = Data(), TwoWayNode<Data>* p_prev = nullptr,
             TwoWayNode<Data>* p_next = nullptr)
      : data(data), p_prev(p_prev), p_next(p_next), node_adress(this){};
};

template <typename Data>
class TwoWayList {
 private:
  TwoWayNode<Data>* head;
  TwoWayNode<Data>* tail;
  int size_m;

 public:
  TwoWayList() :  size_m(0), head(nullptr), tail(nullptr) {};
  ~TwoWayList();

 public:
  int get_size();
  void push_front(Data dt);
  void push_back(Data dt);
  void insert(const int index, Data dt);
  Data& operator[](int index);
  TwoWayNode<Data>* get_node_adress(const int node_index);
  void pop_front();
  void pop_back();
  void remove(const int index);
  void clean();
};

template <typename Data>
inline TwoWayList<Data>::~TwoWayList() {
  clean();
}

template <typename Data>
inline int TwoWayList<Data>::get_size() {
  return this->size_m;
}

template <typename Data>
inline void TwoWayList<Data>::push_front(Data dt) {
  if (this->head == nullptr) {
    this->head = new TwoWayNode<Data>(dt);
    this->tail = this->head;
    size_m++;
    return;
  }
  TwoWayNode<Data>* node_before_head = this->head;
  this->head = new TwoWayNode<Data>(dt, nullptr, node_before_head);
  node_before_head->p_prev = this->head;
  size_m++;
}

template <typename Data>
inline void TwoWayList<Data>::push_back(Data dt) {
  if (this->head == nullptr) {
    this->head = new TwoWayNode<Data>(dt);
    this->tail = this->head;
    size_m++;
    return;
  }
  TwoWayNode<Data>* pre_last = this->tail;
  pre_last->p_next = new TwoWayNode<Data>(dt, pre_last, nullptr);
  this->tail = pre_last->p_next;
  size_m++;
}

template <typename Data>
inline void TwoWayList<Data>::insert(const int index, Data dt) {
  if (get_node_adress(index) == nullptr) return;
  get_node_adress(index)->data = dt;
  return;
}

template <typename Data>
inline Data& TwoWayList<Data>::operator[](int index) {
  if (size_m == 0) {
    Data except = Data();
    return except;
  }
  if (index > size_m) index = size_m;
  if (index < 0) index = 0;
  // strart count from tail
  if (index > (size_m / 2)) {
    TwoWayNode<Data>* current = this->tail;
    int steps = size_m - index - 1;
    for (size_t i = 0; i < steps; i++) {
      current = current->p_prev;
    }
    return current->data;
  }
  // strart count from head
  TwoWayNode<Data>* current = this->head;
  for (size_t i = 0; i < index; i++) {
    current = current->p_next;
  }
  return current->data;
}

template <typename Data>
inline TwoWayNode<Data>* TwoWayList<Data>::get_node_adress(
    const int node_index) {
  if (size_m == 0 || node_index > size_m || node_index  < 0) return nullptr;
  if (node_index > (size_m / 2)) {
    TwoWayNode<Data>* current = this->tail;
    int steps = size_m - node_index - 1;
    for (size_t i = 0; i < steps; i++) {
      current = current->p_prev;
    }
    return current->node_adress;
  }
  // strart count from head
  TwoWayNode<Data>* current = this->head;
  for (size_t i = 0; i < node_index; i++) {
    current = current->p_next;
  }
  return current->node_adress;
}

template <typename Data>
inline void TwoWayList<Data>::pop_front() 
{
  if (size_m == 0) return;
  if (size_m == 1) {
    delete this->tail;
    this->tail = nullptr;
    this->head = nullptr;
    size_m--;
    return;
  }
  TwoWayNode<Data>* new_head = this->head->p_next;
  new_head->p_prev = nullptr;
  delete head;
  this->head = new_head;
  size_m--;
}

template <typename Data>
inline void TwoWayList<Data>::pop_back() 
{
  if (size_m == 0) return;
  if (size_m == 1) {
    delete this->tail;
    this->tail = nullptr;
    this->head = nullptr;
    size_m--;
    return;
  }
  TwoWayNode<Data>* new_tail = this->tail->p_prev;
  new_tail->p_next = nullptr;
  delete this->tail;
  this->tail = new_tail;
  this->size_m--;
}

template <typename Data>
inline void TwoWayList<Data>::remove(const int index) 
{
  if (size_m == 0) return;
  if (index <= 0) {
    pop_front();
  }
  if (index >= size_m) {
    pop_back();
  }
  if (get_node_adress(index) == nullptr) return;
  TwoWayNode<Data> *to_delete = get_node_adress(index);
  TwoWayNode<Data>* back = to_delete->p_prev;
  TwoWayNode<Data>* front = to_delete->p_next;
  back->p_next = front;
  front->p_prev = back;
  delete to_delete;
  size_m--;
}

template <typename Data>
inline void TwoWayList<Data>::clean() 
{
  while (size_m != 0) {
    pop_back();
  }
}

}  // namespace TwoWayList
#endif  // TWO_WAY_LIST_H