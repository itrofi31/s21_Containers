#ifndef S21_CONTAINERS_DEQUE_H_
#define S21_CONTAINERS_DEQUE_H_

#include <cstddef>           // std::size_t
#include <initializer_list>  // std::initializer_list
#include <utility>           //std::swap

namespace s21 {

template <typename T>
class deque {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  // constructors
  deque();
  deque(const deque& other);
  deque(deque&& other);
  deque(std::initializer_list<value_type> const& items);
  ~deque();

  // operators
  deque& operator=(const deque& other);
  deque& operator=(deque&& other);

  // methods
  void push_front(const_reference value);
  void push_back(const_reference value);
  void pop_front();
  void pop_back();

  const_reference front();
  const_reference back();
  bool empty();
  void swap(deque& other);
  void clear();
  size_type size();

 protected:
  struct Node {
    value_type data;
    Node* next;
    Node* prev;
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  std::size_t size_;
};

}  // namespace s21
#include "s21_deque.tpp"

#endif /* S21_CONTAINERS_DEQUE_H_ */