#ifndef S21_CONTAINERS_LIST_H_
#define S21_CONTAINERS_LIST_H_

#include <limits>

#include "../deque/s21_deque.h"

// STL reference
// https://en.cppreference.com/w/cpp/container/list

namespace s21 {
template <typename T>
class list : public deque<T> {
 public:
  class ListIterator;
  class ListConstIterator;

  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = std::size_t;

  class ListIterator {
    friend class list<T>;

   public:
    ListIterator();
    ListIterator(typename deque<T>::Node* ptr, list<T>* parent);
    reference operator*() const;

    ListIterator& operator++();
    ListIterator operator++(int);
    ListIterator& operator--();
    ListIterator operator--(int);

    bool operator==(const ListIterator& other) const;
    bool operator!=(const ListIterator& other) const;

   protected:
    typename deque<T>::Node* ptr_;
    list<T>* parent_;
    // typename deque<T>::Node* last_node_;
  };  // class ListIterator

  class ListConstIterator : ListIterator {
    friend class list<T>;

   public:
    ListConstIterator();
    ListConstIterator(const ListIterator& ptr_);
    ListConstIterator(typename deque<T>::Node* ptr, const list<T>* parent);

    const_reference operator*() const;
  };  // class ListConstIterator

  // constructors
  list();
  list(size_type n);
  list(const list& other);
  list(list&& other);
  list(std::initializer_list<value_type> const& items);
  ~list();

  // operators
  list& operator=(const list& other);
  list& operator=(list&& other);

  // ACCESS

  const_reference front();
  const_reference back();

  // ITERATORS

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  // CAPACITY

  bool empty();
  size_type size();
  size_type max_size();

  // MODIFIERS

  iterator insert(iterator pos, const_reference value);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
  void erase(iterator pos);
  void clear();

  // ADDITIONAL

  template <class... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  template <class... Args>
  void insert_many_back(Args&&... args);
  template <class... Args>
  void insert_many_front(Args&&... args);

 private:
  void quickSort(iterator first, iterator last);
  iterator partition(iterator first, iterator last);
};  // class list
}  // namespace s21

#include "s21_list.tpp"
#endif /* S21_CONTAINERS_LIST_H_ */