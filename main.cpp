#include "main.h"

int main() 
{
    int sock_fd;
    struct sockaddr_in serv_addr, client_addr;
    char serv_buffer[SERVER_BUFF];
    socklen_t client_len = sizeof(client_addr);
    string serv_data;

    cout << "UDP_SERVER: Server is waiting for messages..." << endl;

    // Create a UDP socket
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
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

    // Infinite loop to receive and process client messages
    while (true) {
        memset(serv_buffer, 0, sizeof(serv_buffer));
        serv_data.clear();
        
        recvfrom(sock_fd, serv_buffer, SERVER_BUFF, 0, (struct sockaddr*)&client_addr, &client_len);
        cout << "Received Data: " << serv_buffer << endl;
        serv_data += serv_buffer;

        if (serv_data.find("Client1") != string::npos)
            extract_client1(serv_buffer);
        
        else if (serv_data.find("Client2") != string::npos)
            extract_client2(serv_buffer);

        else if (serv_data.find("Client3") != string::npos)
            extract_client3(serv_buffer);

        else if (serv_data.find("Client4") != string::npos)
            extract_client4(serv_buffer);
    }

    close(sock_fd);
    return 0;
}
