#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

extern "C" {
int create_server(int* port, char* buffer, int buffer_size, char*(request_handle)(char*, void*), void* data, bool* loaded, bool* run) {
    // Create the address to bind the socket to
    struct sockaddr_in host_addr;
    socklen_t host_addrlen = sizeof(struct sockaddr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(*port == 0) {
        host_addr.sin_port = 0;
    } else {
        host_addr.sin_port = htons(*port);
    }

    memset(host_addr.sin_zero, '\0', sizeof(host_addr.sin_zero));

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("webserver (socket)");
        return 0;
    }

    if(*port) {
        const int enable = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
            perror("setsockopt(SO_REUSEADDR) failed");
            return 0;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0) {
            perror("setsockopt(SO_REUSEADDR) failed");
            return 0;
        }
    }

    // Bind the socket to the address
    while (bind(sockfd, (struct sockaddr *)&host_addr, host_addrlen) != 0) {}
    *loaded = true;
    
    if (getsockname(sockfd, (struct sockaddr *)&host_addr, &host_addrlen) == -1) {
        perror("getsockname");
        return 0;
    }
    
    *port = ntohs(host_addr.sin_port);

    // Listen for incoming connections
    if (listen(sockfd, SOMAXCONN) != 0) {
        perror("webserver (listen)");
        return 0;
    }

    struct sockaddr_in client_addr;
    int client_addrlen = sizeof(client_addr);

    while (*run) {
        memset(buffer, 0, sizeof(char) * buffer_size);
        // Accept incoming connections
        int newsockfd = accept(sockfd, (struct sockaddr *)&host_addr,
                               (socklen_t *)&host_addrlen);
        if (newsockfd < 0) {
            perror("webserver (accept)");
            continue;
        }

        // Get client address
        int sockn = getsockname(newsockfd, (struct sockaddr *)&client_addr,
                                (socklen_t *)&client_addrlen);
        if (sockn < 0) {
            perror("webserver (getsockname)");
            continue;
        }

        // Read from the socket
        int valread = read(newsockfd, buffer, buffer_size);
        if (valread < 0) {
            perror("webserver (read)");
            continue;
        }

        char* response = request_handle(buffer, data);

        // Write to the socket
        int valwrite = write(newsockfd, response, strlen(response));
        if (valwrite < 0) {
            perror("webserver (write)");
            continue;
        }

        close(newsockfd);
    }

    return 1;
}
}