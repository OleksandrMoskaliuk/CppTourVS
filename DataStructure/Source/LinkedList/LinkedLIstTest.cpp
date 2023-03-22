#include <iostream>

#include "LinkedList.h"
#include "gtest/gtest.h"

namespace LinkedList {

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "LinkedList*";
  RUN_ALL_TESTS();
}
TEST(LinkedList, DefaultConstructor_test) {
  LinkedList::List<int> list;
  EXPECT_EQ(list.get_size(), 0);
}

TEST(LinkedList, ParametrizedConstructor_test) {
  LinkedList::List<int> list(8);
  EXPECT_EQ(list[0], 8);
  EXPECT_EQ(list.get_size(), 1);
}

TEST(LinkedList, CopyConstructor_test) {
  LinkedList::List<int> list1;
  list1.push_back(1);
  list1.push_back(2);
  list1.push_back(3);
  list1.push_back(4);
  list1.push_back(5);

  LinkedList::List<int> list2(list1);
  
  // list2 should have pushed list1 values
  EXPECT_EQ(list2[0], 1);
  EXPECT_EQ(list2[1], 2);
  EXPECT_EQ(list2[2], 3);
  EXPECT_EQ(list2[3], 4);
  EXPECT_EQ(list2[4], 5);
  EXPECT_EQ(list2.get_size(), 5);

  // Copied values should have different pionters
  EXPECT_NE(&list1[0], &list2[0]);
  EXPECT_NE(&list1[1], &list2[1]);
  EXPECT_NE(&list1[2], &list2[2]);
  EXPECT_NE(&list1[3], &list2[3]);
}


TEST(LinkedList, GetSize_test) 
{
  List<int> lst45;
  for (size_t i = 0; i < 45; ++i) {
    lst45.push_back(45);
  }
  EXPECT_EQ(lst45.get_size(), 45);
}
//TEST(LinkedList, Constructor_test) {
//  LinkedList::List<int> last;
//
//  LinkedList::List<int> df;
//  df.push_back(10);
//  df.push_back(20);
//  df.push_back(30);
//  df.push_back(40);
//  df.push_back(50);
//  df.push_back(60);
//  for (int i = 0; i < df.get_size(); i++) {
//    std::cout << df[i] << "\n";
//  }
//
//  std::cout << "result:" << std::endl;
//  df.push_front(56);
//  df.push_front(522);
//  for (int i = 0; i < df.get_size(); i++) {
//    std::cout << df[i] << "\n";
//  }
//  std::cout << df[0] << "\n";
//  std::cout << df[1] << "\n";
//  std::cout << df[2] << "\n";
//
//  EXPECT_EQ(1, 1);
//}

}  // namespace LinkedList