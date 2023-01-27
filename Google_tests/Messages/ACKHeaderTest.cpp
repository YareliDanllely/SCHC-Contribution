#include "gtest/gtest.h"
#include "SigFoxProfile.h"
#include "Rule.h"
#include "ACKHeader.h"
#include "schc.h"
using namespace std;

TEST(initACKHeaderTest, ACKHeaderTest) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char dtag[] = "\0";
    char w[] = "10";
    char c[] = "0";

    ACKHeader header = ACKHeader(profile,dtag,w,c);

    ASSERT_EQ(strcmp(c,header.C),0);

    try {
        char cTwo[] = "11";
        ACKHeader header1 = ACKHeader(profile,dtag,w,cTwo);
    }
    catch (LengthMismatchError const & err) {
        EXPECT_EQ(err.message, "C bit mus be of length 1");
    }

}

TEST(toBinaryTest, ACKHeaderTest) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);
    char dtag[] = "";
    char w[] = "10";
    char c[] = "0";
    ACKHeader header = ACKHeader(profile,dtag,w,c);

    char test1[] = "000100";

    ASSERT_EQ(strcmp(test1,header.to_binary()),0);
}