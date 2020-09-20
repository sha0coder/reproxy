#ifndef SCRIPT_H
#define SCRIPT_H

#include "scriptrule.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <QObject>

using namespace std;

class Script {
private:
    vector<ScriptRule *> rules;

public:
    string error;
    Script();
    bool load(string filename);
    void exec(Direction dir, int packet_num, char *buffer, int sz);

};

#endif // SCRIPT_H


