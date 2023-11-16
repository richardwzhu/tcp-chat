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

# Setup Instructions

## System Requirements

* C++ Compiler (e.g., g++, Clang)
* CMake (version 3.10 or higher)

## Installation Steps

1. Clone the repository:
```bash
git clone https://github.com/richardwzhu/tcp-chat
```

2. Navigate to the project directory:
```bash
cd tcp-chat
```
3. Create a build directory and navigate into it:
```bash
mkdir build && cd build
```

4. Run CMake to configure the project:
```bash
cmake ..
```

5. Compile the project:
```bash
make
```

## Running the Server and Client

* To run the server:
```bash
./server
```

* To run the client:
```bash
./client
```

* Server Side: The server listens for incoming connections. Once a client connects, it receives a message from the client, processes it, and can send back a response.
* Client Side: The client connects to the server, sends a predefined message, and displays the response received from the server.
* End of Session: The client will automatically terminate after receiving the server's response. The server, however, will continue to run, waiting for new connections. To stop the server, use Ctrl+C in the server's terminal window.
