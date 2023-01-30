#include "test.h"

#include <iostream>

#include "../byte.h"
#include "gtest/gtest.h"

namespace byte {
namespace test {

struct byte_testing : testing::Test {
  My8bit* m8b;
  byte_testing() { m8b = new My8bit(0); }
  ~byte_testing() {
    if (m8b) {
      delete m8b;
    }
  }
};

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "byte_testing*";
  RUN_ALL_TESTS();
}

TEST_F(byte_testing, set_bit_testing) {
  m8b->reset_data();
  m8b->set_bit(4);
  EXPECT_TRUE(m8b->get_bit(4));
}

TEST_F(byte_testing, unset_bit_testing) {
  m8b->reset_data();
  m8b->set_bit(1);
  m8b->unset_bit(1);
  EXPECT_FALSE(m8b->get_bit(1));
}

TEST_F(byte_testing, reset_data_testing) {
  My8bit mb(1);
  mb.reset_data();
  EXPECT_FALSE(mb.get_byte());
}

TEST_F(byte_testing, get_dec_testing) {
  //      12345678
  // 25 = 00011001
  m8b->reset_data();
  // Make number 25
  m8b->set_bit(4);
  m8b->set_bit(5);
  m8b->set_bit(8);
  EXPECT_EQ(25, m8b->get_dec());
}

}  // namespace test
}  // namespace byte