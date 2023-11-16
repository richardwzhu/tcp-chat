// src/server/server.cpp
#include "server/server.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

namespace tcp_chat {
    namespace server {

        Server::Server(int port) : port(port) {
            setupSocket();
            bindSocket();
        }

        Server::~Server() {
            close(server_fd);
        }

        void Server::setupSocket() {
            server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd == 0) {
                perror("socket failed");
                exit(EXIT_FAILURE);
            }
        }

        void Server::bindSocket() {
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons(port);

            if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
                perror("bind failed");
                exit(EXIT_FAILURE);
            }
        }

        void Server::listenForConnections() {
            if (listen(server_fd, 3) < 0) {
                perror("listen");
                exit(EXIT_FAILURE);
            }
        }

        void Server::run() {
            listenForConnections();
            std::cout << "Server is listening on port " << port << std::endl;

            while (true) {
                int addrlen = sizeof(address);
                int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
                if (new_socket < 0) {
                    perror("accept");
                    continue;  // continue to accept next connection
                }

                handleClient(new_socket);
                close(new_socket);
            }
        }

        void Server::handleClient(int clientSocket) {
            char buffer[1024] = {0};
            read(clientSocket, buffer, 1024);
            std::cout << "Message from client: " << buffer << std::endl;

            const char *response = "Hello from server";
            send(clientSocket, response, strlen(response), 0);
        }

    } // namespace server
} // namespace tcp_chat
