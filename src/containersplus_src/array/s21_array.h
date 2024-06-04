#ifndef S21_CONTAINERSPLUS_ARRAY_H_
#define S21_CONTAINERSPLUS_ARRAY_H_

#include <cstddef>           // std::size_t
#include <initializer_list>  // std::initializer_list

// STL reference
// https://en.cppreference.com/w/cpp/container/array

namespace s21 {
template <typename T, std::size_t N>
class array {
 public:
  class ArrayIterator;
  class ArrayConstIterator;

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = ArrayConstIterator;
  using size_type = std::size_t;

  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array();
  array &operator=(array &&a);

  // ACCESS

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // ITERATORS

  iterator begin();
  iterator end();

  // CAPACITY

  bool empty();
  size_type size();
  size_type max_size();

  // MODIFIERS

  void swap(array &other);
  void fill(const_reference value);

  // https://google.github.io/styleguide/cppguide.html#Access_Control
 protected:
 private:
  value_type data_[N]{};
  size_type size_ = N;
};  // class array
}  // namespace s21

#include "s21_array.tpp"

#endif  // S21_CONTAINERSPLUS_ARRAY_H_