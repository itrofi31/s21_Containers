
#include "s21_array.h"

namespace s21 {
template <typename T, std::size_t N>
array<T, N>::array() : size_(N) {}

template <typename T, std::size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  int i = 0;
  for (const auto &item : items) {
    if (i != N) data_[i++] = item;
  }
  size_ = i;
}

template <typename T, std::size_t N>
array<T, N>::array(const array &a) : size_(N) {
  for (size_type i = 0; i < N; i++) {
    (*this)[i] = a.data_[i];
  }
}

template <typename T, std::size_t N>
array<T, N>::array(array &&a) : size_(N) {
  for (size_type i = 0; i < N; i++) {
    (*this)[i] = std::move(a.data_[i]);
  }
}

template <typename T, std::size_t N>
array<T, N>::~array() {}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  return (*this)[pos];
}

template <typename T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos < 0 || pos >= size_) throw std::out_of_range("Incorrect index");
  return data_[pos];
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  if (this != &a) {
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = a.data_[i];
    }
  }
  return *this;
}

template <typename T, std::size_t N>
array<T, N> &array<T, N>::operator=(array &&a) {
  if (this != &a) {
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = std::move(a.data_[i]);
    }
  }
  return *this;
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  return data_[0];
}

template <typename T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  return data_[N - 1];
}

template <typename T, std::size_t N>
T *array<T, N>::data() {
  return data_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return data_;
}

template <typename T, std::size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return data_ + N;
}

template <typename T, std::size_t N>
bool array<T, N>::empty() {
  return size_ == 0;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return size_;
}

template <typename T, std::size_t N>
void array<T, N>::swap(array &other) {
  for (size_type i = 0; i < N; ++i) {
    std::swap((*this)[i], other[i]);
  }
}

template <typename T, std::size_t N>
void array<T, N>::fill(const_reference value) {
  for (auto &item : data_) {
    item = value;
  }
}

}  // namespace s21