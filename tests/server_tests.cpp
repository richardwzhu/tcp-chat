#include "gtest/gtest.h"
#include "server/server.h"
#include "common/constants.h"

namespace tcp_chat {
    namespace server {

        class ServerTest : public ::testing::Test {
        protected:
            Server *server;

            // This method runs before each test
            void SetUp() override {
                // Initialize the server with a test port
                server = new Server(tcp_chat::common::DEFAULT_PORT);
            }

            // This method runs after each test
            void TearDown() override {
                delete server;
            }
        };

        // Test cases

        // Test for successful server creation
        TEST_F(ServerTest, ServerCreation) {
            ASSERT_NE(server, nullptr);
        }

        // Test if the server binds to the correct port
        TEST_F(ServerTest, BindsToCorrectPort) {
            // This requires accessing the internal state of the Server class, which might not be directly testable
            // You might need to add getters or make the port public for this test
            ASSERT_EQ(server->getPort(), tcp_chat::common::DEFAULT_PORT);
        }

    } // namespace server
} // namespace tcp_chat
