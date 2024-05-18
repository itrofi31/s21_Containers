#ifndef S21_CONTAINERS_DEQUE_H_
#define S21_CONTAINERS_DEQUE_H_

#include <iostream>
#include <utility>

namespace s21 {

template <typename T>
class deque {
 public:
  // constructors
  deque();
  deque(const deque<T>& other);
  deque(deque<T>&& other);
  deque(std::initializer_list<T> const& items);
  ~deque();

  // operators
  deque<T>& operator=(const deque<T>& other);
  deque<T>& operator=(deque<T>&& other);

  // methods
  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();

  const T& front();
  const T& back();
  bool empty();
  void swap(deque<T>& other);
  void clear();
  std::size_t size();

 protected:
  struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  std::size_t size_;
};

}  // namespace s21

#endif /* S21_CONTAINERS_DEQUE_H_ */