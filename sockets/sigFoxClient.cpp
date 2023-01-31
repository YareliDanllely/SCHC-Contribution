
#include "sigFoxClient.h"

void sigFoxClient::initializeSocket(int port) {

#if defined(WIN64)

    /* initialize winsock */
    WSAData wsaData;

    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    if (iResult != 0) {
        cout << "error at WSASturtup" << endl;
    }

#endif
    /* Create a server socket */
    SOCKET = socket(AF_INET,SOCK_STREAM,0);

    /* Create socket error */
    if ( SOCKET < 0 ){
        cout << "Can't create Socket" << endl;
        WSACleanup();
    }


    /* Define server address */
    struct sockaddr_in serverAdress;

    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(port);
    serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connect to server */
    int connectStatus = connect(SOCKET, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    /* Connection error */
    if (connectStatus < 0 ) {
        cout<< "Can't connect to server " << endl;
    }


}

char *sigFoxClient::recvMessage(int bufSize) {

    char readMessage[bufSize];
    int iResult;

    iResult = recv(SOCKET,readMessage,sizeof(readMessage),0);
    if (iResult == 8) {
        throw invalid_argument("Received data is larger than buffer size.");
    }

    set_reception(true);

    char * finalMessage = (char *) malloc(bufSize+1);
    char * pointer = finalMessage;
    strcpy(finalMessage,readMessage);
    pointer += bufSize +1;
    *pointer = '\0';

    return finalMessage;

}
