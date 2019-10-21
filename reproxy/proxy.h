#ifndef RPROXY_H
#define RPROXY_H

#include <QThread>
#include <QObject>
#include <QtCore>
#include <QtNetwork>
#include <QMutex>

/*
#include <thread>
#include <chrono>*/

#include "rsocket.h"

class Proxy : public QThread
{
    Q_OBJECT
private:
    const int CONNECTION_TIMEOUT = 5*1000;
    const int READWRITE_TIMEOUT = 5*1000;
    const int LISTEN_TIMEOUT = 1*1000;
    const int READ_TIMEOUT = 10;
    const int BUFF_SZ = 1024;
    char *buff;
    int sz;
    int lPort;
    int rPort;
    bool isUDP;
    bool isOk;
    bool isRunning;    // internal, feasible means if the thread is alive
    bool isStoping;    // stop signal, it will try to stop, when it will turn isRunning=false when really is stoped
    QString rHost;
    QTcpSocket *rTSock;
    QTcpServer *lTServer;
    QTcpSocket *lTSock;
    QMutex mutReadyForSend;

public:
    explicit Proxy(QObject *parent = 0);

    void run(void);
    void closeConnections(void);
    void stop(void);
    bool running(void);
    bool ok();

    void setLPort(int lport);
    void setRPort(int rport);
    void setRHost(QString rhost);
    void setUDP();
    void setTCP();
    char *getBufferPtr();


signals:
    void setStatus(QString msg);
    void sigDisconnected();
    void sigRConnected();
    void sigLConnected();
    void sigCantConnect(QString errmsg);
    void sigConnecting();
    void sigEndpiontData(char *buff, int sz);
    void sigClientData(char *buff, int sz);


public slots:
    void onNewTcpConnection();
    void onTcpLocalDisconnected();
    void onReadTcpLocal();
    void onTcpRemoteDisconnected();
    void onReadTcpRemote();
    void onReadyToSend(int);
};

#endif // RPROXY_H
