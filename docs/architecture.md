# Architecture Overview

## Components

- **Server:** Handles incoming client connections and processes messages.
- **Client:** Connects to the server, sends messages, and receives responses.

## Communication

- The client establishes a TCP connection with the server.
- Messages are sent over this connection using a simple protocol.
