namespace s21 {

template <typename T>
list<T>::ListIterator::ListIterator() : ptr_(nullptr) {}

template <typename T>
list<T>::ListIterator::ListIterator(typename deque<T>::Node* ptr) : ptr_(ptr) {}

template <typename T>
typename list<T>::reference list<T>::ListIterator::operator*() const {
  if (ptr_) {
    return ptr_->data;
  }
  throw std::invalid_argument("pointer is nullptr");
}

template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator++() {
  return ptr_ = ptr_->next;
}

template <typename T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator tmp = *this;
  ptr_ = ptr_->next;
  return tmp;
}

template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator--() {
  ptr_ = ptr_->prev;
}

template <typename T>
typename list<T>::ListIterator list<T>::ListIterator::operator--(int) {
  ListIterator tmp = *this;
  ptr_ = ptr_->prev;
  return tmp;
}

template <typename T>
bool list<T>::ListIterator::operator==(const ListIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool list<T>::ListIterator::operator!=(const ListIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
list<T>::ListConstIterator::ListConstIterator() : ListIterator() {}

template <typename T>
typename list<T>::const_reference s21::list<T>::ListConstIterator::operator*()
    const {
  return ListIterator::operator*();
}

template <typename T>
list<T>::ListConstIterator::ListConstIterator(const ListIterator& ptr_)
    : ListIterator(ptr_) {}

template <typename T>
list<T>::list() : deque<T>() {}

template <typename T>
list<T>::list(size_type n) : list() {
  if (n > 0) {
    for (size_type i = 0; i < n; i++) {
      deque<T>::push_back(0);
    }
  }
}

template <typename T>
list<T>::list(const list& other) : deque<T>(other) {}

template <typename T>
list<T>::list(list&& other) : deque<T>(std::move(other)) {}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items)
    : deque<T>(items) {}

template <typename T>
list<T>::~list() {}

template <typename T>
list<T>& list<T>::operator=(const list& other) {
  if (this != &other) {
    deque<T>::operator=(other);
  }
  return *this;
}

template <typename T>
list<T>& list<T>::operator=(list&& other) {
  if (this != &other) {
    deque<T>::operator=(std::move(other));
  }
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  return deque<T>::front();
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  return deque<T>::back();
}
template <typename T>
bool list<T>::empty() {
  return deque<T>::empty();
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return deque<T>::size();
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return (std::numeric_limits<size_type>::max() /
          sizeof(typename deque<T>::Node) / 2);
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(deque<T>::head_);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return deque<T>::head_ ? iterator(deque<T>::tail_->next) : begin();
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(deque<T>::head_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return deque<T>::head_ ? const_iterator(deque<T>::tail_->next) : begin();
}

// template <typename T>
// typename list<T>::iterator list<T>::insert(iterator pos,
//                                            const_reference value) {}

template <typename T>
void list<T>::push_back(const_reference value) {
  deque<T>::push_back(value);
}

template <typename T>
void list<T>::pop_back() {
  deque<T>::pop_back();
}

template <typename T>
void list<T>::push_front(const_reference value) {
  deque<T>::push_front(value);
}

template <typename T>
void list<T>::pop_front() {
  deque<T>::pop_front();
}

template <typename T>
void list<T>::swap(list& other) {
  deque<T>::swap(other);
}

// template <typename T>
// void list<T>::merge(list& other) {}

// template <typename T>
// void list<T>::splice(const_iterator pos, list& other) {}

template <typename T>
void list<T>::reverse() {
  if (size() > 1) {
    typename deque<T>::Node* cur = deque<T>::head_;
    while (cur != nullptr) {
      std::swap(cur->next, cur->prev);
      cur = cur->prev;
    }
    std::swap(deque<T>::head_, deque<T>::tail_);
  }
}

// template <typename T>
// void list<T>::unique() {}

// template <typename T>
// void list<T>::sort() {}

// template <typename T>
// void list<T>::erase(iterator pos) {}

template <typename T>
void list<T>::clear() {
  deque<T>::clear();
}
}  // namespace s21