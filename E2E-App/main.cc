#include <thread>
#include <iostream>
#include <chrono>
#include "server.hh"
#include "client.hh"

using namespace std;

int main() {
    try {

        // Ask user if they want to be a client or server
        cout << "Do you want to start a client or server? (C/S): ";
        char choice;
        cin >> choice;

        if (choice == 'S' || 's') {
        // Start a server
            cout << "Enter a port number to listen on: ";
            short port;
            cin >> port;

            thread server_thread([port] {
                Server server(port);
                server.run();
                });

            this_thread::sleep_for(chrono::seconds(1));
            server_thread.join();    
        } else if (choice == 'C' || 'c') {
        // Start a client
            cout << "Enter the server's IP address: ";
            string ip;
            cin >> ip;

            cout << "Enter the server's port number: ";
            short port;
            cin >> port;

            Client client(ip, port);
            cout << "Enter a message to send: ";
            string message;
            cin.ignore();
            getline(cin, message);
            client.send(message);
        } else {
            cout << "Invalid choice. Exiting..." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}