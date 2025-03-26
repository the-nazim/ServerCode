#include "main.h"

void extract_client1(const string data)
{
    string str = data.substr(data.find(':')+2);
    stringstream ss(str);
    string token;
    while(getline(ss, token, ';'))
    {
        int pos = token.find('=');
        if(pos != string::npos)
        {
            string key = token.substr(0,pos);
            string value = token.substr(pos+1);
            cout<< key << " : " << value << endl;
        }
    }
}

void extract_client2(const string data)
{
    string str = data.substr(data.find(':')+2);
    stringstream ss(str);
    string token;
    while(getline(ss, token, ';'))
    {
        int pos = token.find('=');
        if(pos != string::npos)
        {
            string key = token.substr(0,pos);
            string value = token.substr(pos+1);
            cout<< key << " : " << value << endl;
        }
    }
}

void extract_client3(const string data)
{
    string str = data.substr(data.find(':')+2);
    stringstream ss(str);
    string token;
    while(getline(ss, token, ';'))
    {
        int pos = token.find('=');
        if(pos != string::npos)
        {
            string key = token.substr(0,pos);
            string value = token.substr(pos+1);
            cout<< key << " : " << value << endl;
        }
    }
}

void extract_client4(const string data)
{
    string str = data.substr(data.find(':')+2);
    stringstream ss(str);
    string token;
    while(getline(ss, token, ';'))
    {
        int pos = token.find('=');
        if(pos != string::npos)
        {
            string key = token.substr(0,pos);
            string value = token.substr(pos+1);
            cout<< key << " : " << value << endl;
        }
    }
}