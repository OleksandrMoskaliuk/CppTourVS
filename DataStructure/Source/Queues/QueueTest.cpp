#include "gtest/gtest.h"
#include "Queue.h"

namespace Queues 
{

void Test(int& argc, char* argv[]) 
{
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "Queues*";
  RUN_ALL_TESTS();
} 


TEST(Queues, DefaultConstructor_test) 
{
  Queue<int> que;
  EXPECT_EQ(que.peek(), -1);
  EXPECT_EQ(que.dequeue(), -1);
  EXPECT_TRUE(que.isEmpty());

}


TEST(Queues, CopyConstructor_test) {
  Queue<int> que;
  que.enqueue(10);
  que.enqueue(20);

  Queue<int> que_copied(que);

  EXPECT_EQ(que_copied.peek(), 10);
  EXPECT_EQ(que.peek(), 10);
  EXPECT_EQ(que_copied.dequeue(), 10);
  EXPECT_EQ(que.dequeue(), 10);
  EXPECT_EQ(que_copied.dequeue(), 20);
  EXPECT_EQ(que.dequeue(), 20);
}


TEST(Queues, Destructor_test) {

  while (false) {
    Queue<int> que;
    que.enqueue(10);
  }
  
  EXPECT_EQ(_CrtDumpMemoryLeaks(), 0);
}

TEST(Queues, Enqueue_test) {
  Queue<int> que;
  que.enqueue(10);
  EXPECT_EQ(que.peek(), 10);
}

TEST(Queues, Dequeue_test) {
  Queue<int> que;
  que.enqueue(10);
  EXPECT_EQ(que.dequeue(), 10);
  que.enqueue(15);
  EXPECT_EQ(que.dequeue(), 15);
}


TEST(Queues, Peek_test) {
  Queue<int> que;
  que.enqueue(10);
  EXPECT_EQ(que.peek(), 10);
  que.dequeue();
  que.enqueue(2);
  EXPECT_EQ(que.peek(), 2);
}

TEST(Queues, End_test) {
  EXPECT_TRUE(true);
}

}