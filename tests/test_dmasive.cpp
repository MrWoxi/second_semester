// Copyright 2024 <Victor Klimovich>
#include <gtest.h>
#include <string>
#include "../lib_dmassive/massive.h"

#define EPSILON 0.000001
TEST(Test_Dmassive, push_back_array) {
    // Arrange
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(9);
    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1, 0, 9, ");
}
TEST(Test_Dmassive, push_front_array) {
    // Arrange
    TDMassive<int> arr;
    arr.push_front(1);
    arr.push_front(0);
    arr.push_front(9);

    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "9, 0, 1, ");
}
TEST(Test_Dmassive, create_empty_array) {
    // Arrange
    TDMassive<int> arr;
    // Act & Assert
    EXPECT_TRUE(arr.empty());
}

TEST(Test_Dmassive, create_array) {
    // Arrange
    TDMassive<int> arr;
    // Act & Assert
    arr.push_back(10);
    EXPECT_FALSE(arr.empty());
}

TEST(Test_Dmassive, clear_empty_array) {
    TDMassive<int> arr;
    EXPECT_NO_THROW(arr.clear());
    EXPECT_TRUE(arr.empty());
}
TEST(Test_Dmassive, clear_array) {
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_NO_THROW(arr.clear());
    EXPECT_TRUE(arr.empty());
}
TEST(Test_Dmassive, resize_array_add) {
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.resize(5, 0);
    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1, 2, 3, 0, 0, ");
}
TEST(Test_Dmassive, resize_array_del) {
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.resize(2, 0);
    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1, 2, ");
}
TEST(Test_Dmassive, resize_array_empty) {
    TDMassive<int> arr;
    arr.resize(2, 0);
    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0, 0, ");
}
TEST(Test_Dmassive, full_test) {
    TDMassive<int> arr;
    EXPECT_FALSE(arr.full());
    arr.resize(15, 'a');
    EXPECT_TRUE(arr.full());
}
TEST(Test_Dmassive, assign_test) {
    TDMassive<int> arr(1, 5);
    TDMassive<int> d(4, 8);
    arr.assign(d);
    EXPECT_EQ(arr.size(), 4);
    EXPECT_EQ(arr.data()[1], 8);
    EXPECT_EQ(arr.capacity(), 15);
}

TEST(Test_Dmassive, repacking_test) {
    TDMassive<int> arr;
    arr.push_front(1);
    arr.push_front(2);
    arr.push_front(3);
    arr.push_front(4);
    arr.push_front(5);

    EXPECT_EQ(arr.size(), 5);
    arr.remove_by_index(1);
    arr.remove_by_index(3);
    EXPECT_EQ(arr.size(), 5);

    arr.reserve();
    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr.data()[0], 5);
    EXPECT_EQ(arr.data()[1], 3);
    EXPECT_EQ(arr.data()[2], 1);
}
TEST(Test_Dmassive, reserve_test) {
    TDMassive<int> arr;
    arr.resize(15, 5);
    EXPECT_EQ(arr.capacity(), 15);
    arr.push_front(1);
    arr.reserve();
    EXPECT_EQ(arr.capacity(), 30);
}
TEST(Test_Dmassive, insert_single_value) {
    TDMassive<int> arr;
    arr.insert(1, 0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.data()[0], 1);

    arr.insert(2, 1);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ(arr.data()[0], 1);
    EXPECT_EQ(arr.data()[1], 2);
}
TEST(Test_Dmassive, PopFront_test) {
    TDMassive<int> arr(10);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    arr.pop_front();
    EXPECT_EQ(arr.data()[0], 2);
    EXPECT_EQ(arr.data()[1], 3);
    EXPECT_EQ(arr.size(), 2);

    arr.pop_front();
    EXPECT_EQ(arr.data()[0], 3);
    EXPECT_EQ(arr.size(), 1);

    arr.pop_front();
    EXPECT_EQ(arr.size(), 0);
}
