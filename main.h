#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5000
#define SERVER_LENGTH 10
#define SERVER_BUFF 256

using namespace std;

void extract_client1(const string data);
void extract_client2(const string data);
void extract_client3(const string data);
void extract_client4(const string data);
