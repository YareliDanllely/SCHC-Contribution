#ifndef SCHC_CONTRIBUTION_SIGFOXSERVER_H
#define SCHC_CONTRIBUTION_SIGFOXSERVER_H
#include "Socket.h"
#include <vector>

class sigFoxServer: public Socket {
public:
    char DEVICE[10] = "1a2b3c";
    int CLIENT;

    /**
     * initialize socket parameters
     * @param port
     */
    virtual void initializeSocket(int port);

    /**
     * Receives data from the socket buffer
     * @param bufSize
     * @return
     */
    virtual char *recvMessage(int bufSize);

    /**
     * Send message to client
     * @param message
     */
    void sendMessage(char *message) override;

};


#endif //SCHC_CONTRIBUTION_SIGFOXSERVER_H
