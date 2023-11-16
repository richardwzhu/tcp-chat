// src/server/main.cpp
#include "server/server.h"
#include "common/constants.h"

int main() {
    const int port = tcp_chat::common::DEFAULT_PORT;  // You can choose a different port if required
    tcp_chat::server::Server server(port);
    server.run();
    return 0;
}
