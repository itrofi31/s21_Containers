#include "test.h"

class QueueSampleTest : public testing::Test {};

TEST(queue, constructor_1) {
  s21::queue<int> q;
  EXPECT_TRUE(q.empty());
}

TEST(queue, constructor_2) {
  s21::queue<int> q;
  q.push(1);
  s21::queue<int> new_q = q;
  EXPECT_EQ(q.front(), new_q.front());
}

TEST(queue, constructor_3) {
  s21::queue<int> q;
  q.push(1);
  s21::queue<int> new_q = std::move(q);
  EXPECT_EQ(new_q.front(), 1);
  EXPECT_TRUE(q.empty());
}

TEST(queue, operator_1) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> new_q;
  new_q = q;
  EXPECT_EQ(q.size(), new_q.size());
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 3);
}

TEST(queue, operator_2) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> new_q;
  new_q = std::move(q);
  EXPECT_TRUE(new_q.size() == 3);
  EXPECT_EQ(new_q.front(), 1);
  EXPECT_TRUE(q.empty());
}

TEST(queue, push) {
  s21::queue<int> q = {1, 2, 3};
  std::queue<int> std_q;
  std_q.push(1);
  std_q.push(2);
  std_q.push(3);

  EXPECT_EQ(q.size(), std_q.size());
}

TEST(queue, pop) {
  s21::queue<int> q = {1, 2, 3};
  std::queue<int> std_q;
  std_q.push(2);
  std_q.push(3);
  q.pop();

  EXPECT_EQ(q.front(), std_q.front());
  EXPECT_EQ(q.back(), std_q.back());
}

TEST(queue, swap) {
  s21::queue<int> q = {1, 2, 3};
  s21::queue<int> q2 = {1};
  q.swap(q2);

  EXPECT_TRUE(q.size() == 1);
  EXPECT_EQ(q2.back(), 3);
}

TEST(queue, insert_many_back) {
  s21::queue<int> q = {1};
  q.insert_many_back(2, 3, 4, 5);

  EXPECT_TRUE(q.size() == 5);
  EXPECT_EQ(q.back(), 5);
}