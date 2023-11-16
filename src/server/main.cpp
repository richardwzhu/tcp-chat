// src/server/main.cpp
#include "server/server.h"

int main() {
    const int port = 8080;  // You can choose a different port if required
    tcp_chat::server::Server server(port);
    server.run();
    return 0;
}
