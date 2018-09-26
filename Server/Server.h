#ifndef MPOINTERS_SERVER_H
#define MPOINTERS_SERVER_H

#include "../Mapa_Memoria.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

class Server {
public:
    Server(int);
    void run();
private:
   // Mapa_Memoria<int> *memory;
    int contador_direcciones;
    int IDs;

    int server_fd;
    int new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
};


#endif //MPOINTERS_SERVER_H
