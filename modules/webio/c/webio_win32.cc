#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <string.h>

extern "C" {
int64_t create_server(int64_t *port, char* buffer, int64_t buffer_size, char*(request_handle)(char*, void*), void* data, bool* loaded, bool* run) {
    int msg_len;
    int addr_len;
    struct sockaddr_in local, client_addr;

    SOCKET sock, msg_sock;
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 0), &wsaData) == SOCKET_ERROR)
    {
        // stderr: standard error are printed to the screen.
        fprintf(stderr, "WSAStartup failed with error %d\n", WSAGetLastError());
        // WSACleanup function terminates use of the Windows Sockets DLL.
        WSACleanup();
        return -1;
    }
    // Fill in the address structure
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;

    if(*port == 0) {
        local.sin_port = 0;
    } else {
        local.sin_port = htons(*port);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0); // TCp socket

    if (sock == INVALID_SOCKET)
    {
        fprintf(stderr, "socket() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    if (bind(sock, (struct sockaddr *)&local, sizeof(local)) == SOCKET_ERROR)
    {
        fprintf(stderr, "bind() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    socklen_t len = sizeof(local);

    if (getsockname(sock, (struct sockaddr *)&local, &len) == -1) {
        fprintf(stderr, "getsockname() failed with error %d\n", WSAGetLastError());
        return 0;
    }
    
    *port = ntohs(local.sin_port);

    // waiting the connection
    if (listen(sock, 5) == SOCKET_ERROR)
    {
        fprintf(stderr, "listen() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }

    while (*run)
    {
        addr_len = sizeof(client_addr);
        msg_sock = accept(sock, (struct sockaddr *)&client_addr, &addr_len);
        if (msg_sock == INVALID_SOCKET)
        {
            fprintf(stderr, "accept() failed with error %d\n", WSAGetLastError());
            WSACleanup();
            return -1;
        }

        if (msg_sock == -1)
        {
            perror("Unable to accept connection.");
            continue;
        }

        msg_len = recv(msg_sock, buffer, buffer_size, 0);

        char* response = request_handle(buffer, data);
        
        msg_len = send(msg_sock, response, strlen(response), 0);
        if (msg_len == 0)
        {
            printf("Closing\n");
            closesocket(msg_sock);
            return -1;
        }

        if (msg_len == SOCKET_ERROR)
        {
            fprintf(stderr, "recv() failed with error %d\n", WSAGetLastError());
            WSACleanup();
            return -1;
        }

        if (msg_len == 0)
        {
            printf("Closing2\n");
            closesocket(msg_sock);
            return -1;
        }
        closesocket(msg_sock);
    }
    WSACleanup();
}
}