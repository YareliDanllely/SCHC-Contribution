#include "gtest/gtest.h"
#include "SigFoxProfile.h"
#include "Rule.h"
#include "FragmentHeader.h"
#include "schc.h"
using namespace std;

TEST(initFragmentTest, FragmentHeaderTest ) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char emptyChar[] = "";
    char dtag[] = "";
    char fcn[] = "101";
    char w[] = "10";
    char * rcs = NULL;

    FragmentHeader header = FragmentHeader(profile,dtag, w, fcn, rcs);

    ASSERT_EQ(strcmp(fcn,header.FCN),0);
    ASSERT_EQ(strcmp(emptyChar,header.RCS),0);
    ASSERT_EQ(strcmp(emptyChar,header.PADDING),0);

    profile.N = 7;

    try {
        FragmentHeader header1 = FragmentHeader(profile,dtag, w, fcn, rcs);
    }
    catch (LengthMismatchError const & err) {
        EXPECT_EQ(err.message , "FCN must be of length N");
    }

}

TEST(initFragmentTestOne, FragmentHeaderTest ) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char dtag[] = "";
    char fcn[] = "101";
    char w[] = "10";
    char rcs[] = "110";

    try {
        FragmentHeader header = FragmentHeader(profile,dtag, w, fcn, rcs);
    }
    catch (BadProfileError const & err) {
        EXPECT_EQ(err.message , "RCS was not None in a regular fragment (not All-1)");
    }

}


TEST(initFragmentTestTwo, FragmentHeaderTest ) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char dtag[] = "";
    char fcn[] = "111";
    char w[] = "10";
    char rcs[] = "110";


    FragmentHeader header = FragmentHeader(profile,dtag, w, fcn, rcs);
    ASSERT_EQ(strcmp(rcs,header.RCS),0);
    ASSERT_EQ(strcmp("00000",header.PADDING),0);
}



TEST(toBinaryTest, FragmentHeaderTest) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char dtag[] = "";
    char fcn[] = "111";
    char w[] = "10";
    char rcs[] = "110";

    char test[] = "0001011111000000";

    FragmentHeader header = FragmentHeader(profile,dtag, w, fcn, rcs);

    ASSERT_EQ(strcmp(test,header.to_binary()),0);

}

TEST(toBinaryTestTwo, FragmentHeaderTest) {
    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);

    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);

    char dtag[] = "";
    char fcnTwo[] = "101";
    char *rcsTwo = NULL;
    char w[] = "10";
    char testTwo[] = "00010101";

    FragmentHeader header = FragmentHeader(profile, dtag, w, fcnTwo, rcsTwo);
    ASSERT_EQ(strcmp(testTwo, header.to_binary()), 0);

}

