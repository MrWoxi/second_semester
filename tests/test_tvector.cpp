// Copyright 2024 <Victor Klimovich>
#include <gtest.h>
#include "../lib_tvector/TVector.h"



TEST(Vector_test, Empty) {
    TVector<int> vec;
    EXPECT_TRUE(vec.empty());

    vec.push_back(1);
    EXPECT_FALSE(vec.empty());
}

TEST(Vector_test, Size) {
    TVector<int> vec;
    EXPECT_EQ(vec.size(), 0);

    vec.push_back(1);
    EXPECT_EQ(vec.size(), 1);

    vec.push_back(2);
    EXPECT_EQ(vec.size(), 2);
}

TEST(Vector_test, StartIndex) {
    TVector<int> vec;
    EXPECT_EQ(vec.start_index(), 0);

    vec.push_back(1);
    EXPECT_EQ(vec.start_index(), 0);
}



TEST(Vector_test, Assign) {
    TVector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);

    TVector<int> vec_2;
    vec_2.assign(vec_1);

    EXPECT_EQ(vec_2.size(), 2);
    EXPECT_EQ(vec_2[0], 1);
    EXPECT_EQ(vec_2[1], 2);
}

TEST(Vector_test, Clear) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.clear();

    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

TEST(Vector_test, Resize) {
    TVector<int> vec;
    vec.resize(4, 0);

    EXPECT_EQ(vec.size(), 4);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 0);
    }
    ASSERT_ANY_THROW(vec.resize(16));
}
TEST(Vector_test, DefaultConstructor) {
    TVector<int> vec;
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}

TEST(Vector_test, FillConstructor) {
    TVector<int> vec(8, 4);
    EXPECT_TRUE(vec.empty());
    EXPECT_EQ(vec.size(), 0);
}
TEST(Vector_test, Data) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    const int* data = vec.data();
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
}

TEST(Vector_test, Swap) {
    TVector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);

    TVector<int> vec_2;
    vec_2.push_back(3);
    vec_2.push_back(4);

    vec_1.swap(vec_2);

    EXPECT_EQ(vec_1.size(), 2);
    EXPECT_EQ(vec_1[0], 3);
    EXPECT_EQ(vec_1[1], 4);

    EXPECT_EQ(vec_2.size(), 2);
    EXPECT_EQ(vec_2[0], 1);
    EXPECT_EQ(vec_2[1], 2);
}

TEST(Vector_test, Size_method) {
    TVector<int> vec(11, 6);
    vec.insert(1, 0);
    EXPECT_EQ(vec.size(), 1);
}

TEST(Vector_test, PushBack) {
    TVector<int> vec(2);
    vec.push_back(1);
    vec.push_back(2);

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    ASSERT_ANY_THROW(vec.push_back(2));
}

TEST(Vector_test, PopBack) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.pop_back();

    EXPECT_EQ(vec.size(), 1);
    EXPECT_EQ(vec[0], 1);
}



TEST(Vector_test, Replace) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    vec.replace(1, 3);

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
}

TEST(Vector_test, Erase) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.erase(1, 1);
    vec.insert(4, 1);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 4);
    EXPECT_EQ(vec[2], 3);
}

TEST(Vector_test, FindAll) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);

    size_t* indices = vec.find_all(1);
    EXPECT_EQ(indices[0], 2);
    EXPECT_EQ(indices[1], 0);
    EXPECT_EQ(indices[2], 2);
}

TEST(Vector_test, FindFirst) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);

    EXPECT_EQ(vec.find_first(1), 0);
}

TEST(Vector_test, FindLast) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);

    EXPECT_EQ(vec.find_last(1), 2);
}

TEST(Vector_test, OperatorAccess) {
    TVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);

    vec[0] = 3;
    EXPECT_EQ(vec[0], 3);
}
TEST(Vector_test, InsertArray) {
    TVector<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);

    int arr[] = { 3, 4, 5 };
    vec.insert(arr, 3, 1);

    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 4);
    EXPECT_EQ(vec[3], 5);
    EXPECT_EQ(vec[4], 2);
    ASSERT_ANY_THROW(vec.insert(arr, 3, 1));
}

TEST(Vector_test, InsertValue) {
    TVector<int> vec(4, 1);
    vec.push_back(1);
    vec.push_back(2);

    vec.insert(3, 1);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 2);
    ASSERT_ANY_THROW(vec.insert(2, 2));
}

TEST(Vector_test, OperatorAssignment) {
    TVector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);

    TVector<int> vec_2;
    vec_2 = vec_1;

    EXPECT_EQ(vec_2.size(), 2);
    EXPECT_EQ(vec_2[0], 1);
    EXPECT_EQ(vec_2[1], 2);
}

TEST(Vector_test, OperatorAddition) {
    TVector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);

    TVector<int> vec_2;
    vec_2.push_back(3);
    vec_2.push_back(4);

    TVector<int> vec_3 = vec_1 + vec_2;

    EXPECT_EQ(vec_3.size(), 2);
    EXPECT_EQ(vec_3[0], 4);
    EXPECT_EQ(vec_3[1], 6);
}

TEST(Vector_test, OperatorMultiply) {
    TVector<int> vec_1;
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);
    TVector<int> vec = 4 * vec_1;
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 4);
    EXPECT_EQ(vec[1], 8);
    EXPECT_EQ(vec[2], 12);
}

TEST(Vector_test, OperatorAddition_Assigment) {
    TVector<int> vec_1(15, 2);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);

    TVector<int> vec_2;
    vec_2.push_back(4);
    vec_2.push_back(5);
    vec_2.push_back(6);

    vec_1 += vec_2;

    EXPECT_EQ(vec_1.size(), 3);
    EXPECT_EQ(vec_1[2], 7);
    EXPECT_EQ(vec_1[3], 2);
    EXPECT_EQ(vec_1[4], 3);
}

TEST(Vector_test, OperatorSub_Assigment) {
    TVector<int> vec(7, 1);
    TVector<int> vec_1(7, 2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec_1.push_back(4);
    vec_1.push_back(5);
    vec_1.push_back(6);
    vec -= vec_1;
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], -2);
    EXPECT_EQ(vec[3], -2);
}

TEST(Vector_test, OperatorMulty_Assigment) {
    TVector<int> vec(7, 1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec *= 5;
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec[2], 10);
    EXPECT_EQ(vec[3], 15);
}

TEST(Vector_test, OperatorEqual) {
    TVector<int> vec_1(3, 0);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);

    TVector<int> vec_2(3, 0);
    vec_2.push_back(1);
    vec_2.push_back(2);
    vec_2.push_back(3);

    EXPECT_TRUE(vec_1 == vec_2);

    TVector<int> vec_3(3, 0);
    vec_3.push_back(4);
    vec_3.push_back(5);
    vec_3.push_back(6);

    EXPECT_FALSE(vec_1 == vec_3);

    TVector<int> vec_4(4, 1);
    vec_4.push_back(1);
    vec_4.push_back(2);
    vec_4.push_back(3);

    EXPECT_FALSE(vec_1 == vec_4);

    TVector<int> vec_5(2, 0);
    vec_5.push_back(1);
    vec_5.push_back(2);

    EXPECT_FALSE(vec_1 == vec_5);
}

TEST(Vector_test, OperatorNotEqual) {
    TVector<int> vec_1(3, 0);
    vec_1.push_back(1);
    vec_1.push_back(2);
    vec_1.push_back(3);

    TVector<int> vec_2(3, 0);
    vec_2.push_back(1);
    vec_2.push_back(2);
    vec_2.push_back(3);

    EXPECT_FALSE(vec_1 != vec_2);

    TVector<int> vec_3(3, 0);
    vec_3.push_back(4);
    vec_3.push_back(5);
    vec_3.push_back(6);

    EXPECT_TRUE(vec_1 != vec_3);

    TVector<int> vec_4(4, 1);
    vec_4.push_back(1);
    vec_4.push_back(2);
    vec_4.push_back(3);

    EXPECT_TRUE(vec_1 != vec_4);

    TVector<int> vec_5(2, 0);
    vec_5.push_back(1);
    vec_5.push_back(2);

    EXPECT_TRUE(vec_1 != vec_5);
}
