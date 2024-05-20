#ifndef S21_CONTAINERS_STACK_H_
#define S21_CONTAINERS_STACK_H_

#include "../deque/s21_deque.h"
namespace s21 {

template <typename T, typename Container = deque<T>>
class stack {
 public:
  using size_type = std::size_t;

  // constructors
  stack();
  stack(const stack& other);
  stack(stack&& other);
  stack(std::initializer_list<T> const& items);
  ~stack();

  // operators
  stack& operator=(const stack& other);
  stack& operator=(stack&& other);

  // methods
  void push(const T& value);
  void pop();
  const T& top();
  bool empty();
  void swap(stack& other);
  size_type size();

 private:
  Container deque_;
};
}  // namespace s21

#include "s21_stack.tpp"
#endif /* S21_CONTAINERS_STACK_H_ */