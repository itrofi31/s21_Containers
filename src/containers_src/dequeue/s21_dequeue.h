#ifndef S21_CONTAINERS_DEQUEUE_H_
#define S21_CONTAINERS_DEQUEUE_H_

#include <iostream>
#include <utility>

namespace s21 {

template <typename T>
class dequeue {
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

 public:
  // constructors
  dequeue();
  dequeue(const dequeue<T>& other);
  dequeue(dequeue<T>&& other);
  dequeue(std::initializer_list<T> const& items);
  ~dequeue();

  // methods
  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();

  // operators
  dequeue<T>& operator=(const dequeue<T>& other);
  dequeue<T>& operator=(dequeue<T>&& other);

  const T& front();
  const T& back();
  bool empty();
  void swap(dequeue<T>& other);
  void clear();

  std::size_t size();
};

}  // namespace s21

#endif /* S21_CONTAINERS_DEQUEUE_H_ */