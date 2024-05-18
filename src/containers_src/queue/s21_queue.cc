#include "s21_queue.h"

using namespace s21;

template <typename T>
dequeue<T>::dequeue() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
dequeue<T>::dequeue(const dequeue<T>& other)
    : head_(nullptr), tail_(nullptr), size_(0) {
  Node* current = other.head_;
  while (current != nullptr) {
    push(current->data);
    current = current->next;
  }
}

template <typename T>
dequeue<T>::dequeue(dequeue<T>&& other)
    : head_(other.head_), tail_(other.tail_), size_(other.size_) {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <typename T>
dequeue<T>::dequeue(std::initializer_list<T> const& items)
    : head_(nullptr), tail_(nullptr) {
  for (const T& i : items) {
    push(i);
  }
}

template <typename T>
dequeue<T>::~dequeue() {
  clear();
}

template <typename T>
void dequeue<T>::push_front(const T& value) {
  Node* new_node = new Node(value);
  new_node->next = head_;
  new_node->prev = nullptr;
  if (head_ != nullptr) {
    head_->prev = new_node;
  }
  head_ = new_node;
  if (tail_ == nullptr) {
    tail_ = new_node;
  }
  size_++;
}

template <typename T>
void dequeue<T>::push_back(const T& value) {
  Node* new_node = new Node(value);
  new_node->next = nullptr;
  new_node->prev = tail_;
  if (tail_ != nullptr) {
    tail_->next = new_node;
  }
  tail_ = new_node;
  if (head_ == nullptr) {
    head_ = new_node;
  }
  size_++;
}

template <typename T>
void dequeue<T>::pop_front() {
  if (!empty()) {
    Node* new_head = head_->next;
    delete head_;
    head_ = new_head;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    size_--;
  }
}

template <typename T>
void dequeue<T>::pop_back() {
  if (!empty()) {
    Node* new_back = tail_->prev;
    delete tail_;
    tail_ = new_back;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    size_--;
  }
}

template <typename T>
dequeue<T>& dequeue<T>::operator=(const dequeue<T>& other) {
  if (this != &other) {
    clear();
    for (Node* current = other.head_; current != nullptr;
         current = current->next) {
      push_back(current->data);
    }
  }
  return *this;
}

template <typename T>
dequeue<T>& dequeue<T>::operator=(dequeue<T>&& other) {
  if (this != &other) {
    clear();
    swap(other);
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
const T& dequeue<T>::front() {
  if (!empty()) {
    return head_->data;
  }
  throw("dequeue is empty");
}

template <typename T>
const T& dequeue<T>::back() {
  if (tail_ != nullptr) {
    return tail_->data;
  }
  throw("dequeue is empty");
}

template <typename T>
bool dequeue<T>::empty() {
  return (head_ == nullptr);
}

template <typename T>
void dequeue<T>::swap(dequeue<T>& other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <typename T>
void dequeue<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
std::size_t dequeue<T>::size() {
  return size_;
}

int main() {
  s21::dequeue<int> q;
  q.push_back(1);
  q.push_back(2);
  q.push_back(3);

  while (!q.empty()) {
    std::cout << q.front() << ' ';
    q.pop_front();
  }
}