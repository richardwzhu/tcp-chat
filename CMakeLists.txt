cmake_minimum_required(VERSION 3.10)
project(tcp_chat)

set(CMAKE_CXX_STANDARD 17)

# Include the headers from the include directory
include_directories(include)

# Add common source files
set(COMMON_SOURCES
    src/common/utils.cpp
)

# Add server executable
add_executable(server 
    src/server/main.cpp 
    src/server/server.cpp
    ${COMMON_SOURCES}
)

# Add client executable
add_executable(client 
    src/client/main.cpp 
    src/client/client.cpp
    ${COMMON_SOURCES}
)
