//
// Created by Usuario on 13-01-2023.
//

#include "sigFoxServer.h"


/**
 *  run server to test
 * @return
 */

int main(){

    char sendAnswer[] = "test2";

    SERVER.initializeSocket(SERVER.PORT);
    MessageClient = SERVER.recvMessage(4);
    SERVER.sendMessage(sendAnswer);

    printf("%s\n",MessageClient);


}

