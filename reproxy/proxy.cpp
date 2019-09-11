#include "proxy.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

Proxy::Proxy(Ui::MainWindow *ui) {
    this->acceptLock = false;
    this->is_connected = false;
    this->ui = ui;
    this->is_running = false;

    uniform_int_distribution<int> dist(0, 6);
    cout << "random num: " << dist(r) << endl;
}

bool Proxy::settings(int lport, QString rhost, int rport, bool isUDP) {
    // no port zero allowed for now

    if (lport <= 0) {
        ui->lStatus->setText("Incorrect local port!");
        return false;
    }

    if (rport <= 0) {
        ui->lStatus->setText("Incorrect remote endpoint port!");
        return false;
    }

    if (rhost == "") {
        ui->lStatus->setText("Incorrect endpoint host!");
        return false;
    }

    this->lPort = lport;
    this->rHost = rhost;
    this->rPort = rport;
    this->isUDP = isUDP;

    return sockaddrConfig();
}

bool Proxy::isConnected() {
    return this->is_connected;
}

bool Proxy::isRunning() {
    return this->is_running;
}

bool Proxy::sockaddrConfig() {
    QByteArray brHost = rHost.toLocal8Bit();

    struct hostent *h = gethostbyname(brHost.data());
    if (!h) {
        ui->lStatus->setText("Cannot resolve the remote host!");
        return false;
    }

    rEndPoint.sin_family = AF_INET;
    rEndPoint.sin_port = htons(rPort);
    rEndPoint.sin_addr = *(struct in_addr *)(h->h_addr);

    lEndPoint.sin_family = AF_INET;
    lEndPoint.sin_port = htons(rPort);
    lEndPoint.sin_addr.s_addr = INADDR_ANY;

    return true;
}

bool Proxy::setNonBlockingSocket(int *sock) {
    int opt;

    if ((opt = fcntl (*sock, F_GETFL, NULL)) < 0) {
        return false;
    }


    if (fcntl (*sock, F_SETFL, opt | O_NONBLOCK) < 0) {
        return false;
    }

    return true;
}

void Proxy::start(){ //Ui::MainWindow *ui) {
    //this->ui = ui;
    ui->bConnect->setEnabled(false);
    ui->lStatus->setText("Connecting ...");

    if (isUDP)
        startUDPProxy();
    else
        startTCPProxy();

     ui->bConnect->setEnabled(true);

    /*
    this->is_connected = true;
    ui->lStatus->setText("Connected.");
    ui->bConnect->setText("Dissconnect");
    ui->bConnect->setEnabled(true);
    */

}

void Proxy::stop() {
    this->is_running = false;
}



/*
void Proxy::disconnect(bool silent) {

    ui->bConnect->setEnabled(false);
    ui->lStatus->setText("Disconnecting ...");

    close(rSock);
    close(lSock);
    close(cSock);

    this->is_connected = false;
    ui->lStatus->setText("Disconnected.");
    ui->bConnect->setText("Connect");
    ui->bConnect->setEnabled(true);
}*/

void Proxy::startTCPProxy() {
    int r, rSock;
    struct timeval timeout;
    timeout.tv_sec = 8;
    timeout.tv_usec = 0;

    rSock = socket(AF_INET, SOCK_STREAM, 0);
    if (rSock<1) {
        ui->lStatus->setText("can not create a socket.");
        return;
    }

    if (!setNonBlockingSocket(&rSock)) {
        ui->lStatus->setText("can not create a non blocking socket.");
        return;
    }

    r = connect(rSock, (struct sockaddr *)&this->rEndPoint, sizeof(this->rEndPoint));
    if (r<0) {
        if (errno == EINPROGRESS) {
            fd_set wait_set;
            FD_ZERO (&wait_set);
            FD_SET (rSock, &wait_set);

            r = select (rSock + 1, &wait_set, &wait_set, NULL, &timeout);
        } else {
            ui->lStatus->setText("can not connect");
            return;
        }
    }

    if (r <= 0) {
        ui->lStatus->setText("can not connect.");
        return;
    }

    // CONNECTED TO RHOST
    this->is_connected = true;
    this->is_running = true;
    ui->lStatus->setText("Connected.");
    ui->bConnect->setText("Dissconnect");
    ui->bConnect->setEnabled(true);



    close(rSock);

}

void Proxy::startUDPProxy() {

}
