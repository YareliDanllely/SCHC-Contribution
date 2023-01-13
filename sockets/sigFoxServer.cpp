
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
#include "sigFoxServer.h"

void sigFoxServer::initializeSocket(int port)  {
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



