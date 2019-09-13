#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QObject>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow) {
    ui->setupUi(this);
    silent = false;
    isReadyForSend = false;
    ui->lStatus->setText("Disconnected.");

    proxy = new RProxy(this);
    connect(proxy, SIGNAL(setStatus(QString)), this, SLOT(setStatusMessage(QString)));
    connect(proxy, SIGNAL(sigConnected()), this, SLOT(statConnected()));
    connect(proxy, SIGNAL(sigDisconnected()), this, SLOT(statDisconnected()));

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

void MainWindow::statConnected() {
    disableSettings();
    ui->bConnect->setText("Disconnect");
}

void MainWindow::statDisconnected() {
    enableSettings();
    ui->bConnect->setText("Connect");
    box("disconnected");
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


        if (proxy->ok())
            proxy->start();


    } else {
        // Dissconnect

        proxy->stop();
    }
}

void MainWindow::on_bSend_clicked() {
    if (proxy->running())
        isReadyForSend = true;
}

