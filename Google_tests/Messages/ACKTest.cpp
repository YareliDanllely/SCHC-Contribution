#include "gtest/gtest.h"
#include "ACK.h"
#include "SigFoxProfile.h"


TEST(fromHexTest,ackTets){
    char bin[] = "0001001111001000000000000000000000000000000000000000000000000000";
    char *as_hex = bin_to_hex(bin);
    ACK ack = ack.from_hex(as_hex);

    ASSERT_EQ(SigFoxProfile::DOWNLINK_MTU_, strlen(hex_to_bin(ack.to_hex())));
}