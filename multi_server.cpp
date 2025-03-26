#include "main.h"

int main() 
{
    int sock_fd, data_sock_fd, pid;
    struct sockaddr_in serv_addr;
    char serv_buffer[SERVER_BUFF];

    cout << "TCP_SERVER: Concurrent server is waiting..." << endl;

    // Create a TCP socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        cerr << "Socket creation failed" << endl;
        exit(EXIT_FAILURE);
    }

    // Bind it to a particular IP address & port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        cerr << "Binding failed" << endl;
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(sock_fd, SERVER_LENGTH) == -1) {
        cerr << "Listening failed" << endl;
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    // Infinite loop to accept multiple clients
    while (true) {
        data_sock_fd = accept(sock_fd, nullptr, nullptr);
        if (data_sock_fd == -1) {
            cerr << "Accept failed" << endl;
            continue;
        }

        pid = fork();
        if (pid < 0) {
            cerr << "Fork failed" << endl;
            close(data_sock_fd);
            continue;
        }

        // Child process to handle client
        if (pid == 0) {
            cout << "New child forked... awaiting input from client" << endl;
            while(true)
            {
                memset(serv_buffer, 0, sizeof(serv_buffer));
                recv(data_sock_fd, serv_buffer, SERVER_BUFF, 0);
                cout<< serv_buffer << endl;
                extract_data(serv_buffer);
            }
            close(data_sock_fd);
            exit(0);
        }
    }

    close(sock_fd);
    return 0;
}
