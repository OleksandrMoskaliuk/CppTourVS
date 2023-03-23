#include <gtest/gtest.h>
#include "Stack.h"
#include <thread>


namespace Stack {

void Test(int& argc, char* argv[]) 
{
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "StackTest*";
  RUN_ALL_TESTS();
}

TEST(StackTest, DefaultConstructor_test) 
{
 Stack<int> st;
 EXPECT_EQ(st.size(), 0);
}

TEST(StackTest, CopyConstructor_test) {
 Stack<int> st;
 st.push(5);
 st.push(4);
 st.push(3);
 st.push(2);
 st.push(1);
 EXPECT_EQ(st.top(), 1);

 Stack<int> st_copy(st);
 EXPECT_EQ(st_copy.top(), 1);
 st_copy.pop();
 EXPECT_EQ(st_copy.top(), 2);
 st_copy.pop();
 EXPECT_EQ(st_copy.top(), 3);
 st_copy.pop();
 EXPECT_EQ(st_copy.top(), 4);
 st_copy.pop();
 EXPECT_EQ(st_copy.top(), 5);

}

TEST(StackTest, Destructor_test) {
 for (size_t i = 0; i < 1000; i++) {
   for (size_t j = 0; j < 10000; j++) {
     Stack<int> st;
     st.push(10);
   }
 }
 ASSERT_EQ(0, _CrtDumpMemoryLeaks());
}

TEST(StackTest, Top_test) {
 Stack<int> st;
 st.push(10);
 EXPECT_EQ(st.top(), 10);
 st.push(20);
 EXPECT_EQ(st.top(), 20);
 st.pop();
 EXPECT_EQ(st.top(), 10);
}


TEST(StackTest, Empty_test) {
 // Stack is empty
 Stack<int> st;
 EXPECT_TRUE(st.empty());

 // Stack is not  empty
 st.push(1);
 EXPECT_FALSE(st.empty());
}


TEST(StackTest, Size_test) {
 Stack<int> st1;
 st1.push(10);
 EXPECT_EQ(st1.size(), 1);

 Stack<int> st5;
 for (size_t i = 0; i < 5; ++i) {
   st5.push(5);
 }
 EXPECT_EQ(st5.size(), 5);

 Stack<int> st10;
 for (size_t i = 0; i < 10; ++i) {
   st10.push(10);
 }
 EXPECT_EQ(st10.size(), 10);
}


TEST(StackTest, End_test) {
 EXPECT_TRUE(true);
}

} // namespce Stack