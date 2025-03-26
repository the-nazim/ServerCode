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

void extract_data(const string data);