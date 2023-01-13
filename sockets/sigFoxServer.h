//
// Created by Usuario on 13-01-2023.
//

#ifndef SCHC_CONTRIBUTION_SIGFOXSERVER_H
#define SCHC_CONTRIBUTION_SIGFOXSERVER_H
#include "Socket.h"

class sigFoxServer: public Socket {
public:
    char DEVICE[10] = "1a2b3c";

    /**
     * initialize socket parameters
     * @param port
     */
    virtual void initializeSocket(int port)  {

#if defined(WIN64)

        /* initialize winsock */
        WSAData wsaData;

        int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

        if (iResult != 0) {
            cout << "error at WSASturtup" << endl;
        }

#endif

        /* Define server address */
        struct sockaddr_in serverAdress;

        serverAdress.sin_family = AF_INET;
        serverAdress.sin_port = htons(port);
        serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");

        /* Bind socket to the specified address and port */
        int bindConnection = bind(SOCKET, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

        /* Bind connection error */
        if (bindConnection < 0 ) {
            cout << "Bind failed" << endl;
        }

        /*listen for connections */
        listen(SOCKET,1);

        
    }

    /**
     * Receives data from the socket buffer
     * @param bufSize
     * @return
     */
    virtual char *recvMessage(int bufSize)  {

        int client = accept(SOCKET,NULL, NULL);

        /* valid connection  */
        if (client < 0 ){
            cout << "Error on accepting" << endl;
        }

        char readMessage[bufSize];
        int iResult;

        iResult = recv(client,readMessage,sizeof(readMessage),0);
        if (iResult == 8) {
            throw invalid_argument("Received data is larger than buffer size.");
        }

        char * finalMessage = (char *) malloc(bufSize+1);
        char * pointer = finalMessage;
        strcpy(finalMessage,readMessage);
        pointer += bufSize +1;
        *pointer = '\0';

        return finalMessage;

    }


};


#endif //SCHC_CONTRIBUTION_SIGFOXSERVER_H
