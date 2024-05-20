#ifndef S21_CONTAINERS_QUEUE_H_
#define S21_CONTAINERS_QUEUE_H_

#include "../deque/s21_deque.h"

// STL reference
// https://en.cppreference.com/w/cpp/container/queue

namespace s21 {

template <typename T, typename Container = deque<T>>
class queue {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  // constructors
  queue();
  queue(const queue& other);
  queue(queue&& other);
  queue(std::initializer_list<value_type> const& items);
  ~queue();

  // operators
  queue& operator=(const queue& other);
  queue& operator=(queue&& other);

  // ACCESS
  const_reference front();
  const_reference back();

  // CAPACITY
  bool empty();
  size_type size();

  // MODIFIERS
  void push(const_reference value);
  void pop();
  void swap(queue& other);

  // ADDITIONAL

  template <class... Args>
  void insert_many_back(Args&&... args);

 private:
  Container deque_;
};

}  // namespace s21
#include "s21_queue.tpp"
#endif /* S21_CONTAINERS_QUEUE_H_ */