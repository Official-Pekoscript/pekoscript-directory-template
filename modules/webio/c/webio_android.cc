#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
// #include <sys/types.h>

extern "C" {
int64_t create_server(int64_t *port, char *buffer, int64_t buffer_size, char *(request_handle)(char *, void *), void *data, bool *loaded, bool *run)
{
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);
    int i; // for loop var

    ///////////
    // SETUP //
    ///////////

    // Default values

    // Socket settings
    server_addr.sin_family = AF_INET;                // sets to use IP
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // sets our local IP address
    if(*port == 0) {
        server_addr.sin_port = 0;
    } else {
        server_addr.sin_port = htons(*port);
    }

    // Create Socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0); // creates IP based TCP socket
    if (socket_fd < 0) {
        printf("ERROR: Opening socket\n");
    }

    if(*port) {
        const int enable = 1;
        if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
            perror("setsockopt(SO_REUSEADDR) failed");
            return 0;
        }

        if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0) {
            perror("setsockopt(SO_REUSEADDR) failed");
            return 0;
        }
    }

    // Bind Socket
    while(bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) != 0) {}
    *loaded = true;

    socklen_t len = sizeof(struct sockaddr);

    if (getsockname(socket_fd, (struct sockaddr *)&server_addr, &len) == -1) {
        perror("getsockname");
        return 0;
    }

    bool port_is_zero = (*port == 0);

    *port = ntohs(server_addr.sin_port);

    printf("%lld\n", *port);
    fflush(stdout);

    // Listen to Socket
    if (listen(socket_fd, 10) != 0) {
        printf("ERROR: Socket listening failed\n");
        return 0;
    }

    while (*run)
    {
        // blocks until client sends connection
        int connect_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_size);
        int read_msg = read(connect_fd, buffer, buffer_size);

        char* response = request_handle(buffer, data);
        int write_msg = write(connect_fd, response, strlen(response));
    
        close(connect_fd);
    }
}
}