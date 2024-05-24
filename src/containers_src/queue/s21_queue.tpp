namespace s21 {

template <typename T, typename Container>
queue<T, Container>::queue() : deque_() {}

template <typename T, typename Container>
queue<T, Container>::queue(const queue& other) : deque_(other.deque_) {}

template <typename T, typename Container>
queue<T, Container>::queue(queue&& other) : deque_(std::move(other.deque_)) {}

template <typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<T> const& items)
    : deque_(items) {}

template <typename T, typename Container>
queue<T, Container>::~queue() {}  //~deque_ exists

template <typename T, typename Container>
queue<T, Container>& queue<T, Container>::operator=(const queue& other) {
  if (this != &other) {
    deque_ = other.deque_;
  }
  return *this;
}

template <typename T, typename Container>
queue<T, Container>& queue<T, Container>::operator=(queue&& other) {
  if (this != &other) {
    deque_ = std::move(other.deque_);
  }
  return *this;
}

template <typename T, typename Container>
void queue<T, Container>::push(const_reference value) {
  deque_.push_back(value);
}

template <typename T, typename Container>
void queue<T, Container>::pop() {
  deque_.pop_front();
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::front() {
  return deque_.front();
}

template <typename T, typename Container>
typename queue<T, Container>::const_reference queue<T, Container>::back() {
  return deque_.back();
}

template <typename T, typename Container>
bool queue<T, Container>::empty() {
  return deque_.empty();
}

template <typename T, typename Container>
void queue<T, Container>::swap(queue& other) {
  deque_.swap(other.deque_);
}

template <typename T, typename Container>
typename queue<T, Container>::size_type queue<T, Container>::size() {
  return deque_.size();
}

template <typename T, typename Container>
template <class... Args>
void queue<T, Container>::insert_many_back(Args&&... args) {
  (push(args), ...);
}
}  // namespace s21