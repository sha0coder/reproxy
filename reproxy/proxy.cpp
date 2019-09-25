#include "proxy.h"
#include "rsocket.h"
#include <stdlib.h>



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

    rTSock = new QTcpSocket();
    rTSock->connectToHost(rHost, rPort);
    //connect(rTSock, SIGNAL(disconnected()), this, SLOT(onTcpRemoteDisconnected()));
    //connect(rTSock, SIGNAL(readyRead()), this, SLOT(onReadTcpRemote()));
    if (!rTSock->waitForConnected(CONNECTION_TIMEOUT)) {
        emit sigCantConnect("cannot connect.");
        rTSock->close();
        delete rTSock;
        return;
    }


    emit sigRConnected();

    lTSock = NULL;
    lTServer = new QTcpServer();
    //connect(lTServer, SIGNAL(newConnection()), this, SLOT(onNewTcpConnection()));
    lTServer->listen(QHostAddress::Any, lPort);
    lTServer->waitForNewConnection(LISTEN_TIMEOUT);
    lTSock = lTServer->nextPendingConnection();

    buff = (char *)malloc(BUFF_SZ+1);
    qint64 sz;

    isRunning = true;
    emit sigLConnected();


    qDebug() << "start the party" << endl;
    while (isRunning) {


        if (lTSock->waitForReadyRead(READ_TIMEOUT)) {

            memset(buff, 0, BUFF_SZ);
            sz = lTSock->read(buff, BUFF_SZ);
            if (sz > 0) {
                rTSock->write(buff, sz);
                qDebug() << ">> " << buff << endl;
                rTSock->flush();
            }
        }

        if (rTSock->waitForReadyRead(READ_TIMEOUT)) {
            memset(buff, 0, 1024);
            sz = rTSock->read(buff, BUFF_SZ);
            if (sz > 0) {
                lTSock->write(buff, sz);
                qDebug() << "<< " << buff << endl;
                rTSock->flush();
            }
        }
    }


    //rTSock->blockSignals(true);
    //lTSock->blockSignals(true);

    isRunning = false;
    rTSock->close();
    lTSock->close();
    lTServer->close();

    delete rTSock;
    delete lTSock;
    delete lTServer;


    memset(buff, 0, BUFF_SZ);
    free(buff);

    emit sigDisconnected();
}

// SLOTS

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
