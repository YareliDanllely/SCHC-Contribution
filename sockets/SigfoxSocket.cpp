#include <iostream>
using namespace std;
#include "Socket.h"
#if defined(WIN64)
#include <winsock2.h>
# pragma comment(lib,"ws2_32.lib")
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

class SigfoxSocket : public Socket {
public:
    char DEVICE[10] = "1a2b3c";
    int SOCKET = socket(AF_INET, SOCK_STREAM, 0);
    int PORT = 5000;

    void connectSocket(int port){

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

        /* Connect to server */
        int connectStatus = connect(SOCKET, (struct sockaddr*)&serverAdress, sizeof(serverAdress));

    }

    void sendMessage(char* message) override {
        connectSocket(PORT);
        SEQNUM +=1;
        send(SOCKET,message, sizeof(message),0);
    }

    char *recvMessage(int bufSize) override {

        char readMessage[bufSize];
        int iResult;

        iResult = recv(SOCKET,readMessage,sizeof(readMessage),0);
        if (iResult == 8) {
            throw invalid_argument("Received data is larger than buffer size.");
        }

    }

    void set_reception( bool flag) override{
        EXPECTS_ACK = flag;
    }

    void set_timeout(float timeOut ) override{
        TIMEOUT = timeOut;
    }



};