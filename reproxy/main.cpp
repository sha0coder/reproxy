#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "rsocket.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow win;

    //QObject::connect(proxy, SIGNAL(onSignal()), &win, SLOT(testSignal()));

/*
    Socket *sock = new Socket(true, 6);
    sock->dial("google.com", 80);
    if (sock->ok()) {
        cout << "all ok" << endl;
        sock->setTimeout(10);

        char buff[1024];
        strcpy(buff, "GET / HTTP/1.0\n\n");
        sock->push(buff, 1024);
        int r = sock->pop(buff, 1024);
        if (sock->ok()) {
            if (sock->timeout()) {
                cout << "timmed out" << endl;
            } else {
                cout << r << " bytes read." << endl;
                cout << buff << endl;
            }
        } else {
            cout << sock->getError() << endl;
        }

    } else
        cout << sock->getError() << endl;
    delete sock;
*/

    win.show();
    return a.exec();
}
