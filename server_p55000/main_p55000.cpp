#include <iostream>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
    WSADATA data;
    WORD version = MAKEWORD(2, 2);

    int wsOk = WSAStartup(version, &data);
    if (wsOk != 0)
    {
        cout << "Can't start Winsock! " << wsOk;
        return 1;
    } 

    // Create the second socket for port 55000
    SOCKET in55000 = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverHint55000;
    serverHint55000.sin_addr.S_un.S_addr = ADDR_ANY;
    serverHint55000.sin_family = AF_INET;
    serverHint55000.sin_port = htons(55000);

    if (bind(in55000, (sockaddr*)&serverHint55000, sizeof(serverHint55000)) == SOCKET_ERROR)
    {
        cout << "Can't bind socket to port 55000! " << WSAGetLastError() << endl;
        return 1;
    }

    sockaddr_in client;
    int clientLength = sizeof(client);

    char buf[1024];

    while (true)
    {
        // Receive on port 55000
        ZeroMemory(&client, clientLength);
        ZeroMemory(buf, 1024);

        int bytesIn55000 = recvfrom(in55000, buf, 1024, 0, (sockaddr*)&client, &clientLength);
        if (bytesIn55000 != SOCKET_ERROR)
        {
            char clientIp[256];
            ZeroMemory(clientIp, 256);
            inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);
            cout << "Message recv from " << clientIp << " on port 55000: " << buf << endl;
        }
    }

    // Close socket
    closesocket(in55000);

    // Shutdown winsock
    WSACleanup();
    return 0;
}
