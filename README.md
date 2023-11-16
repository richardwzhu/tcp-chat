# TCP Chat Server and Client

## Introduction
A simple chat server and client that communicates over TCP.

## Project Structure

```plaintext
tcp-chat/
│
├── src/                    # Source files
│   ├── server/             # Server specific code
│   │   ├── main.cpp
│   │   └── ...
│   ├── client/             # Client specific code
│   │   ├── main.cpp
│   │   └── ...
│   └── common/             # Common code used by both server and client
│       └── ...
│
├── include/                # Header files
│   ├── server/
│   ├── client/
│   └── common/
│
├── tests/                  # Unit tests
│   └── ...
│
├── docs/                   # Documentation files
│   └── ...
│
├── CMakeLists.txt          # CMake project file
└── README.md               # Project overview and guide
```

## Installation Prerequisites

Before you begin, ensure your system meets the following requirements:
* C++ Compiler: A modern C++ compiler is needed. g++ (on Linux) or Clang (on macOS) is recommended.
* Operating System: The instructions are written for Unix-like operating systems, including Linux distributions and macOS.

## Compilation
Navigate to the respective directories (`src/server/` and `src/client/)` and run the following commands to compile the server and client and create executables in their respective direcotires:

For the server:
```bash
g++ -o server main.cpp server.cpp -I../../include/
```
* -o server specifies the name of the output executable.
* main.cpp and server.cpp are the source files.
* -I../../include/ tells the compiler where to find the header files.

For the client:
```bash
g++ -o client main.cpp client.cpp -I../../include/
```

## Running the Program
Start the Server:
Navigate to the server's directory and run `./server`.

Run the Client:
In a new terminal, navigate to the client's directory and run `./client`.

* Server Side: The server listens for incoming connections. Once a client connects, it receives a message from the client, processes it, and can send back a response.
* Client Side: The client connects to the server, sends a predefined message, and displays the response received from the server.
* End of Session: The client will automatically terminate after receiving the server's response. The server, however, will continue to run, waiting for new connections. To stop the server, use Ctrl+C in the server's terminal window.
