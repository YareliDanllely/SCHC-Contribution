#if defined(WIN64)
#include <winsock2.h>
# pragma comment(lib,"ws2_32.lib")
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
#include <iostream>
using namespace std;

int main() {

    /* variables */

    char  readMessage[255];
    char message[255] = "Hello from server";

    int portNum = 9001;

#if defined(WIN64)

    /* initialize winsock */
    WSAData wsaData;

    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    if (iResult != 0) {
        cout << "error at WSASturtup" << endl;
    }

#endif

    /* Create a server socket */
    int serverSocket = socket(AF_INET,SOCK_STREAM,0);

    /* Create socket error */
    if ( serverSocket < 0 ){
        cout << "Can't create Socket" << endl;
        WSACleanup();
    }

    /* Define server address */
    struct sockaddr_in serverAdress;

    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(portNum);
    serverAdress.sin_addr.s_addr = INADDR_ANY;

    /* Bind socket to the specified address and port */
    int bindConnection = bind(serverSocket, (struct sockaddr *)&serverAdress, sizeof(serverAdress));

    /* Bind connection error */
    if (bindConnection < 0 ) {
        cout << "Bind failed" << endl;
    }

    /*listen for connections */
    listen(serverSocket,1);
    cout << "Waiting for connections.." << endl;

    /* integer to hold client socket */
    int client = accept(serverSocket,NULL, NULL);

    /* valid connection  */
    if (client < 0 ){
        cout << "Error on accepting" << endl;
    }

    /* read message from client */
    recv(client,readMessage, sizeof(readMessage),0);
    cout << "Message from client: " << readMessage << endl;

    /* client response */
    send(client, message, sizeof(message), 0);
    cout << "Message sent" << endl;

    /* closing the connected socket */

    closesocket(client);

#if defined(WIN64)
    WSACleanup();
#endif

    return 0;
}