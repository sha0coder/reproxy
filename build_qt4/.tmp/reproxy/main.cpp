#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "rsocket.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QIcon icon(":/images/truck.ico");
    a.setWindowIcon(icon);

    MainWindow win;
    win.show();
    return a.exec();
}
