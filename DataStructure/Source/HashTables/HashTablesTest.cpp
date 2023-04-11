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
  //ht.print();


  EXPECT_EQ(4, 4);
}

TEST(HashTable, str_test) {
  HashTable<char> ht(10);
  srand(2);

  for (size_t i = 0; i < 1200; ++i) {
    ht.insert("hash" + rand() % 100, 'c' + rand() % 100);
  }

  ht.insert("find", 'i');

  ht.print();
  

  EXPECT_EQ(ht.get("find"),'i');
}

}