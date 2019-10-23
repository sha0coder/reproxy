#include "proxy.h"
#include "rsocket.h"
#include <stdlib.h>



Proxy::Proxy(QObject *parent) : QThread(parent) {
    isStoping = false;
    isRunning = false;
    isUDP = false;
    isOk = true;
    mutReadyForSend.unlock();
}

void Proxy::stop() {
    isStoping = true;
}

void Proxy::closeConnections() {
    // force close connection
    // only call this when the engine already exited the loop, or on the Quit menu.

    if (!isRunning)
        return;

    isRunning = false;
    rTSock->close();
    lTSock->close();
    lTServer->close();

    delete rTSock;
    delete lTSock;
    delete lTServer;

    memset(buff, 0, BUFF_SZ);
    free(buff);
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

char *Proxy::getBufferPtr() {
    return this->buff;
}

// run

void Proxy::run() {
    isStoping = false;
    isRunning = true;

    emit sigConnecting();

    rTSock = new QTcpSocket();
    rTSock->connectToHost(rHost, rPort);
    //connect(rTSock, SIGNAL(disconnected()), this, SLOT(onTcpRemoteDisconnected()));
    //connect(rTSock, SIGNAL(readyRead()), this, SLOT(onReadTcpRemote()));
    if (!rTSock->waitForConnected(CONNECTION_TIMEOUT)) {
        isRunning = false;
        emit sigCantConnect("cannot connect.");
        rTSock->close();
        delete rTSock;
        return;
    }


    emit sigRConnected();

    lTSock = NULL;
    lTServer = new QTcpServer();
    //connect(lTServer, SIGNAL(newConnection()), this, SLOT(onNewTcpConnection()));

    if (!lTServer->listen(QHostAddress::Any, lPort)) {
        emit sigCantConnect("cant open the local port");
        goto end_thread;
    }


    bool bTimedout = false;

    while (true) {
        lTServer->waitForNewConnection(LISTEN_TIMEOUT, &bTimedout);
        if (!isRunning)
            goto end_thread;
        if (!bTimedout)
            break;
    }

    lTSock = lTServer->nextPendingConnection();

    buff = (char *)malloc(BUFF_SZ+1);



    emit sigLConnected();


    mutReadyForSend.unlock();
    while (!isStoping) {
        if (!lTSock || !rTSock)
            goto end_thread;

        if (lTSock->state() != lTSock->ConnectedState || rTSock->state() != rTSock->ConnectedState) {
            emit sigDisconnected();
            goto end_thread;
        }

        if (!lTSock || !rTSock)
            goto end_thread;

        if (lTSock->waitForReadyRead(READ_TIMEOUT)) {

            memset(buff, 0, BUFF_SZ);
            sz = lTSock->read(buff, BUFF_SZ);
            if (sz > 0) {
                mutReadyForSend.lock();
                emit sigClientData(buff, sz);

                mutReadyForSend.lock(); // the window must unlock this
                rTSock->write(buff, sz);
                rTSock->flush();
                mutReadyForSend.unlock();
            }
        }

        if (!lTSock || !rTSock)
            goto end_thread;

        if (rTSock->waitForReadyRead(READ_TIMEOUT)) {
            memset(buff, 0, BUFF_SZ);
            sz = rTSock->read(buff, BUFF_SZ);
            if (sz > 0) {
                mutReadyForSend.lock();
                emit sigEndpiontData(buff, sz);

                mutReadyForSend.lock();
                lTSock->write(buff, sz);
                rTSock->flush();
                mutReadyForSend.unlock();
            }
        }
    }


    //rTSock->blockSignals(true);
    //lTSock->blockSignals(true);
end_thread:
    isRunning = false;
    closeConnections();

    emit sigDisconnected();
}

// SLOTS

void Proxy::onReadyToSend(int sz) {
    this->sz = sz;
    mutReadyForSend.unlock();
}

void Proxy::onNewTcpConnection() {
    if (isRunning) {
        emit setStatus("error: new clients trying to connect");
        return;
    }


    lTSock = lTServer->nextPendingConnection();
    connect(lTSock, SIGNAL(disconnected()), this, SLOT(onTcpLocalDisconnected()));
    connect(lTSock, SIGNAL(readyRead()), this, SLOT(onReadTcpLocal()));


    isRunning = true;
    emit sigLConnected();
}

void Proxy::onTcpLocalDisconnected() {
    stop();
}

void Proxy::onTcpRemoteDisconnected() {
    stop();
}

void Proxy::onReadTcpLocal() {

        // usar QByteArray array = server_socket.read(erver_socket.bytesAvailable());

    QByteArray buff;
    buff.clear();

    if (!isRunning)
        return;

    buff = lTSock->readAll();
    if (buff.size()>0)
        rTSock->write(buff.constData(), buff.size());

}

void Proxy::onReadTcpRemote() {
    QByteArray buff;
    buff.clear();

    if (!isRunning)
        return;

    buff = rTSock->readAll();
    if (buff.size() > 0)
        lTSock->write(buff.constData(), buff.size());


}
