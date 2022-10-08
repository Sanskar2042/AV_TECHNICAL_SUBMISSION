#include <gtest/gtest.h>
#include "testerF.h"

TEST(testerF, testerFunction)
{
    GTEST_ASSERT_EQ(testerFunction(), 5000);
}
