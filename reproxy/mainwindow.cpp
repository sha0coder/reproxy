#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proxy.h"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow) {
    ui->setupUi(this);
    silent = false;
    isReadyForSend = false;
    ui->lStatus->setText("Disconnected.");

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setProxy(Proxy *proxy) {
    this->proxy = proxy;
    enableSettings();

    //this->proxy->setMainWindow((void *)this);
    //this->proxy->check();
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

// button Events

void MainWindow::on_bConnect_clicked() {
    if (!proxy->isRunning()) {
        // Connect
        clear();

        if (proxy->settings(ui->eLPort->text().toInt(), ui->eRHost->text(), ui->eRPort->text().toInt(), ui->rUDP->isChecked())) {
            disableSettings();
            std::thread th(&Proxy::start, proxy); //, &this->ui);

        } else {
            box("Incorrect settings!");
        }

    } else {
        // Dissconnect

        proxy->stop();
        enableSettings();
        box("Dissconnected!");
    }
}

void MainWindow::on_bSend_clicked() {
    if (proxy->isConnected())
        isReadyForSend = true;
}

void MainWindow::testSignal() {
    std::cout << "lol" << std::endl;
}

