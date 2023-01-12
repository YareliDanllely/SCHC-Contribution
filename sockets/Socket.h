//
// Created by Usuario on 12-01-2023.
//

#ifndef SCHC_CONTRIBUTION_SOCKET_H
#define SCHC_CONTRIBUTION_SOCKET_H


class Socket {
public:
    bool EXPECTS_ACK = false;
    int SEQNUM = 0;
    int TIMEOUT = 60;

};


#endif //SCHC_CONTRIBUTION_SOCKET_H
