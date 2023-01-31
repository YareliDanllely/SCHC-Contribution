#ifndef SCHC_CONTRIBUTION_SIGFOXCLIENT_H
#define SCHC_CONTRIBUTION_SIGFOXCLIENT_H
#include "Socket.h"

class sigFoxClient : public Socket{
public:
    char DEVICE[10] = "1a2b3c";

    /**
     *  initialize socket parameters
     * @param port
     */
     void initializeSocket(int port);

    /**
     * Receives data from the socket buffer
     * @param bufSize
     * @return
     */
    virtual char *recvMessage(int bufSize);

};


#endif //SCHC_CONTRIBUTION_SIGFOXCLIENT_H
