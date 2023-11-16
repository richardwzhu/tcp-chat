// include/server/server.h

#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

namespace tcp_chat {
    namespace server {

        class Server {
        public:
            Server(int port);
            ~Server();

            void run();

        private:
            int server_fd;
            struct sockaddr_in address;
            int port;

            void setupSocket();
            void bindSocket();
            void listenForConnections();
            void handleClient(int clientSocket);
        };

    } // namespace server
} // namespace tcp_chat

#endif // SERVER_H
