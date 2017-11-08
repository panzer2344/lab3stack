#include "../ClassCalculator/TCalculator.h"

#include "gtest.h""

TEST(TCalculator, can_create_tcalculator_object) {
	ASSERT_NO_THROW(TCalculator("(2+2)*5"));
}