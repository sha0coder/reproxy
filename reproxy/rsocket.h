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
    const char *getError();
    bool ok();
    bool timeout();
    void dial(std::string host, int port);
    void serve(int port, int num_connections);
    void shutdown();
    long int push(char *data, size_t sz);
    long int pop(char *data, size_t sz);

    //bool connected();
    bool isReadyForRead(int timeout);
    bool isReadyForWrite(int timeout);
    char wait();


private:
    int sock;
    int cSock;
    sockaddr_in endpoint;
    sockaddr_in client;
    socklen_t clientLen;
    struct timeval tv;
    bool isTcp;
    bool isConnected;
    bool isTimeout;
    std::string err;

    void setError(std::string msg);
    void setNonBlocking();

};

#endif // SOCKET_H
