#include "proxy.h"


using namespace std;

Proxy::Proxy(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
    this->acceptLock = false;
    this->is_connected = false;


    uniform_int_distribution<int> dist(0, 6);
    cout << "random num: " << dist(r) << endl;
}

bool Proxy::isConnected() {
    return this->is_connected;
}
