#pragma once
#include "../ClassCalculator/TCalculator.h"
#include "../ClassCalculator/TCalculator.cpp"

#include "gtest.h""

TEST(TCalculator, can_create_tcalculator_object) {
	ASSERT_NO_THROW(TCalculator("(2+2)*5"));
}

TEST(TCalculator, can_copy_two_objets) {
	TCalculator tc("2+2");
	EXPECT_EQ(tc.getinfix(), TCalculator(tc).getinfix());
}

TEST(TCalculator, return_true_when_check_correct_string) {
	TCalculator tc("2*(3+2)");
	EXPECT_TRUE(tc.Check());
}

TEST(TCalculator, return_false_when_check_uncorrect_string) {
	TCalculator tc("2*(3+2))");
	EXPECT_FALSE(tc.Check());
}

TEST(TCalculator, topostfix_return_correct_string) {
	TCalculator tc("2+2*3*(4+5)");
	tc.ToPostfix();
	EXPECT_EQ("2 2 3 *4 5+*+", tc.getpostfix());
}

TEST(TCalculator, calculate_simple_example) {
	TCalculator tc("2 * 6 + 5");
	EXPECT_EQ(17, tc.Calculate());
}

TEST(TCalculator, calculate_example_with_braces) {
	TCalculator tc("2 * (6 + 5)");
	EXPECT_EQ(22, tc.Calculate());
}

TEST(TCalculator, calculate_example_with_exponentian) {
	TCalculator tc("3 ^ ( 2 * (6 + 4) / 5)");
	EXPECT_EQ(81, tc.Calculate());
}

