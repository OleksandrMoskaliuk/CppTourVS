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

   List<int> lst34;
  for (size_t i = 0; i < 34; ++i) {
    lst34.push_back(45);
  }
  EXPECT_EQ(lst34.get_size(), 34);
}

TEST(LinkedList, PushFront_test) 
{ 
 List<float> lst(0);
 lst.push_front(1);
 lst.push_front(2);
 EXPECT_EQ(lst[0], 2);
 EXPECT_EQ(lst[1], 1);
 EXPECT_EQ(lst[2], 0);

}


TEST(LinkedList, PushBack_test) {
 List<float> lst(0);
 lst.push_back(1);
 lst.push_back(2);
 EXPECT_EQ(lst[0], 0);
 EXPECT_EQ(lst[1], 1);
 EXPECT_EQ(lst[2], 2);
}


TEST(LinkedList, Insert_test) {
 //insers as middle
 List<char> lst;
 lst.push_back('a');
 lst.push_back('c');
 lst.insert(1, 'b');
 EXPECT_EQ(lst[0], 'a');
 EXPECT_EQ(lst[1], 'b');
 EXPECT_EQ(lst[2], 'c');

 // front insert
 List<char> lstf;
 lstf.push_back('b');
 lstf.push_back('c');
 lstf.insert(0, 'a');
 EXPECT_EQ(lst[0], 'a');
 EXPECT_EQ(lst[1], 'b');
 EXPECT_EQ(lst[2], 'c');

 // back insert
 List<char> lstb;
 lstb.push_back('a');
 lstb.push_back('b');
 lstb.insert(2, 'c');
 EXPECT_EQ(lst[0], 'a');
 EXPECT_EQ(lst[1], 'b');
 EXPECT_EQ(lst[2], 'c');
}

TEST(LinkedList, PopFront_test) 
{ 
 List<double> lst;
 lst.push_back(0);
 lst.push_back(1);
 lst.push_back(2);
 lst.push_back(3);
 lst.push_back(4);
 lst.pop_front();
 EXPECT_EQ(lst[0], 1);
}

TEST(LinkedList, PopBack_test) {
 List<int> ls;
 ls.push_back(0);
 ls.push_back(1);
 ls.push_back(2);
 ls.push_back(3);
 ls.push_back(4);
 ls.push_back(5);
 EXPECT_EQ(ls.get_size(), 6);

 ls.pop_back();
 ls.pop_back();
 EXPECT_EQ(ls.get_size(), 4);
 EXPECT_EQ(ls[2], 2);

}

TEST(LinkedList, Remove_test) 
{
 // remove midle element
 List<int> lst0;
 lst0.push_back(0);
 lst0.push_back(1);
 lst0.push_back(2);
 lst0.push_back(3);
 lst0.remove(1);
 EXPECT_EQ(lst0[1], 2);
 
 // remove firs 
 List<int> lst1;
 lst1.push_back(0);
 lst1.push_back(1);
 lst1.push_back(2);
 lst1.remove(0);
 EXPECT_EQ(lst1[0], 1);

 // remove last
 List<int> lst2;
 lst2.push_back(0);
 lst2.push_back(1);
 lst2.push_back(2);
 EXPECT_EQ(lst2.get_size(), 3);
 lst2.remove(2);
 EXPECT_EQ(lst2.get_size(), 2);
 EXPECT_EQ(lst2[1], 1);

 // remove last if only 2 elements
 List<int> lst3;
 lst3.push_back(0);
 lst3.push_back(1);
 EXPECT_EQ(lst3.get_size(), 2);
 lst3.remove(1);
 EXPECT_EQ(lst3.get_size(), 1);
 EXPECT_EQ(lst3[0], 0);
}

TEST(LinkedList, End_test) {
 EXPECT_TRUE(true);
}


}  // namespace LinkedList