
#ifndef SCHC_CONTRIBUTION_SOCKET_H
#define SCHC_CONTRIBUTION_SOCKET_H


class Socket {
public:
     bool EXPECTS_ACK = false;
     int SEQNUM = 0;
     int TIMEOUT = 60;
     int PORT = 5000;


     /**
      * initalize socket parameters
      * @param port
      */

     virtual void initializeSocket(int port);

    /**
     * Sends data towards the receiver end
     * @param message
     */
    virtual void sendMessage(char* message);

    /**
     * Receives data from the socket buffer
     * @param bufsize
     * @return
     */
    virtual char *recvMessage(int bufSize);

    /**
     * Configures the socket to be able to receive a message after sending one
     * @param flag
     */
    virtual void set_reception( bool flag);

    /**
     * Configures the timeout value of the socket, in seconds
     * @param timeOut
     */
    virtual void set_timeout(float timeOut );


};


#endif //SCHC_CONTRIBUTION_SOCKET_H
