#include "gtest/gtest.h"
#include "test.h"
#include "../2WayList.h"

namespace TwoWayList {

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "TwoWayListTest*";
  RUN_ALL_TESTS();
}

struct TwoWayList_testing : testing::Test {
  Node<int> *node = new Node<int>();

  
  
};

TEST_F(TwoWayList_testing, set_bit_testing) {
  //m8b->reset_data();
  //m8b->set_bit(4);

  std::cout << node->data;

  EXPECT_TRUE(1);
}

TEST(TwoWayListTest, DefaultConstructor) {
  TwoWayList<int> list;
  EXPECT_EQ(list.get_size(), 0);
}

TEST(TwoWayListTest, PushFront) {
  TwoWayList<int> list;
  list.push_front(1);
  EXPECT_EQ(list.get_size(), 1);
  EXPECT_EQ(list[0], 1);

  list.push_front(2);
  EXPECT_EQ(list.get_size(), 2);
  EXPECT_EQ(list[0], 2);
  EXPECT_EQ(list[1], 1);

  list.push_front(3);
  EXPECT_EQ(list.get_size(), 3);
  EXPECT_EQ(list[0], 3);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list[2], 1);
}

TEST(TwoWayListTest, PushBack) {
  TwoWayList<int> list;
  list.push_back(1);
  EXPECT_EQ(list.get_size(), 1);
  EXPECT_EQ(list[0], 1);

  list.push_back(2);
  EXPECT_EQ(list.get_size(), 2);
  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);

  list.push_back(3);
  EXPECT_EQ(list.get_size(), 3);
  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list[2], 3);
}

TEST(TwoWayListTest, Insert) {
  TwoWayList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.insert(0, 0);
  EXPECT_EQ(list.get_size(), 3);
  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list[2], 3);

  list.insert(1, 4);
  EXPECT_EQ(list.get_size(), 3);
  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 4);
  EXPECT_EQ(list[2], 3);

  list.insert(2, 5);
  EXPECT_EQ(list.get_size(), 3);
  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 4);
  EXPECT_EQ(list[2], 3);
}

TEST(TwoWayListTest, OperatorBracket) {
  TwoWayList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  EXPECT_EQ(list[0], 1);
  EXPECT_EQ(list[1], 2);
  EXPECT_EQ(list[2], 3);

  list[0] = 4;
  EXPECT_EQ(list[0], 4);
}

TEST(TwoWayListTest, GetNodeAddress) {
  TwoWayList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  TwoWayNode<int>* node = list.get_node_adress(1);
  EXPECT_EQ(node->data, 2);
}

TEST(TwoWayListTest, PopFront) {
  TwoWayList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  list.pop_front();
  EXPECT_EQ(list.get_size(), 2);
  EXPECT_EQ(list[0], 2);
  EXPECT_EQ(list[1], 3);

  list.pop_front();
  EXPECT_EQ(list.get_size(), 1);
  EXPECT_EQ(list[0], 3);

  list.pop_front();
}

}  // namespace TwoWayList