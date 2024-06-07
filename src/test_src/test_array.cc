#include "test.h"

TEST(Array, constructor_1) {
  s21::array<int, 2> arr = {21, 42};
  s21::array<int, 2> arr2(arr);
  EXPECT_EQ(arr.at(0), arr2.at(0));
  EXPECT_EQ(arr.at(1), arr2.at(1));
}

TEST(Array, constructor_2) {
  s21::array<int, 2> arr = {21, 42};
  s21::array<int, 2> arr2 = std::move(arr);

  EXPECT_EQ(21, arr2.at(0));
  EXPECT_EQ(42, arr2.at(1));
}

TEST(Array, swap) {
  s21::array<int, 2> arr = {901, 2};
  s21::array<int, 2> arr2 = {0, 0};
  arr.swap(arr2);
  EXPECT_EQ(arr[0], 0);
  EXPECT_EQ(arr2[0], 901);
  EXPECT_EQ(arr[1], 0);
  EXPECT_EQ(arr2[1], 2);
}
TEST(Array, fill) {
  s21::array<int, 2> arr = {901, 2};
  arr.fill(21);
  EXPECT_EQ(arr.at(0), 21);
  EXPECT_EQ(arr.at(1), 21);
}

TEST(Array, operator_eq) {
  s21::array<int, 2> arr = {21, 42};
  s21::array<int, 2> arr2;
  arr2 = std::move(arr);

  EXPECT_EQ(arr2.front(), 21);
  EXPECT_EQ(arr2[1], 42);
  EXPECT_TRUE(arr2.size() == 2);
}

TEST(Array, operator_eq_2) {
  s21::array<int, 2> arr = {21, 42};
  s21::array<int, 2> arr2;
  arr2 = arr;
  auto it = arr.begin();
  auto it2 = arr2.begin();
  for (; it != arr.end(); it++, it2++) {
    EXPECT_EQ(*it, *it2);
  }
}

TEST(Array, front) {
  s21::array<int, 2> arr = {21, 42};
  EXPECT_EQ(arr.front(), 21);
}

TEST(Array, back) {
  s21::array<int, 2> arr = {21, 42};
  EXPECT_EQ(arr.back(), 42);
}

TEST(Array, begin) {
  s21::array<int, 2> arr = {21, 42};
  EXPECT_EQ(*(arr.begin()), 21);
}

TEST(Array, data) {
  s21::array<int, 2> arr = {21, 42};
  int* first = arr.data();
  EXPECT_EQ(*(first), 21);
}

TEST(Array, empty) {
  s21::array<int, 0> arr;
  EXPECT_TRUE(arr.empty());
}

TEST(Array, max_size) {
  s21::array<int, 5> arr = {1, 2, 3, 4, 5};
  EXPECT_TRUE(arr.max_size() == size_t(5));
}