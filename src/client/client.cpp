// src/client/client.cpp
#include "client/client.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

namespace tcp_chat {
    namespace client {

        Client::Client(const std::string& server_ip, int server_port) 
            : server_ip(server_ip), server_port(server_port) {
            setupSocket();
        }

        Client::~Client() {
            close(sock);
        }

        void Client::setupSocket() {
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                std::cerr << "Socket creation error" << std::endl;
                exit(EXIT_FAILURE);
            }

            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(server_port);

            if (inet_pton(AF_INET, server_ip.c_str(), &serv_addr.sin_addr) <= 0) {
                std::cerr << "Invalid address/ Address not supported" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        void Client::connectToServer() {
            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                std::cerr << "Connection Failed" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        void Client::sendMessage(const std::string& message) {
            send(sock, message.c_str(), message.length(), 0);
        }

        std::string Client::receiveMessage() {
            char buffer[1024] = {0};
            read(sock, buffer, 1024);
            return std::string(buffer);
        }

    } // namespace client
} // namespace tcp_chat
