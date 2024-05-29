namespace s21 {

template <typename T>
list<T>::ListIterator::ListIterator() : ptr_(nullptr), parent_(nullptr) {}

template <typename T>
list<T>::ListIterator::ListIterator(typename deque<T>::Node* ptr,
                                    list<T>* parent)
    : ptr_(ptr), parent_(parent) {}

template <typename T>
typename list<T>::reference list<T>::ListIterator::operator*() const {
  if (ptr_) {
    return ptr_->data;
  }
  throw std::invalid_argument("pointer is nullptr");
}

template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator++() {
  if (ptr_) ptr_ = ptr_->next;
  return *this;
}

template <typename T>
typename list<T>::ListIterator list<T>::ListIterator::operator++(int) {
  ListIterator tmp = *this;
  if (ptr_) ptr_ = ptr_->next;
  return tmp;
}

template <typename T>
typename list<T>::ListIterator& list<T>::ListIterator::operator--() {
  if (ptr_ == nullptr) {
    ptr_ = parent_->tail_;
  } else if (ptr_->prev != nullptr) {
    ptr_ = ptr_->prev;
  } else {
    throw std::out_of_range("Iterator cannot be decremented");
  }
  return *this;
}

template <typename T>
typename list<T>::ListIterator list<T>::ListIterator::operator--(int) {
  ListIterator tmp = *this;
  if (ptr_ == nullptr) {
    ptr_ = parent_->tail_;
  } else if (ptr_->prev != nullptr) {
    ptr_ = ptr_->prev;
  } else {
    throw std::out_of_range("Iterator cannot be decremented");
  }
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
list<T>::ListConstIterator::ListConstIterator(typename deque<T>::Node* ptr,
                                              const list<T>* parent)
    : ListIterator(ptr, const_cast<list<T>*>(parent)) {}

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
  return iterator(this->head_, this);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  if (this->tail_)
    return iterator(this->tail_->next, this);
  else
    return iterator(nullptr, this);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(this->head_, this);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  if (this->tail_)
    return const_iterator(this->tail_->next, this);
  else
    return const_iterator(nullptr, this);
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    return begin();
  } else if (pos == end()) {
    push_back(value);
    return --end();
  } else {
    typename deque<T>::Node* cur = pos.ptr_;
    typename deque<T>::Node* new_node = new typename deque<T>::Node(value);
    new_node->prev = cur->prev;
    cur->prev->next = new_node;
    cur->prev = new_node;
    new_node->next = cur;
    return iterator(new_node, this);
  }
}

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

template <typename T>
void list<T>::merge(list& other) {
  if (this == &other) return;

  iterator it1 = begin();
  iterator it2 = other.begin();

  while (it1 != end() && it2 != other.end()) {
    if (*it2 < *it1) {
      this->insert(it1, *it2);
      ++it2;
    }
    ++it1;
  }

  while (it2 != other.end()) {
    this->insert(it1, *it2);
    ++it2;
  }

  other.clear();
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (this != &other && !other.empty()) {
    iterator pos_it = pos;

    while (!other.empty()) {
      iterator it = other.begin();
      insert(pos_it, *it);
      other.pop_front();
    }
  }
}

template <typename T>
void list<T>::reverse() {
  if (size() > 1) {
    typename deque<T>::Node* cur = deque<T>::head_;
    while (cur != nullptr) {
      std::swap(cur->next, cur->prev);
      cur = cur->prev;
    }
    std::swap(this->head_, this->tail_);
  }
}

template <typename T>
void list<T>::unique() {
  if (begin() != end()) {
    iterator it = begin();
    while (it != end()) {
      iterator next = it;
      ++next;
      while (next != end() && *it == *next) {
        erase(next);
        next = it;
        ++next;
      }
      ++it;
    }
  }
}
template <typename T>

void list<T>::sort() {
  if (!empty()) {
    quickSort(begin(), --end());
  }
}

template <typename T>
void list<T>::quickSort(iterator first, iterator last) {
  if (first != last && first.ptr_ != nullptr) {
    iterator pivot = partition(first, last);
    if (pivot != first) {
      iterator before_pivot = pivot;
      --before_pivot;
      quickSort(first, before_pivot);
    }
    quickSort(pivot, last);
  }
}

template <typename T>
typename list<T>::iterator list<T>::partition(iterator first, iterator last) {
  T pivot_value = *last;
  iterator i = first;

  for (iterator j = first; j != last; ++j) {
    if (*j < pivot_value) {
      if (i != j) {
        std::swap(*i, *j);
      }
      ++i;
    }
  }
  std::swap(*i, *last);
  return i;
}

template <typename T>
void list<T>::erase(iterator pos) {
  typename deque<T>::Node* cur = pos.ptr_;
  typename deque<T>::Node* next_node = cur->next;
  if (pos != end()) {
    if (cur->prev) {
      cur->prev->next = next_node;
    } else {
      this->head_ = next_node;
    }

    if (next_node) {
      next_node->prev = cur->prev;
    } else {
      this->tail_ = cur->prev;
    }

    delete cur;
    this->size_--;
  }
}

template <typename T>
void list<T>::clear() {
  deque<T>::clear();
}

template <typename T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  ((insert(pos, args)), ...);
  return pos;
}

template <typename T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  ((push_back(args)), ...);
}

template <typename T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  ((push_front(args)), ...);
}
}  // namespace s21