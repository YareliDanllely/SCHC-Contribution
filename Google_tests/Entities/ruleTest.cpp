#include "gtest/gtest.h"
#include "Rule.h"
#include "casting.h"
#include "string.h"

TEST(createRuleTest, ruleTest) {
    char ruleId[] = "000";
    Rule rule = Rule(ruleId);

    ASSERT_EQ(strcmp(rule.STR,ruleId),0);
    ASSERT_EQ(rule.ID,0);
    ASSERT_EQ(rule.RULE_ID_SIZE,3);
    ASSERT_EQ(rule.T,0);
    ASSERT_EQ(rule.M,2);
    ASSERT_EQ(rule.N,3);
    ASSERT_EQ(rule.WINDOW_SIZE,7);
    ASSERT_EQ(rule.U,3);


    ASSERT_EQ(rule.HEADER_LENGTH,8);
    ASSERT_EQ(rule.ALL1_HEADER_LENGTH,16);
    ASSERT_EQ(rule.ACK_HEADER_LENGTH,6);

}

TEST(createRuleTestTwo, ruleTest) {
    char ruleId[] = "111";
    Rule rule = Rule(ruleId);

    ASSERT_EQ(strcmp(rule.STR,ruleId),0);
    ASSERT_EQ(rule.ID,7);
    ASSERT_EQ(rule.RULE_ID_SIZE,6);
    ASSERT_EQ(rule.T,0);
    ASSERT_EQ(rule.M,2);
    ASSERT_EQ(rule.N,4);
    ASSERT_EQ(rule.WINDOW_SIZE,12);
    ASSERT_EQ(rule.U,4);


    ASSERT_EQ(rule.HEADER_LENGTH,16);
    ASSERT_EQ(rule.ALL1_HEADER_LENGTH,16);
    ASSERT_EQ(rule.ACK_HEADER_LENGTH,9);

}

TEST(fromHexTest, ruleTest) {
    char strId[] = "10101";
    char ruleId[] = "000";
    Rule newRule = newRule.from_hex(strId);

    ASSERT_EQ(strcmp(newRule.STR,ruleId),0);
    ASSERT_EQ(newRule.ID,0);

}
