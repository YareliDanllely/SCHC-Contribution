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
    char message[255] = "Hello dear server";
    char readMessage[255];

    int portNum = 9001;

#if defined(WIN64)

    /* initialize winsock */
    WSAData wsaData;

    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

    if (iResult != 0) {
        cout << "error at WSASturtup" << endl;
    }

#endif

    /* Create socket*/
    int clientSocket = socket(AF_INET,SOCK_STREAM,0);

    /* Create socket error */
    if (clientSocket < 0 ) {
        cout << "Can't create Socket" << endl;
    }

    /* Define server address */
    struct sockaddr_in serverAdress;

    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(portNum);
    serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");


    /* Connect to server */
    int connectStatus = connect(clientSocket, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    /* Connection error */
    if (connectStatus < 0 ) {
        cout<< "Can't connect to server " << endl;
    }

        /* successful connection */
    else {

        /* send message */
        send(clientSocket,message, sizeof(message),0);
        cout << "Message sent" << endl;

        /* receive message*/
        recv(clientSocket,readMessage, sizeof(readMessage),0);
        cout << "Message from server: " <<readMessage << endl;
    }

    /* closing the connected socket */

    closesocket(clientSocket);

#if defined(WIN64)
    WSACleanup();
#endif

    return 0;
}