#include "byte.h"
#include <iostream>
#include "gtest/gtest.h"

namespace byte {

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

  // 1000 0000
  m8b->set_bit(1);
  // 2^7 = 128
  EXPECT_EQ(128, m8b->get_dec());
  m8b->reset_data();

  // 0100 0000
  m8b->set_bit(2);
  // 2^6 = 64
  EXPECT_EQ(64, m8b->get_dec());
  m8b->reset_data();

  // 0010 0000
  m8b->set_bit(3);
  // 2^5 = 32
  EXPECT_EQ(32, m8b->get_dec());
  m8b->reset_data();

  // 0001 0000
  m8b->set_bit(4);
  // 2^4 = 16
  EXPECT_EQ(16, m8b->get_dec());
  m8b->reset_data();

  // 0000 1000
  m8b->set_bit(5);
  // 2^3 = 8
  EXPECT_EQ(8, m8b->get_dec());
  m8b->reset_data();

  // 0000 0100
  m8b->set_bit(6);
  // 2^2 = 4
  EXPECT_EQ(4, m8b->get_dec());
  m8b->reset_data();

  // 0000 0010
  m8b->set_bit(7);
  // 2^1 = 2
  EXPECT_EQ(2, m8b->get_dec());
  m8b->reset_data();

  // 0000 0001
  m8b->set_bit(8);
  EXPECT_EQ(1, m8b->get_dec());
  m8b->reset_data();

}

TEST_F(byte_testing, unset_bit_testing) {
  m8b->set_bit(1);
  m8b->info();
  m8b->unset_bit(1);
  m8b->info();
  EXPECT_FALSE(m8b->get_bit(1));
}

TEST_F(byte_testing, reset_data_testing) {
  My8bit mb(1);
  mb.info();
  std::cout << "reset data!\n";
  mb.reset_data();
  mb.info();
  EXPECT_FALSE(mb.get_byte());
}

TEST_F(byte_testing, get_dec_testing) {
  //      12345678
  // 25 = 00011001
  // Make number 25
  m8b->set_bit(4);
  m8b->set_bit(5);
  m8b->set_bit(8);
  EXPECT_EQ(25, m8b->get_dec());
}

}  // namespace byte