#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once


#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <thread>

#include "proxy.h"

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    void clearStats();
    void box(QString msg);

signals:
    void sigReadyToSend(int sz);

public slots:
    void setStatusMessage(QString msg);
    void statConnecting();
    void statRConnected();
    void statLConnected();
    void statDisconnected();
    void statCantConnect(QString errmsg);
    void onEndpointData(char *buff, int sz);
    void onClientData(char *buff, int sz);

private slots:
    void on_bConnect_clicked();
    void on_bSend_clicked();

private:
    bool silent;
    Proxy *proxy;
    bool isReadyForSend;

    void enableSettings();
    void disableSettings();
    void putBuffer(char *buffer, int sz, bool bSend);
    int getBuffer(char *buffer);
    void resetHex();

};

#endif // MAINWINDOW_H
