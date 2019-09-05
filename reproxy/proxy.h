#ifndef PROXY_H
#define PROXY_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <random>
#include <iostream>
#include "mainwindow.h"

const int IN = 1;
const int OUT = 2;


class Proxy {
public:
    int TIMEOUT = 5;
    int lport;
    int rport;
    bool acceptLock;
    std::string rhost;
    bool isUDP;
    bool is_connected;
    std::string endpoint;
    int lSock;
    int rSock;
    int cSock;
    sockaddr_in lEndPoint;
    sockaddr_in rEndPoint;
    MainWindow *mainWindow;
    std::random_device r;


    Proxy(MainWindow *mainWindow);
    bool isConnected();
    bool isAcceptLocked();
    void wait(int secs);
    void disconnect(bool silent);
    bool config(int lport, int rport, std::string rhost, bool isUDP);
    void initSockets(bool isUDP);
    void connect();


protected:
    void tryCloseSocket(int sock);
    void displayBuffer(char *buff, int sz, int direction);
    void waitSendButton();
    char *mutate(char *buff, int sz);
    void init();
    bool isSocketConnected(int s);
    void startTCPProxy();
    void startUDPProxy();
};

#endif // PROXY_H
