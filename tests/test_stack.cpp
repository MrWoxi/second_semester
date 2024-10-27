// Copyright 2024 <Victor Klimovich>
#include <gtest.h>
#include "../lib_dmassive/massive.h"
#include "../lib_stack/stack.h"


TEST(Test_TStack, empty_metod) {
    TStack<int> st_1;
    EXPECT_TRUE(st_1.IsEmpty());
}

TEST(Test_TStack, PUSH_metod) {
    TStack<int> st_1(3);
    st_1.push(8);
    st_1.push(7);
    st_1.push(1);
    EXPECT_EQ(st_1.top(), 1);
}

TEST(Test_TStack, Constructor) {
    TStack<int> st_1;
    EXPECT_EQ(st_1.size(), 20);
}

TEST(Test_TStack, POP_metod) {
    TStack<int> st_1(5);

    ASSERT_ANY_THROW(st_1.pop());

    st_1.push(1);
    st_1.push(2);
    st_1.push(3);
    st_1.pop();
    EXPECT_EQ(st_1.top(), 2);
}

TEST(Test_TStack, Full_metod) {
    TStack<int> st_1(2);
    st_1.push(2);
    st_1.push(3);
    EXPECT_TRUE(st_1.IsFull());


    ASSERT_ANY_THROW(st_1.push(2));
}
