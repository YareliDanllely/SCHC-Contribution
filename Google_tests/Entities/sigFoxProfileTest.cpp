#include "gtest/gtest.h"
#include "Rule.h"
#include "SigFoxProfile.h"
#include "casting.h"
#include "string.h"
#include "schc.h"


TEST(createSigFoxProfileTest, SigFoxProfileTest) {
    char ruleId[] = "000";
    Rule rule = Rule(ruleId);
    char direct[] = "UPLINK";
    SigFoxProfile profile = SigFoxProfile(direct,FR_MODE,rule);

    char keyZero[] = "110";
    char keyOne[] = "101";
    char keyTwo[] = "100";
    char keyThree[] = "011";
    char keyFour[] = "010";
    char keyFive[] = "001";
    char keySix[] = "000";


    for (auto &i: profile.FCN_DICT) {
        if (strcmp(i.first,keyZero),0 ){
            ASSERT_EQ(i.second,0);
        }
        else if (strcmp(i.first,keyOne),0 ){
            ASSERT_EQ(i.second,1);
        }
        else if (strcmp(i.first,keyTwo),0 ){
            ASSERT_EQ(i.second,2);
        }
        else if (strcmp(i.first,keyThree),0 ){
            ASSERT_EQ(i.second,3);
        }
        else if (strcmp(i.first,keyFour),0 ){
            ASSERT_EQ(i.second,4);
        }
        else if (strcmp(i.first,keyFive),0 ){
            ASSERT_EQ(i.second,5);
        }
        else if (strcmp(i.first,keySix),0 ){
            ASSERT_EQ(i.second,6);
        }
    }

    ASSERT_EQ(profile.UPLINK_MTU, 96);
    ASSERT_EQ(profile.DOWNLINK_MTU, 64);

    ASSERT_EQ(profile.MAX_ACK_REQUESTS, 5);
    ASSERT_EQ(profile.RETRANSMISSION_TIMEOUT, 100);
    ASSERT_EQ(profile.INACTIVITY_TIMEOUT, 500);
    ASSERT_EQ(profile.SIGFOX_DL_TIMEOUT, 60);

    ASSERT_EQ(profile.RULE_ID_SIZE, rule.RULE_ID_SIZE);
    ASSERT_EQ(profile.MAX_WINDOW_NUMBER, 4);

    ASSERT_EQ(profile.MAX_FRAGMENT_NUMBER, 28);
}




