#pragma once
#include "..\LabStack\stack.h"

#include "gtest.h""

TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int> s(100));
}

TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-1));
}

TEST(TStack, trows_when_create_stack_with_too_large_size) {
	ASSERT_ANY_THROW(TStack<int> s(STACK_MAX_SIZE + 1));
}

TEST(TStack, can_create_copied_stack) {
	TStack<int> st1(100);
	ASSERT_NO_THROW(TStack<int> st2(st1));
}

TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> st1(100);
	st1.push(2);

	TStack<int> st2(st1);
	EXPECT_EQ(st1.pop(), st2.pop());
}

TEST(TStack, isfull_method_return_true_when_stack_is_full) {
	TStack<int> s(1);
	s.clear();
	s.push(1);
	EXPECT_TRUE(s.isFull());
}

TEST(TStack, isfull_method_return_false_when_stack_isnt_full) {
	TStack<int> s(2);
	s.clear();
	s.push(1);
	EXPECT_FALSE(s.isFull());
}

TEST(TStack, isempty_method_return_true_when_stack_is_empty) {
	TStack<int> s(1);
	s.clear();
	EXPECT_TRUE(s.isEmpty());
}

TEST(TStack, isempty_method_return_false_when_stack_isnt_empty) {
	TStack<int> s(3);
	s.push(1);
	EXPECT_FALSE(s.isEmpty());
}

TEST(TStack, can_get_top) {
	TStack<int> s(3);
	s.push(1);
	ASSERT_NO_THROW(s.top());
}

TEST(TStack, push_work_corretly) {
	TStack<int> s(3);
	s.clear();
	s.push(2);
	EXPECT_EQ(2, s.top());
}

TEST(TStack, pop_correct_value) {
	TStack<int> s(3);
	s.clear();
	s.push(3);
	EXPECT_EQ(3, s.pop());
}

TEST(TStack, pop_move_pointer_back) {
	TStack<int> s(5);
	s.clear();
	s.push(3);
	s.push(2);
	s.pop();
	EXPECT_EQ(3, s.top());
}





