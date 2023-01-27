#include "gtest/gtest.h"
#include "SenderAbort.h"


TEST(initSenderAbortTest, senderAbortTest) {
    char b[] = "00010101100010001000100010001000";
    char w[] = "11";
    char fcn[] = "111";
    char rcs[] = "\0";
    char *h = bin_to_hex(b);
    Fragment fragment = fragment.from_hex(h);

    SenderAbort abort = SenderAbort(fragment.HEADER);

    ASSERT_EQ(fragment.HEADER.RULE_ID, abort.HEADER.RULE_ID);
    ASSERT_EQ(strcmp(fragment.HEADER.DTAG, abort.HEADER.DTAG),0);
    ASSERT_EQ(strcmp(w, abort.HEADER.W),0);
    ASSERT_EQ(strcmp(fcn, abort.HEADER.FCN),0);
    ASSERT_EQ(strcmp(rcs, abort.HEADER.RCS),0);

    ASSERT_FALSE(fragment.is_sender_abort());
    ASSERT_TRUE(abort.is_sender_abort());

    char bin[] = "00011111100000000100010001000100";
    char *hex = bin_to_hex(bin);
    Fragment fragment1 = fragment1.from_hex(hex);

    SenderAbort abort1 = SenderAbort(fragment1.HEADER);

    ASSERT_EQ(fragment1.HEADER.RULE_ID, abort1.HEADER.RULE_ID);
    ASSERT_EQ(strcmp(fragment1.HEADER.DTAG, abort1.HEADER.DTAG),0);
    ASSERT_EQ(strcmp(w, abort1.HEADER.W),0);
    ASSERT_EQ(strcmp(fcn, abort1.HEADER.FCN),0);
    ASSERT_EQ(strcmp(rcs, abort1.HEADER.RCS),0);

    ASSERT_FALSE(fragment1.is_sender_abort());
    ASSERT_TRUE(abort1.is_sender_abort());

}
