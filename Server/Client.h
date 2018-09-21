#ifndef MPOINTERS_CLIENT_H
#define MPOINTERS_CLIENT_H

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

class Client {
public:
    Client();
    int connectClient();
    void sendMessage(char *);
    char *readMessage();

private:
    struct sockaddr_in address;
    bool isConnected;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
};


#endif //MPOINTERS_CLIENT_H
