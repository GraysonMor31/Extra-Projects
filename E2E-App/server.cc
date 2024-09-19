#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <stdexcept>
#include <thread>
#include "server.hh"

using namespace std;

Server::Server(short port) : port_(port) {
    server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd_ == -1) {
        throw runtime_error("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_);

    if (bind(server_fd_, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        throw runtime_error("Failed to bind socket");
    }

    if (listen(server_fd_, 5) == -1) {
        throw runtime_error("Failed to listen on socket");
    }
}

void Server::run() {
    cout << "Server listening on port " << port_ << endl;
    while (true) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd_, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            cerr << "Failed to accept client connection" << endl;
            continue;
        }

        thread client_thread(&Server::handle_client, this, client_fd);
        client_thread.detach();
    }
}

void Server::handle_client(int client_fd) {
    char buffer[1024];
    int bytes_read = read(client_fd, buffer, sizeof(buffer));

    cout << "Received " << bytes_read << " bytes: " << buffer << endl;
    send(client_fd, buffer, bytes_read, 0);
    close(client_fd);
}