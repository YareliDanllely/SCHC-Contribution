#include "gtest/gtest.h"
#include <sigFoxClient.h>
#include <sigFoxServer.h>

TEST(initTest, sigFoxSocket){
    sigFoxServer socket;
    ASSERT_EQ(socket.TIMEOUT, 60);
    ASSERT_EQ(socket.PORT,5000);
    ASSERT_EQ(socket.SEQNUM , 0);
    ASSERT_FALSE(socket.EXPECTS_ACK);
}