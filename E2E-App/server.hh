#ifndef SERVER_HH
#define SERVER_HH

class Server {
public:
    Server(short port);
    void run();

private:
    short port_;
    short server_fd_;
    void handle_client(int client_fd);
};

#endif