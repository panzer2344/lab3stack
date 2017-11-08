#include "..\LabStack\stack.h"

#include "gtest.h""

TEST(TStack, can_create_stack_with_positive_size) {
	ASSERT_NO_THROW(TStack<int> s(100));
}

TEST(TStack, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TStack<int> s(-1));
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