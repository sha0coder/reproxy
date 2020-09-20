#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <QCoreApplication>
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <script.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow) {
    //setWindowIcon(QIcon(":/icons/reproxy.png"));
    ui->setupUi(this);
    silent = false;
    //isReadyForSend = false;
    ui->lStatus->setText("Disconnected.");
    saveAll = false;
    hexEventEnabled = true;

    proxy = new Proxy(this);
    script = new Script();
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

    connect(ui->actionSave_Bin, SIGNAL(triggered(bool)), this, SLOT(on_saveBin()));
    connect(ui->actionSave_Hex, SIGNAL(triggered(bool)), this, SLOT(on_saveHex()));
    connect(ui->actionLoad_Bin, SIGNAL(triggered(bool)), this, SLOT(on_loadBin()));
    connect(ui->actionLoad_Hex, SIGNAL(triggered(bool)), this, SLOT(on_loadHex()));
    connect(ui->actionAbout_2, SIGNAL(triggered(bool)), this, SLOT(on_about()));
    connect(ui->actionSave_all, SIGNAL(triggered(bool)), this, SLOT(on_saveAll()));
    connect(ui->actionRadare, SIGNAL(triggered(bool)), this, SLOT(on_radare()));
    connect(ui->actionLoad_script, SIGNAL(triggered(bool)), this, SLOT(on_script()));
    connect(ui->actionScripting, SIGNAL(triggered(bool)), this, SLOT(on_help_scripting()));

    resetHex();

    ui->eId->setDisabled(true);
    ui->eIn->setDisabled(true);
    ui->eOut->setDisabled(true);

    ui->bSend->setEnabled(false);
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
    ui->tHex->setRowCount(0);
    ui->tHex->setHorizontalHeaderLabels(titles);
    for (int i=0; i<16; i++)
        ui->tHex->setColumnWidth(i, 27);
    ui->tHex->setColumnWidth(16, 250);
    ui->eSize->setText("0");
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

    //if (!hexEventEnabled)
    //    return;

    qDebug() << "on_hexChanged triggered" << endl;

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
                    snprintf(tmp, 3, "%.2x", bytes[i].toLatin1());
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
    ui->bConnect->setEnabled(true);
    box("connect the client please");
}

void MainWindow::statLConnected() {
    // totally connected!!

    disableSettings();
    clearStats();
    ui->lStatus->setText("connected!");
    ui->bConnect->setText("Disconnect");
    ui->bConnect->setEnabled(true);
    ui->bSend->setEnabled(false);
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
    box(errmsg);
    ui->bConnect->setEnabled(true);
}

void MainWindow::statConnecting() {
    disableSettings();
    ui->lStatus->setText("Connecting ...");
    ui->bConnect->setEnabled(false);
}

void MainWindow::onEndpointData(char *buff, int sz) {
    // triggered from proxy by sigEndpointData() data from the endpoint
    bool ok;
    int packet_num;

    // execute script
    packet_num = ui->eOut->text().toInt(&ok, 10);
    script->exec(OUT, packet_num, buff, sz);

    // do mutation
    doMutation(buff, sz);

    ui->bSend->setText("<<< Send <<<");
    putBuffer(buff, sz, true);
    if (ui->chkAutoSend->isChecked())
        emit sigReadyToSend(sz);
    else
        ui->bSend->setEnabled(true);

     if (saveAll)
        binarySave(saveAll_folder+"/"+getFilename().toStdString()+".bin", buff, sz);


}

void MainWindow::onClientData(char *buff, int sz) {
    // triggered from proxy by sigClientData() data from the client

    bool ok;
    int packet_num;

    // execute script
    packet_num = ui->eIn->text().toInt(&ok, 10);
    script->exec(IN, packet_num, buff, sz);

    // do mutation
    doMutation(buff, sz);

    ui->bSend->setText(">>> Send >>>");
    putBuffer(buff, sz, false);
    if (ui->chkAutoSend->isChecked())
        emit sigReadyToSend(sz);
    else
        ui->bSend->setEnabled(true);

    if (saveAll)
        binarySave(saveAll_folder+"/"+getFilename().toStdString()+".bin", buff, sz);
}

// display and retrieve buffer

void MainWindow::putBuffer(char *buffer, int sz, bool bSend) {
    int row, col, i=0;
    char hex[5];

    hexEventEnabled = false;

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
            snprintf(hex, 3, "%.2x", buffer[i+col]); // byte2hex
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
    hexEventEnabled = false;
}

int MainWindow::getBuffer(char *buffer) {
    bool ok;
    int i, sz, tblSZ, col, row, hex;

    tblSZ = ui->tHex->columnCount()*ui->tHex->rowCount();

    sz = ui->eSize->text().toInt(&ok, 10);
    if (!ok || sz <0 || sz>1024 || sz>tblSZ) {
        this->box("bad size");
        return 0;
    }

    memset(buffer, 0, 1024);

    qDebug() << "tHex size "  << tblSZ << "box size" << sz << endl;

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

void MainWindow::binarySave(std::string filename, char *buff, int sz) {
    std::ofstream ofs(filename);
    if (!ofs) {
        box("cant save the data");
        return;
    }
    ofs.write(buff, sz);
    ofs.close();
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
        //ui->bSend->setEnabled(false);
        //ui->chkAutoSend->setChecked(true);
        //proxy->closeConnections();
    }
}

void MainWindow::on_bSend_clicked() {
    int sz;

    ui->bSend->setEnabled(false);
    sz = getBuffer(proxy->getBufferPtr());
    emit sigReadyToSend(sz);
    ui->tHex->clear();
    resetHex();
}

//  MENU

void MainWindow::on_actionQuit_triggered() {
    proxy->closeConnections();
    delete proxy;
    exit(1);
}

QString MainWindow::getFilename() {
    QString filename = ui->eRHost->text()+"_";

    if (ui->bSend->text() == "<<< Send <<<") {
        filename += "in_";
        filename += ui->eIn->text();
    } else {
        filename += "out_";
        filename += ui->eOut->text();
    }

    return filename;    // do mutation
}

void MainWindow::on_saveBin() {
    char buff[1024];
    int sz = getBuffer(buff);
    std::string filename;

    filename = QFileDialog::getSaveFileName(this,
                                            tr("save binary"),getFilename()+".bin",
                                            tr("binary file (*.bin)")).toStdString();

    if (filename.size()==0)
        return;

    std::ofstream ofs(filename);
    if (!ofs) {
        box("cant save the data");
        return;
    }
    ofs.write(buff, sz);
    ofs.close();
}

void MainWindow::on_saveHex() {
    char buff[1024];
    int sz = getBuffer(buff);
    std::string filename;

    filename = QFileDialog::getSaveFileName(this,
                                            tr("save hexa"),getFilename()+".txt",
                                            tr("hexa text file (*.txt)")).toStdString();

    if (filename.size()==0)
        return;

    std::ofstream ofs(filename);
    if (!ofs) {
        box("cant save the data");
        return;
    }

    int col = 0;
    char hex[4];
    for (int i=0; i<sz; i++) {
        snprintf(hex, 3, "%.2x", buff[i]);
        ofs << hex << " ";
        if (col++ >= 0xf) {
            ofs << endl;
            col = 0;
        }
    }
    ofs.close();
}

void MainWindow::on_loadBin() {
    char buff[1024];
    int sz;
    std::string filename;


    filename = QFileDialog::getOpenFileName(this,
                                            tr("load binary file"),
                                            "",
                                            tr("binary file (*.bin)")).toStdString();

    std::ifstream ifs(filename);
    if (!ifs) {
        box("cant load file");
        return;
    }
    sz = ifs.readsome(buff, 1024);
    ifs.close();

    putBuffer(buff, sz, true);
}

void MainWindow::on_loadHex() {
    std::string filename;
    int pos = 0;
    int num;
    char buff[1024];
    char line[255];
    QString qsline;
    bool ok;


    filename = QFileDialog::getOpenFileName(this,
                                            tr("load hex file"),
                                            "",
                                            tr("hex file (*.txt)")).toStdString();
    std::ifstream ifs(filename);
    if (!ifs) {
        box("cant load file");
        return;
    }

    while(ifs.getline(line, 254)) {

        qsline = QString::fromStdString(std::string(line));

        auto spl = qsline.split(" ");
        for (int i=0; i<spl.length(); i++) {
            if (spl[i] == "")
                break;

            num = spl[i].toInt(&ok, 16);
            if (!ok)
                num = 0x00;

            buff[pos++] = (char)(num & 0x000000ff);
        }
    }
    ifs.close();
    putBuffer(buff, pos, true);
}

void MainWindow::on_saveAll() {

    if (saveAll) {
        box("save all disabled");
        saveAll = false;
        return;
    }

    saveAll = true;
    saveAll_folder = QFileDialog::getExistingDirectory(this,
                                               tr("select folder"),
                                               "").toStdString();
    box(QString::fromStdString(saveAll_folder));
}

void MainWindow::on_about() {
    box("reproxy - the multiprotocol reverse proxy\nby @sha0coder");
}

void MainWindow::on_radare() {
    QString filename;
    QProcess process;
    char *buffer;
    int sz;

    // save tmp bin file
    buffer = (char *)malloc(1024);
    sz = getBuffer(buffer);
    filename = "/tmp/"+getFilename()+".bin";
    binarySave(filename.toStdString(), buffer, sz);
    free(buffer);


    QProcess::execute("x-terminal-emulator -e r2 "+filename);
}

void MainWindow::on_eSize_editingFinished() {
    // size validation
    int sz, tblSZ;
    bool ok;

    tblSZ = ui->tHex->columnCount()*ui->tHex->rowCount();

    sz = ui->eSize->text().toInt(&ok, 10);
    if (!ok || sz <0 || sz>1024 || sz>tblSZ) {
        box("incorrect size");
    }
}

void MainWindow::on_eMutation_editingFinished() {
    // mutation validation
    int mutation;
    bool ok;

    mutation = ui->eMutation->text().toInt(&ok,10);
    if (!ok || mutation < 0 || mutation > 100) {
        box("incorrect mutation %");
    }
}

void MainWindow::on_script() {
    std::string filename;

    filename = QFileDialog::getOpenFileName(this,       tr("load script .proxy"),
                                                        "",
                                                        tr("hex file (*.proxy)")).toStdString();

    if (script->load(filename)) {
        box("script loaded");
    } else {
        box(QString::fromStdString(script->error));
    }
}

void MainWindow::on_help_scripting() {
    box("parameters: [IN|OUT] [packet num] [position] [replacement in hex]\nexample: IN 3 20 3F\nthis means in the third input packet from endpoint, will replace the position 20 with the byte 3F");
}

void MainWindow::doMutation(char *buffer, int sz) {
    int bytes2mutate;
    int mutation;
    bool ok;

    mutation = ui->eMutation->text().toInt(&ok, 10);
    if (!ok || mutation < 0 || mutation > 100) {
        box("incorrect mutation %");
        return;
    }

    srand(time(NULL));

    bytes2mutate = mutation*sz/100;
    for (int i=0; i<bytes2mutate; i++) {
        int iWhere = rand()%sz;
        int iWhat = rand()%0xff;
        //qDebug() << "where " << iWhere << "what " << iWhat << " " << (char)iWhat << " " << (unsigned char)iWhat << endl;
        buffer[iWhere] = (char)iWhat;
    }

}

void MainWindow::on_tHex_cellChanged(int row, int column) {
    on_hexChanged(row, column);
}
