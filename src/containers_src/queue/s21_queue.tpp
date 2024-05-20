
// #include "s21_queue.h"

// using namespace s21;
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
void queue<T, Container>::push(const T& value) {
  deque_.push_back(value);
}

template <typename T, typename Container>
void queue<T, Container>::pop() {
  deque_.pop_front();
}

template <typename T, typename Container>
const T& queue<T, Container>::front() {
  return deque_.front();
}

template <typename T, typename Container>
const T& queue<T, Container>::back() {
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
std::size_t queue<T, Container>::size() {
  return deque_.size();
}
}  // namespace s21