// include/client/client.h

#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>
#include <string>

namespace tcp_chat {
    namespace client {

        class Client {
        public:
            Client(const std::string& server_ip, int server_port);
            ~Client();

            void connectToServer();
            void sendMessage(const std::string& message);
            std::string receiveMessage();

        private:
            int sock;
            struct sockaddr_in serv_addr;
            std::string server_ip;
            int server_port;

            void setupSocket();
        };

    } // namespace client
} // namespace tcp_chat

#endif // CLIENT_H
