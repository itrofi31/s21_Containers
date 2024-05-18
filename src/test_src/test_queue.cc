#include "test.h"

class QueueSampleTest : public testing::Test {};

TEST_F(QueueSampleTest, test1) {
  s21::queue<int> q{1, 2, 3};
  for (int i = 0; i < 3; i++) {
  }
}