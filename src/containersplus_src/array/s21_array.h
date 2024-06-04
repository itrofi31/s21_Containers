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
  using iterator = ArrayIterator;
  using const_iterator = ArrayConstIterator;
  using size_type = std::size_t;

  class ArrayIterator {
    friend class array<T>;

   public:
    ArrayIterator();

    reference operator*() const;

    ArrayIterator &operator++();
    ArrayIterator &operator--();

    bool operator==(const ArrayIterator &other) const;
    bool operator!=(const ArrayIterator &other) const;
  };  // class ArrayIterator

  class ArrayConstIterator {
    friend class array<T>;

   public:
    ArrayConstIterator();

    const_reference operator*() const;

    ArrayConstIterator &operator++();
    ArrayConstIterator &operator--();

    bool operator==(const ArrayConstIterator &other) const;
    bool operator!=(const ArrayConstIterator &other) const;
  };  // class ArrayConstIterator

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
  T *data();

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