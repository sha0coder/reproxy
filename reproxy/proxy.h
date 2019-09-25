#ifndef RPROXY_H
#define RPROXY_H

#include <QThread>
#include <QObject>
#include <QtCore>
#include <QtNetwork>

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
    const int LISTEN_TIMEOUT = 60*1000;
    const int READ_TIMEOUT = 10;
    const int BUFF_SZ = 1024;
    char *buff;
    int lPort;
    int rPort;
    bool isUDP;
    bool isOk;
    bool isRunning;
    QString rHost;
    QTcpSocket *rTSock;
    QTcpServer *lTServer;
    QTcpSocket *lTSock;

public:
    explicit Proxy(QObject *parent = 0);
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
    void sigEndpiontData(char *buff, qint64 sz);
    void sigClientData(char *buff, qint64 sz);


public slots:
    void onNewTcpConnection();
    void onTcpLocalDisconnected();
    void onReadTcpLocal();
    void onTcpRemoteDisconnected();
    void onReadTcpRemote();
};

#endif // RPROXY_H
