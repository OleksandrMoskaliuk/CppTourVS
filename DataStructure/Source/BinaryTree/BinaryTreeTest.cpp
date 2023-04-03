#include <gtest/gtest.h>

#include "BinaryTree.h"

namespace BinaryTree {

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "BinaryTree*";
  RUN_ALL_TESTS();
}

TEST(BinaryTree, DefaultConstructor_test) 
{ 
 BinaryTree<int> bt;
 EXPECT_FALSE(bt.search(0));
}

TEST(BinaryTree, ParametrizedConstructor_test) {
 BinaryTree<int> bt(10);
 Node<int>* res = bt.search(10);
 EXPECT_EQ(res->data, 10);
}

TEST(BinaryTree, Insert_test) {
 BinaryTree<double> bt;
 bt.insert(10.5);
 Node<double> *nd = bt.search(10.5);
 EXPECT_EQ(nd->data, 10.5);
}

TEST(BinaryTree, Remove_test) {
  BinaryTree<int> bt;
  bt.insert(10);
  bt.insert(5);
  bt.insert(20);
  bt.insert(4);
  bt.insert(6);
  bt.insert(21);
  bt.insert(19);
  /*
                              10
                            /    \
                           5      20
                          / \    /  \    
                         4   6  19  21
  */
  bt.remove(20);
  /*
                              10
                            /    \
                           5      21
                          / \    /  \    
                         4   6  19  nullptr
  */
}


TEST(BinaryTree, MemoryLeakTest_test) 
{
  _CrtMemState sOld;
  _CrtMemState sNew;
  _CrtMemState sDiff;
  _CrtMemCheckpoint(&sOld);  // take a snapshot
  {
  BinaryTree<double> bt;
  bt.insert(10);
  BinaryTree<int> bt2(10);
  }
  _CrtMemCheckpoint(&sNew);  // take a snapshot

  // If there any difference than we got memory leak
  EXPECT_FALSE(_CrtMemDifference(&sDiff, &sOld, &sNew));
}

TEST(BinaryTree, End_test) { EXPECT_TRUE(true); }

}  // namespace BinaryTree