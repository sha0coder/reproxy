#ifndef SOCKET_H
#define SOCKET_H

#include <string>

#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

class RSocket {
public:
    RSocket();
    RSocket(bool tcp, int timeout);
    ~RSocket();
    int getSock();
    void setTimeout(int secs);
    std::string getError();
    bool ok();
    bool timeout();
    void dial(std::string host, int port);
    void serve(int port);
    void shutdown();
    long int push(char *data, size_t sz);
    long int pop(char *data, size_t sz);

    /*
    bool connected();
    bool isReadyForRead();
    bool isReadyForWrite();*/



private:
    int sock;
    sockaddr_in endpoint;
    struct timeval tv;
    bool isTcp;
    bool isConnected;
    bool isTimeout;
    std::string err;

    void setError(std::string msg);
    void setNonBlocking();

};

#endif // SOCKET_H
