#include "gtest/gtest.h"
#include "casting.h"


TEST(BasicChecks, TestEq) {
int a = 1;
int b = 1;
EXPECT_PRED2(IsEq, a, b);
}