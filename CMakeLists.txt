cmake_minimum_required(VERSION 3.10)
project(tcp_chat)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(server src/server/main.cpp src/server/server.cpp)
add_executable(client src/client/main.cpp src/client/client.cpp)
