#include "rproxy.h"
#include "rsocket.h"

RProxy::RProxy(QObject *parent) : QThread(parent) {
    isRunning = false;
    isUDP = false;
    isOk = true;
}

void RProxy::stop() {
    isRunning = false;
}

bool RProxy::running() {
    return isRunning;
}

bool RProxy::ok() {
    return isOk;
}

// setters

void RProxy::setLPort(int lport) {
    lPort = lport;
    if (lport == 0) {
        emit setStatus("incorrect local port!");
        isOk = false;
    }
}

void RProxy::setRPort(int rport) {
    rPort = rport;
    if (rport == 0) {
        emit setStatus("incorrect remote port!");
        isOk = false;
    }
}

void RProxy::setRHost(QString rhost) {
    rHost = rhost;
    if (rhost.size() == 0) {
        emit setStatus("incorrect hostname!");
        isOk = false;
    }
}

void RProxy::setUDP() {
    isUDP = true;
}

void RProxy::setTCP() {
    isUDP = false;
}


// run

void RProxy::run() {

    isRunning = true;
    emit setStatus("Starting RProxy");
    emit sigConnected();

    rSock = new RSocket(!isUDP, CONNECTION_TIMEOUT);
    rSock->dial(rHost.toStdString(), rPort);
    if (!rSock->ok()) {
        emit setStatus(QString::fromUtf8(rSock->getError()));
        return;
    }

    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }


    //rSock.shutdown();
    delete rSock;

    emit sigDisconnected();
    emit setStatus("RProxy end");
}


