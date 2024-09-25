#ifndef CLIENT_HH
#define CLIENT_HH

#include <string>

class Client {
public:
    Client(const std::string& host, int port);
    void send(const std::string& message);

private:
    std::string host_;
    int port_;
    int sock_;
};

#endif