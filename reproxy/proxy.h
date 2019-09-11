#ifndef PROXY_H
#define PROXY_H

#pragma once


#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include <string>
#include <random>
#include <iostream>

#include "ui_mainwindow.h"


using namespace std;

const int IN = 1;
const int OUT = 2;


class Proxy {

private:
    int TIMEOUT = 5;
    int lPort;
    int rPort;
    /*
    int lSock;
    int rSock;
    int cSock;*/
    QString rHost;
    bool acceptLock;
    bool isUDP;
    bool is_connected;          /* this is the socket connection */
    bool is_running;            /* this is only to signal stop() */
    sockaddr_in lEndPoint;
    sockaddr_in rEndPoint;
    std::random_device r;
    Ui::MainWindow *ui;

public:
    Proxy(Ui::MainWindow *ui);
    void setMainWindow(void *mainWindow);
    bool settings(int lport, QString rhost, int rport, bool isUDP);
    bool isConnected();
    bool isAcceptLocked();
    bool isRunning();
    void wait(int secs);
    void start(); //Ui::MainWindow *ui);
    void stop();
    void disconnect(bool silent);
    void initSockets(bool isUDP);


protected:
    bool sockaddrConfig();
    void tryCloseSocket(int sock);
    void displayBuffer(char *buff, int sz, int direction);
    void waitSendButton();
    char *mutate(char *buff, int sz);
    bool isSocketConnected(int s);
    void startTCPProxy();
    void startUDPProxy();
    bool setNonBlockingSocket(int *sock);
};

#endif // PROXY_H
