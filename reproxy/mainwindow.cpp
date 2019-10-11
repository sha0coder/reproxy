#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow) {
    ui->setupUi(this);
    silent = false;
    //isReadyForSend = false;
    ui->lStatus->setText("Disconnected.");

    proxy = new Proxy(this);
    connect(proxy, SIGNAL(setStatus(QString)), this, SLOT(setStatusMessage(QString)));
    connect(proxy, SIGNAL(sigLConnected()), this, SLOT(statLConnected()));
    connect(proxy, SIGNAL(sigRConnected()), this, SLOT(statRConnected()));
    connect(proxy, SIGNAL(sigDisconnected()), this, SLOT(statDisconnected()));
    connect(proxy, SIGNAL(sigCantConnect(QString)), this, SLOT(statCantConnect(QString)));
    connect(proxy, SIGNAL(sigConnecting()), this, SLOT(statConnecting()));
    connect(proxy, SIGNAL(sigClientData(char*,int)), this, SLOT(onClientData(char*,int)));
    connect(proxy, SIGNAL(sigEndpiontData(char*,int)), this, SLOT(onEndpointData(char*,int)));
    connect(this, SIGNAL(sigReadyToSend(int)), proxy, SLOT(onReadyToSend(int)));
    connect(ui->tHex, SIGNAL(cellChanged(int,int)), this, SLOT(on_hexChanged(int,int)));

    resetHex();

    ui->eId->setDisabled(true);
    ui->eIn->setDisabled(true);
    ui->eOut->setDisabled(true);


    clearStats();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resetHex() {
    QStringList titles;
    titles << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "A" << "B" << "C" << "D" << "E" << "F" << "Data";
    ui->tHex->clear();
    ui->tHex->setColumnCount(17);
    ui->tHex->setHorizontalHeaderLabels(titles);
    for (int i=0; i<16; i++)
        ui->tHex->setColumnWidth(i, 25);
    ui->tHex->setColumnWidth(16, 250);
    //ui->tHex->insertRow(0);
}

void MainWindow::clearStats() {
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

void MainWindow::on_hexChanged(int row, int col) {
    bool ok;
    QChar *bytes;
    QString hex, data;
    unsigned int h;

    if (mutHex.tryLock()) {

        if (col < 16) {
            // user modified an hex box
            hex = ui->tHex->item(row,col)->text();
            h = hex.toInt(&ok, 16);
            if (!ok) {
                this->box("wrong hexadecimal value");
                ui->tHex->setItem(row, col, new QTableWidgetItem(QString("ff")));
                h = 0xff;
            }

            data = ui->tHex->item(row,16)->text();

            if (h > 0xff) {
                h = 0xff;
                ui->tHex->setItem(row, col, new QTableWidgetItem(QString("ff")));
            }

            bytes = data.data();
            if (h>=' ' && h<= '~')
                bytes[col] = (QChar)h;
            else
                bytes[col] = (QChar)'?';

            ui->tHex->setItem(row, 16, new QTableWidgetItem(QString(bytes)));

        } else if (col == 16) {
            // user modified the string data box
            data = ui->tHex->item(row,col)->text();
            bytes = data.data();


            char tmp[4];
            for (int i=0; i<data.size(); i++) {
                if (bytes[i] != '?') {
                    snprintf(tmp, 3, "%.2x", bytes[i]);
                    ui->tHex->setItem(row, i, new QTableWidgetItem(QString::fromUtf8(tmp, 2)));
                }
            }

        }

        mutHex.unlock();
    }
}

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
    // totally connected!!

    disableSettings();
    clearStats();
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

void MainWindow::onEndpointData(char *buff, int sz) {
    ui->bSend->setText("<<< Send <<<");
    putBuffer(buff, sz, false);
    if (ui->chkAutoSend->isChecked())
        emit sigReadyToSend(sz);
}

void MainWindow::onClientData(char *buff, int sz) {
    ui->bSend->setText(">>> Send >>>");
    putBuffer(buff, sz, true);
    if (ui->chkAutoSend->isChecked())
        emit sigReadyToSend(sz);
}

// display and retrieve buffer

void MainWindow::putBuffer(char *buffer, int sz, bool bSend) {
    int row, col, i=0;
    char hex[5];

    //disconnect(ui->tHex, SIGNAL(cellChanged(int,int)));

    mutHex.lock();

    ui->eSize->setText(QString::number(sz));
    ui->eId->setText(QString::number(ui->eId->text().toInt()+1));
    if (bSend) {
        ui->eOut->setText(QString::number(ui->eOut->text().toInt()+1));
    } else {
        ui->eIn->setText(QString::number(ui->eIn->text().toInt()+1));
    }

    // ui->tHex->clear();
    while (ui->tHex->rowCount() > 0) {
        row = ui->tHex->rowCount();
        ui->tHex->removeRow(row-1);
    }

    while (i<sz) {
        int row = ui->tHex->rowCount();
        ui->tHex->insertRow(row);

        QString data;
        for (col=0; col<16 && i+col<sz; col++) {
            snprintf(hex, 3, "%.2x", buffer[i+col]);
            ui->tHex->setItem(row, col, new QTableWidgetItem( QString(hex) ));
            if (buffer[i+col] >= ' ' && buffer[i+col] <= '~')
                data += QString::fromUtf8(&buffer[i+col], 1);
            else
                data += "?";
        }
        ui->tHex->setItem(row, 16,  new QTableWidgetItem( data ));

        i += 16;
    }

    mutHex.unlock();
}

int MainWindow::getBuffer(char *buffer) {
    bool ok;
    int i, sz, col, row, hex;

    sz = ui->eSize->text().toInt(&ok, 10);
    if (!ok || sz <0 || sz>1024) {
        this->box("bad size");
        return 0;
    }

    col = 0;
    row = 0;
    for (i=0; i<sz; i++) {

        hex = ui->tHex->item(row, col)->text().toInt(&ok, 16);
        if (!ok) {
            // should not enter here because the cell update is already validated
            this->box("wrong byte, check  getBuffer()");
            hex = 0xff;
        }

        memset(buffer+i, hex, 1);

        if (col<15) {
            col++;
        } else {
            row++;
            col=0;
        }
    }



    return sz;
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
    int sz;

    sz = getBuffer(proxy->getBufferPtr());
    emit sigReadyToSend(sz);

}

void MainWindow::on_actionQuit_triggered() {
    proxy->closeConnections();
    delete proxy;
    exit(1);
}
