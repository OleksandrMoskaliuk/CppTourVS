#include "HashTables.h"
#include "gtest/gtest.h"

namespace HashTable 
{

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "HashTable*";
  RUN_ALL_TESTS();
}

TEST(HashTable, DefaultConstructor_test) {
  HashTable<int> ht(20);
  srand(2);
  for (size_t i = 0; i < 20; i++) {
    ht.insert(i, rand()%20);
  }
  for (size_t i = 20; i < 40; i++) {
    ht.insert(i, rand() % 20);
  }
  EXPECT_EQ(4, 4);
}

TEST(HashTable, char_test) {
  HashTable<char> ht(10);
  srand(2);
  for (size_t i = 0; i < 20; ++i) {
    ht.insert("hash" + rand() % 100, 'c' + rand() % 100);
  }
  ht.insert("find", 'i');
  ht.print();
  EXPECT_EQ(ht.get("find"),'i');
}

TEST(HashTable, char_array_test) {
  HashTable<char*> ht(10);
  srand(10);
  char arr[] = "array";
  for (size_t i = 0; i < 20; ++i) {
    ht.insert("hash" + rand() % 100, arr + rand() % 100);
  }
  char to_find[] = "this";
  ht.insert("find", to_find);
  EXPECT_EQ(ht.get("find"), to_find);
}

TEST(HashTable, MemoryLeak_test) {
  _CrtMemState sOld;
  _CrtMemState sNew;
  _CrtMemState sDiff;
  _CrtMemCheckpoint(&sOld);  // take a snapshot
  {
    HashTable<int> ht(10);
    ht.insert("mem_cheak", 10);
  }
  _CrtMemCheckpoint(&sNew);  // take a snapshot
  // The following assertion checks that the memory has been properly
  // deallocated
  EXPECT_FALSE(_CrtMemDifference(&sDiff, &sOld, &sNew));
}

TEST(LinkedList, End_test) { EXPECT_TRUE(true); }

}  // namespace HashTable