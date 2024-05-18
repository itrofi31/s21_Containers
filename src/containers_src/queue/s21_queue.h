#ifndef S21_CONTAINERS_QUEUE_H_
#define S21_CONTAINERS_QUEUE_H_

#include "../dequeue/s21_deque.h"

namespace s21 {

template <typename T, typename Container = deque<T>>
class queue {
 public:
  // constructors
  queue();
  queue(const queue<T>& other);
  queue(queue<T>&& other);
  queue(std::initializer_list<T> const& items);
  ~queue();

  // operators

 private:
  Container deque_;
};

}  // namespace s21

#endif /* S21_CONTAINERS_QUEUE_H_ */