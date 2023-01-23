#include "gtest/gtest.h"
#include "SigFoxProfile.h"
#include "Rule.h"
#include "Header.h"

TEST(initHeaderTest, headerTest) {

    char ruleId[] = "000";
    char direct[] = "UPLINK";
    Rule ruleZero = Rule(ruleId);
    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE, ruleZero);
    char  dtag[] = "\0";
    char  emptyChar[] = "\0";
    char  w[] = "10";

    Header header = Header(profile,dtag, w);

    ASSERT_EQ(strcmp(ruleZero.STR,header.RULE_ID),0);
    ASSERT_EQ(strcmp(header.DTAG,emptyChar),0);
    ASSERT_EQ(strcmp("10",header.W),0);
    ASSERT_EQ(2,header.WINDOW_NUMBER);

    profile.RULE_ID_SIZE = 1;

    try {
        Header header1 = Header(profile,dtag,w);
    }
    catch (LengthMismatchError const & err ) {
        EXPECT_EQ(err.message , "Rule must be of length RULE_ID_SIZE");
    }

    profile = SigFoxProfile(direct,FR_MODE, ruleZero);
    profile.T = 2;

    try {
        Header header2 = Header(profile,dtag,w);
    }
    catch (LengthMismatchError const & err ) {
        EXPECT_EQ(err.message , "DTAG must be of length T");
    }

    profile = SigFoxProfile(direct,FR_MODE, ruleZero);
    profile.M = 5;

    try {
        Header header2 = Header(profile,dtag,w);
    }
    catch (LengthMismatchError const & err ) {
        EXPECT_EQ(err.message , "W must be length M");
    }

}