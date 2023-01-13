#include "gtest/gtest.h"
#include <sigFoxClient.h>
#include <sigFoxServer.h>



TEST(initTestClient, sigFoxSocket){
    sigFoxClient socket;
    char deviceClient[10] = "1a2b3c";
    ASSERT_EQ(socket.TIMEOUT, 60);
    ASSERT_EQ(socket.PORT,5000);
    ASSERT_EQ(socket.SEQNUM , 0);
    ASSERT_FALSE(socket.EXPECTS_ACK);
    ASSERT_EQ(strcmp(socket.DEVICE,deviceClient),0);
}


TEST(initTestServer, sigFoxSocket){
    sigFoxServer socket;
    char deviceClient[10] = "1a2b3c";
    ASSERT_EQ(socket.TIMEOUT, 60);
    ASSERT_EQ(socket.PORT,5000);
    ASSERT_EQ(socket.SEQNUM , 0);
    ASSERT_FALSE(socket.EXPECTS_ACK);
    ASSERT_EQ(strcmp(socket.DEVICE,deviceClient),0);
}

TEST(sendMessageClient, sigFoxSocket){
    sigFoxServer socketServer;
    sigFoxClient socketClient;

    socketServer.initializeSocket(socketServer.PORT);
    socketClient.initializeSocket(socketClient.PORT);

    char sendMessage[] = "hi i'm a test";

    socketClient.sendMessage(sendMessage);
    ASSERT_EQ(socketClient.SEQNUM,1);

}