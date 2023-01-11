#include "gtest/gtest.h"
#include "misc.h"
#include <string>
#include <string.h>

TEST(zFillTest,miscTest) {
    char strTest[] = "test";
    char resulTest[] = "00000test";
    ASSERT_EQ(strcmp(resulTest, zfill(strTest,9)),0);
    ASSERT_EQ(strcmp(strTest, zfill(strTest,2)),0);
}

TEST(zPadTest,miscTest) {
    char strTest[] = "test";
    char resultTest[] = "test00000";
    ASSERT_EQ(strcmp(resultTest, zpad(strTest,9)),0);

}

TEST(replaceCharTest,miscTest) {
    char strTest[] = "1001111";
    char newChar[] = "1";
    char strResultTest[] = "1011111";

    char strTestTwo[] = "1001111";
    char strResultTestTwo[] = "10011111";

    ASSERT_EQ(strcmp(strResultTest, replaceChar(strTest,2,newChar)),0);
    ASSERT_EQ(strcmp(strResultTestTwo, replaceChar(strTestTwo,10,newChar)),0);

}

TEST(findTest,miscTest){
    char strTest[] = "1001011";
    char search[] = "1";
    vector<int> result = find(strTest,search);
    ASSERT_EQ(0,result[0]);
    ASSERT_EQ(3,result[1]);
    ASSERT_EQ(5,result[2]);
    ASSERT_EQ(6,result[3]);
}

TEST(isMonarch, miscTest) {
    char strTest[] = "1111111";
    char search[] = "1";
    char searchTwo[] = "0";
    char strTestTwo[] = "1111111";

    ASSERT_FALSE(is_monochar(strTest,searchTwo));
   /* ASSERT_TRUE(is_monochar(strTestTwo,search));*/
}

