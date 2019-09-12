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
    void setProxy(Proxy *proxy);
    ~MainWindow();
    Ui::MainWindow *ui;
    void clear();
    void box(QString msg);


public slots:
    void setStatus(QString &msg);

private slots:
    void on_bConnect_clicked();
    void on_bSend_clicked();

private:
    bool silent;
    Proxy *proxy;
    bool isReadyForSend;

    void enableSettings();
    void disableSettings();


};

#endif // MAINWINDOW_H
