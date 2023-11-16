cmake_minimum_required(VERSION 3.10)
project(tcp_chat)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock,
# gmock_main
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)

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

# Add server test executable
add_executable(server_tests tests/server_tests.cpp)
add_library(server_lib 
    src/server/server.cpp 
    src/common/utils.cpp
)
target_link_libraries(server_tests gtest gtest_main server_lib)

# Add client test executable
add_executable(client_tests tests/client_tests.cpp)
add_library(client_lib 
    src/client/client.cpp 
    src/common/utils.cpp
)
target_link_libraries(client_tests gtest gtest_main client_lib)
