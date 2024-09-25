#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>
#include <stdexcept>
#include <thread>
#include "client.hh"

using namespace std;

Client::Client(const string& host, int port) : host_(host), port_(port) {
    sock_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_ == -1) {
        throw runtime_error("Failed to create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_);
    inet_pton(AF_INET, host_.c_str(), &server_addr.sin_addr);

    if (connect(sock_, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        throw runtime_error("Failed to connect to server");
    }
}

void Client::send(const string& message) {
    send(sock_, message.c_str(), message.size(), 0);

    char buffer[1024];
    int bytes_read = recv(sock_, buffer, sizeof(buffer), 0);

    cout << "Received " << bytes_read << " bytes: " << buffer << endl;
    close(sock_);
}