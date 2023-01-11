#include "gtest/gtest.h"
#include "casting.h"
#include <string>
#include <string.h>


TEST(binToInt,castingTest) {
    char binTest[] = "11010010";
    EXPECT_EQ(210, bin_to_int(binTest));
}


TEST(binToHex,castingTest) {
    char  binTest[] = "11010010";
    char  resultBinTest[] = "d2";
    char  secondBinTest[] = "000000011010010";
    char  secondResultBinTest[] = "0d2";
    ASSERT_EQ(strcmp(resultBinTest, bin_to_hex(binTest)),0);
    ASSERT_EQ(strcmp(secondResultBinTest, bin_to_hex(secondBinTest)),0);
}


TEST(hexToBin,castingTest) {
    char hexTest[] = "cafe";
    char resultHexTest [] = "1100101011111110";
    char resultHexTestTwo [] = "000000001100101011111110";
    ASSERT_EQ(strcmp(resultHexTest,hex_to_bin(hexTest)),0);
    ASSERT_EQ(strcmp(resultHexTestTwo,hex_to_bin(hexTest,24)),0);
}

TEST(intToBin,castingTest) {
    int num= 210;
    char  binResult [] = "11010010";
    char binResultTwo [] = "000011010010";
    ASSERT_EQ(strcmp(binResult, int_to_bin(num)),0);
    ASSERT_EQ(strcmp(binResultTwo, int_to_bin(num,12)),0);
}


TEST(intToHex,castingTest) {
    int num= 210;
    char *result= int_to_hex(num);
    char value[] = "d2";
    ASSERT_EQ(strcmp(result,value),0);
}
