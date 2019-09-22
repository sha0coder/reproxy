#ifndef RPROXY_H
#define RPROXY_H

#include <QThread>
#include <QObject>
#include <thread>
#include <chrono>

#include "rsocket.h"

class RProxy : public QThread
{
    Q_OBJECT
private:
    int CONNECTION_TIMEOUT = 5;
    int READWRITE_TIMEOUT = 5;
    int lPort;
    int rPort;
    bool isUDP;
    bool isOk;
    bool isRunning;
    QString rHost;
    RSocket *rSock;
    RSocket *lSock;

public:
    explicit RProxy(QObject *parent = 0);
    void run(void);
    void stop(void);
    bool running(void);
    bool ok();

    void setLPort(int lport);
    void setRPort(int rport);
    void setRHost(QString rhost);
    void setUDP();
    void setTCP();

signals:
    void setStatus(QString msg);
    void sigDisconnected();
    void sigRConnected();
    void sigLConnected();
    void sigCantConnect(QString errmsg);
    void sigConnecting();

public slots:
};

#endif // RPROXY_H
