#include "proxy.h"
#include "rsocket.h"
#include <stdlib.h>

#include <QtCore>
#include <QtNetwork>

Proxy::Proxy(QObject *parent) : QThread(parent) {
    isRunning = false;
    isUDP = false;
    isOk = true;
}

void Proxy::stop() {
    isRunning = false;
}

bool Proxy::running() {
    return isRunning;
}

bool Proxy::ok() {
    return isOk;
}

// setters

void Proxy::setLPort(int lport) {
    lPort = lport;
    if (lport == 0) {
        emit setStatus("incorrect local port!");
        isOk = false;
    }
}

void Proxy::setRPort(int rport) {
    rPort = rport;
    if (rport == 0) {
        emit setStatus("incorrect remote port!");
        isOk = false;
    }
}

void Proxy::setRHost(QString rhost) {
    rHost = rhost;
    if (rhost.size() == 0) {
        emit setStatus("incorrect hostname!");
        isOk = false;
    }
}

void Proxy::setUDP() {
    isUDP = true;
}

void Proxy::setTCP() {
    isUDP = false;
}


// run

void Proxy::run() {
    emit sigConnecting();



    /*

    rSock = new RSocket(!isUDP, CONNECTION_TIMEOUT);
    rSock->dial(rHost.toStdString(), rPort);
    if (!rSock->ok()) {
        emit sigCantConnect(QString::fromStdString(rSock->getError()));
        return;
    }

    emit sigRConnected();

    lSock = new RSocket(!isUDP, CONNECTION_TIMEOUT);
    lSock->serve(lPort, 1);
    if (!rSock->ok()) {
        emit sigCantConnect(QString::fromStdString(rSock->getError()));
        return;
    }

    isRunning = true;
    emit sigLConnected();

    int sz;
    char *buff;
    buff = (char *)malloc(1024);

    while (isRunning) {
        if (lSock->isReadyForRead(1)) {
            sz = lSock->pop(buff, 1024);

            if (rSock->isReadyForWrite(1))
                rSock->push(buff, sz);
            else
                emit setStatus("cant send the data to server");

        }

        if (rSock->isReadyForRead(1)) {
            sz = rSock->pop(buff, 1024);

            if (lSock->isReadyForWrite(1))
                lSock->push(buff, sz);
            else
                emit setStatus("cant send the data to client");
        }

        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    free(buff);

    delete rSock;
    delete lSock;*/

    emit sigDisconnected();
}

