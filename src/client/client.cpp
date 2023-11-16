// src/client/client.cpp
#include "client/client.h"
#include "common/constants.h"
#include "common/utils.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

namespace tcp_chat {
    namespace client {

        Client::Client(const std::string& server_ip, int server_port) 
            : server_ip(server_ip), server_port(server_port == 0 ? tcp_chat::common::DEFAULT_PORT : server_port) {
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
                tcp_chat::common::logMessage("Connection Failed");
                exit(EXIT_FAILURE);
            }
            tcp_chat::common::logMessage("Connected to server.");
        }

        void Client::sendMessage(const std::string& message) {
            send(sock, message.c_str(), message.length(), 0);
            tcp_chat::common::logMessage("Message sent: " + message);
        }

        std::string Client::receiveMessage() {
            char buffer[tcp_chat::common::BUFFER_SIZE] = {0};
            read(sock, buffer, tcp_chat::common::BUFFER_SIZE);
            std::string receivedMessage = std::string(buffer);
            tcp_chat::common::logMessage("Response from server: " + receivedMessage);
            return std::string(buffer);
        }

    } // namespace client
} // namespace tcp_chat
