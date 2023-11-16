// src/client/main.cpp
#include "client/client.h"
#include "common/constants.h"
#include <iostream>

int main() {
    const std::string server_ip = "127.0.0.1";  // Server IP
    const int server_port = tcp_chat::common::DEFAULT_PORT;  // Server port

    tcp_chat::client::Client client(server_ip, server_port);
    client.connectToServer();

    std::string message = "Hello from client";
    client.sendMessage(message);
    std::cout << "Message sent: " << message << std::endl;

    std::string response = client.receiveMessage();
    std::cout << "Response from server: " << response << std::endl;

    return 0;
}
