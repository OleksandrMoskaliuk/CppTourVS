#include "ArrayTest.h"

#include "../Array.h"
#include "gtest/gtest.h"

namespace Array {

void Test(int& argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(filter) = "DynamicArrayTest*";
  RUN_ALL_TESTS();
  testing::GTEST_FLAG(filter) = "StaticArrayTest*";
  RUN_ALL_TESTS();
}

TEST(DynamicArrayTest, Constructor_Test) {
  MyDinamicArray<int> arr;
  EXPECT_EQ(arr.size(), 0);
  EXPECT_EQ(arr.capacity(), 1);
  MyDinamicArray<int> arr2(10);
  for (int i = 0; i < arr.size(); i++) {
    EXPECT_EQ(arr[i], 0);
  }
}

TEST(DynamicArrayTest, Destructor_Test) {
  MyDinamicArray<int> arr;
  arr.~MyDinamicArray();
  // The following assertion checks that the memory has been properly
  // deallocated
  ASSERT_EQ(arr.get_base_pointer(), nullptr);
}

TEST(DynamicArrayTest, PushBack_Test) {
  MyDinamicArray<int> arr;
  arr.push_back(10);
  ASSERT_EQ(arr[0], 10);

  arr.push_back(5);
  ASSERT_EQ(arr[1], 5);

  for (size_t i = 0; i < 10; i++) {
    arr.push_back(3);
  }
  for (size_t i = 2; i < arr.size(); i++) {
    ASSERT_EQ(arr[i], 3);
  }
}

TEST(DynamicArrayTest, Operator_Test) {
  MyDinamicArray<int> arr;
  arr.push_back(5);
  ASSERT_EQ(arr[0], 5);

  arr[0] += 10;
  ASSERT_EQ(arr[0], 15);
}

TEST(DynamicArrayTest, size_function_Test) {
  MyDinamicArray<int> arr;
  arr.push_back(2);
  ASSERT_EQ(arr.size(), 1);
  arr.push_back(4);
  ASSERT_EQ(arr.size(), 2);
  arr.push_back(0);
  ASSERT_EQ(arr.size(), 3);

  MyDinamicArray<int> arr2;
  for (size_t i = 0; i < 100; i++) {
    arr2.push_back(i);
    ASSERT_EQ(arr2[i], i);
  }
}

TEST(DynamicArrayTest, capacity_function_Test) {
  MyDinamicArray<int> arr;
  ASSERT_EQ(arr.capacity(), 1);
  arr.push_back(0); // elem 1 cap 1
  ASSERT_EQ(arr.capacity(), 1);
  arr.push_back(2); // elem 2 cap 2
  ASSERT_EQ(arr.capacity(), 2);
  arr.push_back(3); //elem 3 cap 4
  ASSERT_EQ(arr.capacity(), 4);
  arr.push_back(2); // elem 4 cap 4
  arr.push_back(5); // elem 5 cap 8
  ASSERT_EQ(arr.capacity(), 8);

  MyDinamicArray<int> arr0;
  for (size_t i = 0; i < 100; i++) {
    arr.push_back(0);
  }
  ASSERT_EQ(arr.capacity(), 128);
}

TEST(DynamicArrayTest, erase_function_test) {
  MyDinamicArray<int> arr;
  arr.push_back(2);
  arr.push_back(4);
  ASSERT_EQ(arr[0], 2);
  ASSERT_EQ(arr[1], 4);
  ASSERT_EQ(arr.size(), 2);

  arr.pop_back();
  ASSERT_EQ(arr.size(), 1);
  ASSERT_EQ(arr[1], 0); // cell still exist but erased
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  ASSERT_EQ(arr.size(), 4);
  ASSERT_EQ(arr[3], 3);

}

TEST(DynamicArrayTest, end_test) {
  ASSERT_EQ(1, 1);
}

TEST(StaticArrayTest, SizeTest) {
  MyStaticArray<int, 5> arr;
  ASSERT_EQ(5, arr.size());
}

TEST(StaticArrayTest, IndexOperatorTest) {
  MyStaticArray<int, 3> arr;
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  ASSERT_EQ(1, arr[0]);
  ASSERT_EQ(2, arr[1]);
  ASSERT_EQ(3, arr[2]);
}

TEST(StaticArrayTest, IteratorTest) {
  MyStaticArray<int, 4> arr;
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  int expected_sum = 0;
  for (const auto& element : arr) {
    expected_sum += element;
  }
  int actual_sum = 0;
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    actual_sum += *it;
  }
  ASSERT_EQ(expected_sum, actual_sum);
}

TEST(StaticArrayTest, end_test) { ASSERT_EQ(1, 1); }

}  // namespace Array