#include "test.h"

TEST(Stack, constructor_1) {
  s21::stack<int> s;
  EXPECT_TRUE(s.empty());
}

TEST(Stack, constructor_2) {
  s21::stack<int> s = {1, 2, 3, 4, 5};
  s21::stack<int> s2 = std::move(s);
  EXPECT_TRUE(s2.size() == 5);
  EXPECT_TRUE(s.empty());
}

TEST(Stack, constructor_3) {
  s21::stack<int> s = {1, 2, 3, 4, 5};
  s21::stack<int> s2 = s;
  EXPECT_TRUE(s2.size() == 5);
  EXPECT_TRUE(s.top() == s2.top());
}

TEST(Stack, operator_1) {
  s21::stack<int> s = {1, 2, 3, 4, 5};
  s21::stack<int> s2;
  s2 = s;
  EXPECT_EQ(s.size(), s2.size());
  EXPECT_EQ(s.top(), s2.top());
}

TEST(Stack, operator_2) {
  s21::stack<int> s = {1, 2, 3, 4, 5};
  s21::stack<int> s2;
  s2 = std::move(s);
  EXPECT_TRUE(s2.size() == 5);
  EXPECT_TRUE(s.empty());
}

TEST(Stack, push) {
  s21::stack<int> s;
  std::stack<int> std_s;
  for (int i = 0; i < 3; i++) {
    s.push(i);
    std_s.push(i);
    EXPECT_EQ(s.top(), std_s.top());
  }
}

TEST(Stack, pop) {
  s21::stack<int> s;
  std::stack<int> std_s;
  for (int i = 0; i < 3; i++) {
    s.push(i);
    std_s.push(i);
  }
  s.pop();
  std_s.pop();
  EXPECT_EQ(s.top(), std_s.top());
  EXPECT_TRUE(s.size() == 2);
}

TEST(Stack, swap) {
  s21::stack<int> s = {1, 2, 3, 4, 5};
  s21::stack<int> s2 = {21};
  s.swap(s2);
  EXPECT_TRUE(s2.size() == 5);
  EXPECT_TRUE(s.size() == 1);
  EXPECT_EQ(s.top(), 21);
}

TEST(Stack, insert_many) {
  s21::stack<int> s;
  s.insert_many_front(1, 2, 3, 4, 5);
  EXPECT_TRUE(s.size() == 5);
}