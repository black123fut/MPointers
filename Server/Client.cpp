#include "Client.h"

#include <iostream>
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

/**
 * Constructor.
 */
Client::Client() {
    isConnected = false;
    connectClient();
}

Client *Client::client = nullptr;

/**
 * Obtiene el cliente.
 * @return El cliente.
 */
Client *Client::getClient(){
    if (client == nullptr){
        client = new Client;
    }
    return client;
}

/**
 * Envia un mensaje al servidor.
 * @param response Texto por enviar.
 */
void Client::sendMessage(char *response) {
    send(sock, response, strlen(response), 0);
}

/**
 * Lee el mensaje del servirdor.
 * @return El texto que envia el servidor.
 */
char *(Client::readMessage()) {
    char *buffer = new char[1024];

    valread = read(sock, buffer, 1024);
    return buffer;
}

/**
 * Conecta el cliente al servidor.
 * @return un entero.
 */
int Client::connectClient() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    /**
     * La ip es la del servidor.
     */
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        isConnected = false;
        return -1;
    }
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        isConnected = false;
        return -1;
    }
    else {
        isConnected = true;
    }

    return 0;
}
