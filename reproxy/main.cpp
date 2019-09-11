#include "mainwindow.h"
#include "proxy.h"
#include <QApplication>
#include <iostream>

#include "test.h"


using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow win;
    Proxy *proxy = new Proxy(win.ui);
    win.setProxy(proxy);

    //QObject::connect(proxy, SIGNAL(onSignal()), &win, SLOT(testSignal()));


    Test *test = new Test();
    test->start();


    win.show();
    return a.exec();
}
