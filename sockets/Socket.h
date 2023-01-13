
#ifndef SCHC_CONTRIBUTION_SOCKET_H
#define SCHC_CONTRIBUTION_SOCKET_H

#if defined(WIN64)
#include <winsock2.h>
# pragma comment(lib,"ws2_32.lib")
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

using namespace std;
#include <iostream>
#include "Socket.h"



class Socket {
public:
     bool EXPECTS_ACK = false;
     int SEQNUM = 0;
     int TIMEOUT = 60;
     int PORT = 5000;

     int SOCKET = socket(AF_INET, SOCK_STREAM, 0);


    /**
     * Sends data towards the receiver end
     * @param message
     */
    virtual void sendMessage(char* message) {
        send(SOCKET,message, sizeof(message),0);
        SEQNUM +=1;
    }

    /**
       * Configures the socket to be able to receive a message after sending one
       * @param flag
       */

    virtual void set_reception( bool flag) {
        EXPECTS_ACK = flag;
    }

    /**
     * Configures the timeout value of the socket, in seconds
     * @param timeOut
     */

    virtual void set_timeout(float timeOut ){
        TIMEOUT = timeOut;
    }

};


#endif //SCHC_CONTRIBUTION_SOCKET_H
