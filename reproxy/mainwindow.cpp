#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow) {
    ui->setupUi(this);
    silent = false;
    isReadyForSend = false;
    ui->lStatus->setText("Disconnected.");

    proxy = new Proxy(this);
    connect(proxy, SIGNAL(setStatus(QString)), this, SLOT(setStatusMessage(QString)));
    connect(proxy, SIGNAL(sigLConnected()), this, SLOT(statLConnected()));
    connect(proxy, SIGNAL(sigRConnected()), this, SLOT(statRConnected()));
    connect(proxy, SIGNAL(sigDisconnected()), this, SLOT(statDisconnected()));
    connect(proxy, SIGNAL(sigCantConnect(QString)), this, SLOT(statCantConnect(QString)));
    connect(proxy, SIGNAL(sigConnecting()), this, SLOT(statConnecting()));
    connect(proxy, SIGNAL(sigClientData(char*,qint64)), this, SLOT(onClientData(char*,qint64));
    connect(proxy, SIGNAL(sigEndpiontData(char*,qint64)), this, SLOT(onEndpointData(char*,qint64));

    QStringList titles;
    titles << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "A" << "B" << "C" << "D" << "E" << "F" << "Data";
    ui->tHex->setColumnCount(17);
    ui->tHex->setHorizontalHeaderLabels(titles);
    for (int i=0; i<16; i++)
        ui->tHex->setColumnWidth(i, 18);
    ui->tHex->setColumnWidth(16, 350);

    //ui->tHex->insertRow(0);

    clear();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::clear() {
    ui->eId->setText("0");
    ui->eIn->setText("0");
    ui->eOut->setText("0");
    ui->eSize->setText("0");
}

void MainWindow::disableSettings() {
    ui->eLPort->setDisabled(true);
    ui->eRPort->setDisabled(true);
    ui->eRHost->setDisabled(true);
    ui->rTCP->setDisabled(true);
    ui->rUDP->setDisabled(true);
}

void MainWindow::enableSettings() {
    ui->eLPort->setEnabled(true);
    ui->eRPort->setEnabled(true);
    ui->eRHost->setEnabled(true);
    ui->rTCP->setEnabled(true);
    ui->rUDP->setEnabled(true);
}

void MainWindow::box(QString msg) {
    if (this->silent)
        return;

    QMessageBox msgBox;
    msgBox.setWindowTitle("reproxy");
    msgBox.setText(msg);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.exec();
}

// slots

void MainWindow::setStatusMessage(QString msg) {
    this->ui->lStatus->setText(msg);
}

void MainWindow::statRConnected() {
    disableSettings();
    ui->lStatus->setText("connected to endpoint, waiting for client ...");
    ui->bConnect->setText("Disconnect");
    ui->bConnect->setEnabled(false);
    box("connect the client please");
}

void MainWindow::statLConnected() {
    disableSettings();
    ui->lStatus->setText("connected!");
    ui->bConnect->setText("Disconnect");
    ui->bConnect->setEnabled(true);
}

void MainWindow::statDisconnected() {
    enableSettings();
    ui->lStatus->setText("disconnected");
    ui->bConnect->setText("Connect");
    box("disconnected");
    ui->bConnect->setEnabled(true);
}

void MainWindow::statCantConnect(QString errmsg) {
    enableSettings();
    ui->lStatus->setText("can't connect "+errmsg);
    ui->bConnect->setText("Connect");
    box("cant connect");
    ui->bConnect->setEnabled(true);
}

void MainWindow::statConnecting() {
    disableSettings();
    ui->lStatus->setText("Connecting ...");
    ui->bConnect->setEnabled(false);
}

void MainWindow::onEndpointData(char *buff, qint64 sz) {

}

void MainWindow::onClientData(char *buff, qint64 sz) {

}

// button Events

void MainWindow::on_bConnect_clicked() {

    if (!proxy->running()) {

        // Connect

        proxy->setLPort(ui->eLPort->text().toInt());
        proxy->setRHost(ui->eRHost->text());
        proxy->setRPort(ui->eRPort->text().toInt());
        if (ui->rUDP->isChecked())
            proxy->setUDP();
        else
            proxy->setTCP();


        if (proxy->ok()) {
            ui->bConnect->setEnabled(false);
            proxy->start();
        }

    } else {
        // Dissconnect

        proxy->stop();
    }
}

void MainWindow::on_bSend_clicked() {
    if (proxy->running())
        isReadyForSend = true;
}

