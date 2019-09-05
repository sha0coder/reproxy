#include "mainwindow.h"
#include "proxy.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Poxy *proxy = new Proxy();
    MainWindow w;
    w.show();

    return a.exec();
}
