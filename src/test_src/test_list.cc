#include <iostream>

#include "test.h"

class ListSampleTest : public testing::Test {};

// TEST_F(ListSampleTest, test1) {
//   s21::list<int> list;
//   std::list<int> slist;
//   EXPECT_EQ(list.max_size(), slist.max_size());
// }
TEST(test, test1) {
  // s21::list<int> list = {1, 3, 2, 4};
  s21::list<int> slist = {1, 3, 2, 4};
  s21::list<int>::iterator it;
  // slist.merge(list);
  for (it = slist.begin(); it != slist.end(); it++) std::cout << " " << *it;
  std::cout << std::endl;
  // list.reverse();
  // slist.reverse();

  // list.reverse();

  // for (size_t i = 0; i < 4; i++) {
  //   std::cout << list.front() << " - ";
  //   list.pop_front();
  // }
  // std::cout << '\n';
  // for (size_t i = 0; i < slist.size(); i++) {
  //   std::cout << "slist" << slist.front() << ' ';
  //   slist.pop_front();
  // }
  // ASSERT_EQ(list.reverse() slist.reverse());
}