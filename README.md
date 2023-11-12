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

## Installation

#### Prerequisites:
* A C++ compiler (e.g., g++ or clang)

#### Compilation:
Navigate to the respective directories (`src/server/` and `src/client/)` and run the following commands to compile the server and client:

For the server:
```bash
g++ -o server main.cpp
```

For the client:
```bash
g++ -o client main.cpp
```

## Usage
Start the Server:
Navigate to the server's directory and run `./server`.
The server will start and listen for incoming connections.
Run the Client:
In a new terminal, navigate to the client's directory and run `./client`.
The client will connect to the server and you can start chatting.
