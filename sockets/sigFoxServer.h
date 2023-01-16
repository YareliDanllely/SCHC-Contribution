//
// Created by Usuario on 13-01-2023.
//

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
    virtual void initializeSocket(int port) {

#if defined(WIN64)

        /* initialize winsock */
        WSAData wsaData;

        int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (iResult != 0) {
            cout << "error at WSASturtup" << endl;
        }

#endif

        /* Create a server socket */
        SOCKET = socket(AF_INET, SOCK_STREAM, 0);

        /* Create socket error */
        if (SOCKET < 0) {
            cout << "Can't create Socket" << endl;
            WSACleanup();
        }

        /* Define server address */
        struct sockaddr_in serverAdress;

        serverAdress.sin_family = AF_INET;
        serverAdress.sin_port = htons(port);
        serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");

        /* Bind socket to the specified address and port */
        int bindConnection = bind(SOCKET, (struct sockaddr *) &serverAdress, sizeof(serverAdress));

        /* Bind connection error */
        if (bindConnection < 0) {
            cout << "Bind failed" << endl;
        }

        /*listen for connections */
        listen(SOCKET, 1);


        CLIENT = accept(SOCKET, NULL, NULL);

        /* valid connection  */
        if (CLIENT < 0) {
            cout << "Error on accepting" << endl;
        }

    }

    /**
     * Receives data from the socket buffer
     * @param bufSize
     * @return
     */
    virtual char *recvMessage(int bufSize)  {

        char readMessage[bufSize+100];
        int iResult;

        recv(CLIENT,readMessage,sizeof(readMessage),0);
        set_reception(true);

        if (iResult == 8) {
            throw invalid_argument("Received data is larger than buffer size.");
        }

        char * pointer = readMessage;
        pointer += bufSize ;
        *pointer = '\0';
        printf("%s\n",readMessage);

        char * finalMessage = (char *) ::malloc(bufSize+1);
        strcpy(finalMessage,readMessage);

        return finalMessage;

    }

    void sendMessage(char *message) override {
        send(CLIENT,message, sizeof(message),0);
        SEQNUM +=1;
    }

};


/** variables to test **/

sigFoxServer SERVER;
char *MessageClient;



#endif //SCHC_CONTRIBUTION_SIGFOXSERVER_H
