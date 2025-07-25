// Chat-App-Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

bool Initialize() {
    WSADATA data;
    return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}



int main()
{
    if (!Initialize()) {
        cout << "Initialize winsock failed" << endl;
        return 1;
    }

    SOCKET s;
    s = socket(AF_INET,SOCK_STREAM,0);
    if (s == INVALID_SOCKET) {
        cout << "Invalid socket created" << endl;
        return 1;
    }

    int port = 12345;
    string serveraddress = "127.0.0.1";
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));
    if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
        cout << "Not able to connect with server" << endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }
    cout<<"Connection with server is successful"<<endl;

    //send & Receieve
    string message = "Hello there";
    int bytesent;
    bytesent = send(s, message.c_str(), message.length(), 0);

    if (bytesent == SOCKET_ERROR) {
        cout << "Sent Failed" << endl;
    }
    closesocket(s);

    cout << "client code" << endl;

    WSACleanup();
    return 0;
}
