#include "proxy.h"


using namespace std;

proxy::proxy(MainWindow *mainWindow) {
    this->mainWindow = mainWindow;
    this->acceptLock = false;
    this->isConnected = false;


    uniform_int_distribution<int> dist(0, 6);
    cout << dist(r) << endl;
}
