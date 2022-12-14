#pragma once
#include "../byte.h"
#include "gtest/gtest.h"
#include <iostream>

namespace byte {
namespace test {
struct byte_testing : testing::Test
{

};

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc,argv);
  testing::GTEST_FLAG(filter) = "byte_testing*";
  RUN_ALL_TESTS();
}

TEST_F(byte_testing, SameThreadTest) {
  // receiving data in same thread
  /*data_to_send = 100;
  pr_cmm::ProcessCommunicator::send_message<int>(data_to_send, "msg");
  pr_cmm::ProcessCommunicator::get_message<int>(received_data, "msg");
  EXPECT_EQ(data_to_send, received_data);
  data_to_send = 50;
  pr_cmm::ProcessCommunicator::send_message<int>(data_to_send, "msg");
  pr_cmm::ProcessCommunicator::get_message<int>(received_data, "msg");
  EXPECT_EQ(data_to_send, received_data);
  data_to_send = 5;
  pr_cmm::ProcessCommunicator::send_message<int>(data_to_send, "msg");
  pr_cmm::ProcessCommunicator::get_message<int>(received_data, "msg");
  EXPECT_EQ(data_to_send, received_data);*/

  std::cout << "byte_testing!\n";
  EXPECT_TRUE(true);
}

}  // namespace test
}  // namespace byte