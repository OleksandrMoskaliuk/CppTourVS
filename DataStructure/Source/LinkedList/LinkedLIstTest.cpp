#include <iostream>

#include "LinkedList.h"
#include "gtest/gtest.h"

namespace LinkedList {

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "LinkedList";
  RUN_ALL_TESTS();
}

TEST(LinkedList, set_bit_testing) {
  
  EXPECT_EQ(1,1);
}


}  // namespace LinkedList