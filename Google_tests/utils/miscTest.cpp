#include "gtest/gtest.h"
#include "misc.h"
#include <string>
#include <string.h>

TEST(zFillTest,miscTest) {
    char strTest[] = "test";
    char resulTest[] = "00000test";
    char resulTestTwo[] = "test";
    ASSERT_EQ(strcmp(resulTest, zfill(strTest,9)),0);
    ASSERT_EQ(strcmp(resulTestTwo, zfill(strTest,2)),0);
}