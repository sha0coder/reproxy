#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once


#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <thread>

#include "rproxy.h"

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
    void clear();
    void box(QString msg);


public slots:
    void setStatusMessage(QString msg);
    void statConnected();
    void statDisconnected();

private slots:
    void on_bConnect_clicked();
    void on_bSend_clicked();

private:
    bool silent;
    RProxy *proxy;
    bool isReadyForSend;

    void enableSettings();
    void disableSettings();


};

#endif // MAINWINDOW_H
