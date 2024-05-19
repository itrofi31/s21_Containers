#include "test.h"

class QueueSampleTest : public testing::Test {};

TEST(QueueSampleTest, test1) {
  s21::queue<int> q = {1, 2, 3};
  std::queue<int> std_q;
  std_q.push(1);
  std_q.push(2);
  std_q.push(3);

  EXPECT_EQ(q.size(), std_q.size());
}