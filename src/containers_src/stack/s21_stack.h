#ifndef S21_CONTAINERS_STACK_H_
#define S21_CONTAINERS_STACK_H_

#include "../deque/s21_deque.h"
namespace s21 {

template <typename T, typename Container = deque<T>>
class stack {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  // constructors
  stack();
  stack(const stack& other);
  stack(stack&& other);
  stack(std::initializer_list<value_type> const& items);
  ~stack();

  // operators
  stack& operator=(const stack& other);
  stack& operator=(stack&& other);

  // ACCESS
  const_reference top();

  // CAPACITY
  bool empty();
  size_type size();

  // MODIFIERS
  void push(const_reference value);
  void pop();
  void swap(stack& other);

  // ADDITIONAL
  template <typename... Args>
  void insert_many_front(Args&&... args);

 private:
  Container deque_;
};
}  // namespace s21

#include "s21_stack.tpp"
#endif /* S21_CONTAINERS_STACK_H_ */