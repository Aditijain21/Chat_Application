// Chat-App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<tchar.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

bool Initialize() {
    WSADATA data;
    return WSAStartup(MAKEWORD(2,2), &data) == 0;
}


int main()
{
    if (!Initialize()) {
        cout<<"Winsock initialization failed"<<endl;
        return 1;
    }
    
    SOCKET listenSocket = socket(AF_INET,SOCK_STREAM,0);

    if (listenSocket == INVALID_SOCKET) {
        cout << "Socket Connection Failed" << endl;
        return 1;
    }

    //Create socket structure
    int port = 12345;
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);

    //Convert the IP address(0.0.0.0) put it inside the sin_family in binary format
    if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1) {
        cout << "Setting address structure failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    //bind
    if (bind(listenSocket, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
        cout << "Bind failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    //listen
    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
        cout << "Listen Failed" << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    cout << "Server has started listening on the port :" << port << endl;

    //accept
    SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Invalid client Socket" << endl;
    }

    char buffer[4095];
    int bytesrecvd = recv(clientSocket, buffer, sizeof(buffer), 0);
    string message(buffer, bytesrecvd);
    cout << "Message from client" << message << endl;

    closesocket(clientSocket);
    closesocket(listenSocket);










    WSACleanup();
}
