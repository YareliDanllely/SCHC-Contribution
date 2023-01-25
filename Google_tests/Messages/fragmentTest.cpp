#include "gtest/gtest.h"
#include "casting.h"
#include "Fragment.h"

TEST(initFragmentTest, fragmentTest) {

    char b[] = "00010101100010001000100010001000";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    char ruleId[] = "000";
    char emptyChar[] = "\0";
    char w[] = "10";
    char fcn[] = "101";

    ASSERT_EQ(strcmp(ruleId,fragment.HEADER.RULE_ID),0);
    ASSERT_EQ(strcmp(emptyChar,fragment.HEADER.DTAG),0);
    ASSERT_EQ(strcmp(w,fragment.HEADER.W),0);
    ASSERT_EQ(strcmp(fcn,fragment.HEADER.FCN),0);

}


TEST(initFragmentTestOne, fragmentTest) {

    char b[] = "00010111100010001000100010001000";
    char *h = bin_to_hex(b);

    try {
        Fragment fragment = fragment.from_hex(h);
    }
    catch (BadProfileError const & err ) {
        ASSERT_EQ(err.message,"Padding was not all zeroes nor empty");
    }
}


TEST(initFragmentTestTwo, fragmentTest) {

    char b[] = "00010111100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    char ruleId[] = "000";
    char emptyChar[] = "\0";
    char w[] = "10";
    char fcn[] = "111";
    char rcs[] = "100";

    ASSERT_EQ(strcmp(ruleId,fragment.HEADER.RULE_ID),0);
    ASSERT_EQ(strcmp(emptyChar,fragment.HEADER.DTAG),0);
    ASSERT_EQ(strcmp(w,fragment.HEADER.W),0);
    ASSERT_EQ(strcmp(fcn,fragment.HEADER.FCN),0);
    ASSERT_EQ(strcmp(rcs,fragment.HEADER.RCS),0);
}



TEST(toBinTest, fragmentTest) {
    char b[] = "00010101100010001000100010001000";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_EQ(strcmp(b,fragment.to_bin()),0);
}

TEST(isAllOneTest, fragmentTest) {
    char b[] = "00010111100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_TRUE(fragment.is_all_one());
}

TEST(isAllZeroTest, fragmentTest) {
    char b[] = "00010000100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_TRUE(fragment.is_all_zero());

}

TEST(isAllZeroFalseTest, fragmentTest) {
    char b[] = "00010101100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_FALSE(fragment.is_all_zero());
}

TEST(expectsAckTest, fragmentTest) {
    char b[] = "00010000100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_TRUE(fragment.expects_ack());

    char bin[] = "00010101100000000100010001000100";
    char *hex = bin_to_hex(bin);
    Fragment fragmentTwo = fragmentTwo.from_hex(hex);

    ASSERT_FALSE(fragmentTwo.expects_ack());

}

TEST(senderAbortTest, fragmentTest) {
    char b[] = "00011111";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_TRUE(fragment.is_sender_abort());
}


TEST(senderAbortTestTwo, fragmentTest) {
    char b[] = "00011111100000000100010001000100";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    ASSERT_FALSE(fragment.is_sender_abort());
}