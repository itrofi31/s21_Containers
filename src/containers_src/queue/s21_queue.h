#ifndef S21_CONTAINERS_QUEUE_H_
#define S21_CONTAINERS_QUEUE_H_

#include <iostream>

#include "../deque/s21_deque.h"
namespace s21 {

template <typename T, typename Container = deque<T>>
class queue {
 public:
  // constructors
  queue();
  queue(const queue& other);
  queue(queue&& other);
  queue(std::initializer_list<T> const& items);
  ~queue();

  // operators
  queue& operator=(const queue& other);
  queue& operator=(queue&& other);

  // methods
  void push(const T& value);
  void pop();
  const T& front();
  const T& back();
  bool empty();
  std::size_t size();

 private:
  Container deque_;
};

}  // namespace s21
#include "s21_queue.tpp"
#endif /* S21_CONTAINERS_QUEUE_H_ */