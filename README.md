# TCP Chat Server and Client

A simple chat server and client that communicates over TCP.

## Project Structure

```
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
