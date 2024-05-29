#include <iostream>

#include "test.h"

TEST(List, constructor_1) {
  s21::list<int> l;
  EXPECT_TRUE(l.empty());
}

TEST(List, constructor_2) {
  s21::list<int> l;
  l.push_back(1);
  s21::list<int> new_l = l;
  EXPECT_EQ(l.front(), new_l.front());
}

TEST(List, constructor_3) {
  s21::list<int> l;
  l.push_back(1);
  s21::list<int> new_l = std::move(l);
  EXPECT_EQ(new_l.front(), 1);
  EXPECT_TRUE(l.empty());
}

TEST(List, constructor_4) {
  s21::list<int> l(5);
  EXPECT_TRUE(l.size() == 5);
}

TEST(List, operator_1) {
  s21::list<int> l = {1, 2, 3, 4, 5};
  s21::list<int> l2;
  l2 = l;
  EXPECT_EQ(l.size(), l2.size());
  EXPECT_EQ(l.front(), l2.front());
}

TEST(List, operator_2) {
  s21::list<int> l = {1, 2, 3, 4, 5};
  s21::list<int> l2;
  l2 = std::move(l);
  EXPECT_EQ(l2.front(), 1);
  EXPECT_TRUE(l.empty());
}

TEST(List, const_iterator) {
  s21::list<int> list;
  list.push_back(1);
  s21::list<int>::const_iterator it;
  s21::list<int>::const_iterator it_end;
  it = list.cbegin();
  it_end = list.cend();
  EXPECT_EQ(*it, 1);
}

TEST(List, end) {
  s21::list<int> list;
  s21::list<int>::iterator it;
  it = list.end();
  EXPECT_ANY_THROW(*it);
}

TEST(List, cend) {
  s21::list<int> list;
  s21::list<int>::const_iterator it;
  it = list.cend();
  EXPECT_ANY_THROW(*it);
}

TEST(List, decrement) {
  s21::list<int> list{1, 2};
  s21::list<int>::iterator it;
  it = list.begin();
  it++;
  it--;
  EXPECT_EQ(*it, 1);
}

TEST(List, decrement_2) {
  s21::list<int> list = {4, 5};
  s21::list<int>::iterator it = list.end();
  it--;
  EXPECT_EQ(*it, 5);
}

TEST(List, decrement_throw) {
  s21::list<int> list = {5};
  s21::list<int>::iterator it = list.begin();

  EXPECT_ANY_THROW(it--;);
}

TEST(List, decrement_throw_2) {
  s21::list<int> list = {5};
  s21::list<int>::iterator it = list.begin();

  EXPECT_ANY_THROW(--it);
}

TEST(List, max_size) {
  s21::list<int> list;
  std::list<int> slist;
  EXPECT_EQ(list.max_size(), slist.max_size() / 2);
}

TEST(List, erase) {
  s21::list<int> list{1, 2, 3};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.erase(it);
  EXPECT_EQ(list.size(), size_t(2));
  EXPECT_EQ(list.back(), 3);
}

TEST(List, erase_2) {
  s21::list<int> list{1, 2};
  s21::list<int>::iterator it = list.begin();
  list.erase(it);
  EXPECT_TRUE(list.size() == 1);
  EXPECT_EQ(list.back(), 2);
}

TEST(List, erase_3) {
  s21::list<int> list{1, 2};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.erase(it);
  EXPECT_TRUE(list.size() == 1);
  EXPECT_EQ(list.back(), 1);
}

TEST(List, reverse) {
  s21::list<int> list = {1, 3, 2};
  std::list<int> slist = {2, 3, 1};
  s21::list<int>::iterator it;
  list.reverse();

  EXPECT_EQ(list.front(), slist.front());
  list.pop_front();
  slist.pop_front();
  EXPECT_EQ(list.front(), slist.front());
}

TEST(List, unique) {
  s21::list<int> list = {1, 1, 2, 2, 2, 3};
  s21::list<int> slist = {1, 2, 3};
  list.unique();
  s21::list<int>::iterator it = list.begin();
  s21::list<int>::iterator sit = slist.begin();

  EXPECT_EQ(*it++, *sit++);
  EXPECT_EQ(*it++, *sit++);
  EXPECT_EQ(*it, *sit);
}

TEST(List, splice) {
  s21::list<int> list = {1, 5, 6};
  s21::list<int> slist = {2, 3, 4};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.splice(it, slist);
  it = list.begin();
  for (int i = 1; i < 7; ++i, ++it) {
    EXPECT_EQ(*it, i);
  }
  EXPECT_TRUE(slist.empty());
}

TEST(List, insert_many) {
  s21::list<int> list = {1, 5, 6};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.insert_many(it, 2, 3, 4);
  it = list.begin();
  for (int i = 1; i < 7; ++i, ++it) {
    EXPECT_EQ(*it, i);
  }
}

TEST(List, insert_many_back) {
  s21::list<int> list = {1, 2, 3};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.insert_many_back(4, 5, 6);
  it = list.begin();
  for (int i = 1; i < 7; ++i, ++it) {
    EXPECT_EQ(*it, i);
  }
}

TEST(List, insert_many_front) {
  s21::list<int> list = {4, 5, 6};
  s21::list<int>::iterator it = list.begin();
  it++;
  list.insert_many_front(3, 2, 1);
  it = list.begin();
  for (int i = 1; i < 7; ++i, ++it) {
    EXPECT_EQ(*it, i);
  }
}

TEST(List, sort) {
  s21::list<int> list = {4, 1, 6, 0, -21, 10};
  std::list<int> slist = {4, 1, 6, 0, -21, 10};

  list.sort();
  slist.sort();
  auto it = slist.begin();
  for (const auto& i : list) {
    EXPECT_EQ(i, *it++);
  }
}

TEST(List, merge) {
  s21::list<int> list = {4, 1, 6, 0, -21, 10};
  s21::list<int> slist = {99, -99};
  s21::list<int> expected = {-99, -21, 0, 1, 4, 6, 10, 99};
  list.sort();
  slist.sort();
  list.merge(slist);
  auto it = expected.begin();

  for (const auto& i : list) {
    EXPECT_EQ(i, *it++);
  }
  EXPECT_TRUE(slist.empty());
}

TEST(List, pop_back) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  EXPECT_TRUE(list.size() == 1);
  EXPECT_EQ(list.front(), 1);
}

TEST(List, swap) {
  s21::list<int> list = {1, 2, 3, 4, 5};
  s21::list<int> list2;
  list.swap(list2);
  EXPECT_TRUE(list2.size() == 5);
  EXPECT_TRUE(list.empty());
}