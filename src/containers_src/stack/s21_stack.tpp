namespace s21 {

// constructors
template <typename T, typename Container>
stack<T, Container>::stack() : deque_() {}

template <typename T, typename Container>
stack<T, Container>::stack(const stack& other) : deque_(other.deque_) {}

template <typename T, typename Container>
stack<T, Container>::stack(stack&& other) : deque_(std::move(other.deque_)) {}

template <typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<T> const& items)
    : deque_(items) {}

template <typename T, typename Container>
stack<T, Container>::~stack() {}

// operators
template <typename T, typename Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
  if (this != &other) {
    deque_ = other.deque_;
  }
  return *this;
}

template <typename T, typename Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& other) {
  if (this != &other) {
    deque_ = std::move(other.deque_);
  }
  return *this;
}

// methods
template <typename T, typename Container>
void stack<T, Container>::push(const_reference value) {
  deque_.push_front(value);
}

template <typename T, typename Container>
void stack<T, Container>::pop() {
  deque_.pop_front();
}

template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() {
  return deque_.front();
}

template <typename T, typename Container>
bool stack<T, Container>::empty() {
  return deque_.empty();
}

template <typename T, typename Container>
void stack<T, Container>::swap(stack& other) {
  deque_.swap(other.deque_);
}

template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() {
  return deque_.size();
}

template <typename T, typename Container>
template <typename... Args>
void stack<T, Container>::insert_many_front(Args&&... args) {
  (push(args), ...);
}
}  // namespace s21