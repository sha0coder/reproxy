#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once


#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <thread>

#include "proxy.h"
#include "script.h"

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
    void onEndpointData(char *buff, int sz);        // data comming from server
    void onClientData(char *buff, int sz);          // data comming from client
    void on_hexChanged(int row, int col);

private slots:
    void on_bConnect_clicked();
    void on_bSend_clicked();
    void on_actionQuit_triggered();                 // Menu > file > quit
    void on_saveHex();
    void on_saveBin();
    void on_loadHex();
    void on_loadBin();
    void on_saveAll();
    void on_about();
    void on_radare();
    void on_script();
    void on_eSize_editingFinished();
    void on_eMutation_editingFinished();            // unused event
    void on_help_scripting();

    void on_tHex_cellChanged(int row, int column);

private:
    bool hexEventEnabled;
    bool saveAll;
    std::string saveAll_folder;
    bool silent;
    Proxy *proxy;
    Script *script;
    bool isReadyForSend;
    QMutex mutHex;



    void enableSettings();
    void disableSettings();
    QString getFilename();

    void putBuffer(char *buffer, int sz, bool bSend);   // this reads buffer pointer and writes the hex bytes on the screen
    int getBuffer(char *buffer);                        // this gets the hex from the screen and write them on the buffer pointer (sz: 1024)
    void binarySave(std::string filename, char *buffer, int sz);
    void doMutation(char *buffer, int sz);

    void resetHex();

};

#endif // MAINWINDOW_H
