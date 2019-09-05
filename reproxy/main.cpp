#include "mainwindow.h"
#include "proxy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    MainWindow w;
    Proxy *proxy = new Proxy(&w);

    w.show();

    return a.exec();
}
