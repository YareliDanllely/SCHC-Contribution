#include "Socket.h"


void Socket::sendMessage(char *message) {
    send(SOCKET,message, sizeof(message),0);
    SEQNUM +=1;
}

void Socket::set_reception(bool flag) {
    EXPECTS_ACK = flag;
}

void Socket::set_timeout(float timeOut) {
    TIMEOUT = timeOut;
}
