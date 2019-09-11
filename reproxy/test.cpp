#include "test.h"

#include <QObject>
#include <iostream>

using namespace std;

Test::Test() {

}

void Test::run() {
    cout << "running" << endl;
    for (int i=0; i<10000; i++) {
        cout << i << endl;
    }
    cout << "end." << endl;
}
