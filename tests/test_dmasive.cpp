// Copyright 2024 <Victor Klimovich>
#include <gtest.h>
#include <string>
#include "../lib_dmassive/massive.h"

#define EPSILON 0.000001
TEST(TestDinamicArray, push_back_array) {
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
TEST(TestDinamicArray, push_front_array) {
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
TEST(TestDinamicArray, create_empty_array) {
    // Arrange
    TDMassive<int> arr;
    // Act & Assert
    EXPECT_TRUE(arr.empty());
}

TEST(TestDinamicArray, create_array) {
    // Arrange
    TDMassive<int> arr;
    // Act & Assert
    arr.push_back(10);
    EXPECT_FALSE(arr.empty());
}
TEST(TestDinamicArray, print_empty_array) {
    TDMassive<int> arr;
    EXPECT_THROW(arr.print(), std::logic_error);
}
TEST(TestDinamicArray, print_array) {
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    testing::internal::CaptureStdout();
    arr.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1, 2, 3, ");
}
TEST(TestDinamicArray, clear_empty_array) {
    TDMassive<int> arr;
    EXPECT_NO_THROW(arr.clear());
}
TEST(TestDinamicArray, clear_array) {
    TDMassive<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    EXPECT_NO_THROW(arr.clear());
}
TEST(TestDinamicArray, resize_array_add) {
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
TEST(TestDinamicArray, resize_array_del) {
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
TEST(TestDinamicArray, resize_array_empty) {
    TDMassive<int> arr;
    EXPECT_THROW(arr.resize(2, 0), std::logic_error);
}
