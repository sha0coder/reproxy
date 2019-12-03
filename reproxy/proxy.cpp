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

void Proxy::forceStop() { // dont do this
    isStoping = true;
    isRunning = false;
    try {
        if (rTSock && rTSock->isOpen())
            rTSock->close();
        if (lTSock && lTSock->isOpen())
            lTSock->close();
        //if (lTServer)
        //    lTServer->close();
    } catch(const std::exception& e) {
        qDebug() << "forced to stop" << endl;
    }
}

void Proxy::closeConnections() { // dont do this
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

    //memset(buff, 0, BUFF_SZ);
    //free(buff);
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

    qDebug() << "starting proxy thread" << endl;
    emit sigConnecting();

    try {


    qDebug() << "connecting to rHost " << rHost << endl;
    rTSock = new QTcpSocket();
    rTSock->connectToHost(rHost, rPort);
    //connect(rTSock, SIGNAL(disconnected()), this, SLOT(onTcpRemoteDisconnected()));
    //connect(rTSock, SIGNAL(readyRead()), this, SLOT(onReadTcpRemote()));
    qDebug() << "waiting for connected" << endl;
    if (!rTSock->waitForConnected(CONNECTION_TIMEOUT)) {
        qDebug() << "timeout" << endl;
        isRunning = false;
        emit sigCantConnect("cannot connect.");
        rTSock->close();
        delete rTSock;
        return;
    }
    qDebug() << "connected" << endl;

    emit sigRConnected();

    lTSock = NULL;

    // avoid pre opened states
    qDebug() << "checking previous listeners" << endl;
    //if (lTServer && lTServer->isListening())
    //    lTServer->close();

    lTServer = new QTcpServer();
    //connect(lTServer, SIGNAL(newConnection()), this, SLOT(onNewTcpConnection()));
    qDebug() << " awaiting connections " << endl;

    if (!lTServer->listen(QHostAddress::Any, lPort)) {
        qDebug() << " listen failed " << endl;
        if(isRunning)
            emit sigCantConnect("cant open the local port");
        isRunning = false;
        closeConnections();
        return;
    }

    qDebug() << "wait loop" << endl;
    bool bTimedout = false;


    while (true && lTServer) {
        qDebug() << "wait loop start iteration" << endl;
        if (lTServer->waitForNewConnection(LISTEN_TIMEOUT, &bTimedout))
            break;

        if (isStoping) {
            closeConnections();
            isRunning = false;
            emit sigCantConnect("disconnection when listening");
            return;
        }

        if (!bTimedout)
            break;
    }
    qDebug() << "wait loop ended" << endl;

    lTSock = lTServer->nextPendingConnection();

    qDebug() << "allocating buffer" << endl;
    buff = (char *)malloc(BUFF_SZ+1);


    emit sigLConnected();


    mutReadyForSend.unlock();
    qDebug() << "starting main loop" << endl;
    while (!isStoping) {
        qDebug() << "iteration" << endl;
        if (!lTSock || !rTSock) // || !lTSock->isOpen() || !rTSock->isOpen())
            break;

        qDebug() << "iteration1" << endl;
        if (lTSock->state() != lTSock->ConnectedState || rTSock->state() != rTSock->ConnectedState) {
            emit sigDisconnected();
            break;
        }
        qDebug() << "iteration2" << endl;
        if (!lTSock || !rTSock || isStoping) // || !lTSock->isOpen() || !rTSock->isOpen())
            break;

        qDebug() << "iteration3" << endl;
        if (lTSock->waitForReadyRead(READ_TIMEOUT)) {

            if (isStoping)
                break;

            qDebug() << "doing memset" << endl;
            memset(buff, 0, BUFF_SZ);

            qDebug() << "reading buffer" << endl;
            sz = lTSock->read(buff, BUFF_SZ);
            if (sz > 0) {
                qDebug() << "lock" << endl;
                mutReadyForSend.lock();
                emit sigClientData(buff, sz);

                mutReadyForSend.lock(); // the window must unlock this
                qDebug() << "going to write" << endl;
                rTSock->write(buff, sz);
                rTSock->flush();
                mutReadyForSend.unlock();
                qDebug() << "unlock" << endl;
            }
        }

        if (isStoping)
            break;

        qDebug() << "iteration4" << endl;
        if (!lTSock || !rTSock || isStoping) // || !lTSock->isOpen() || !rTSock->isOpen())
            break;

        qDebug() << "iteration5" << endl;
        if (rTSock->waitForReadyRead(READ_TIMEOUT)) {
            if (isStoping)
                break;

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



    closeConnections();
    free(buff);
    isRunning = false;

    emit sigDisconnected();



    //rTSock->blockSignals(true);
    //lTSock->blockSignals(true);
    } catch(...) {
        if (lTServer)
            lTServer->close();

        qDebug() << "finally stopped forcefully" << endl;
        isRunning = false;
    }

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
