#include "script.h"
#include <QStringList>

class Script {

};

Script::Script() {
    error = "";
    rules.clear();
}

/*
 *   Direction PacketNum Position NewValue
 *   IN 3 20 F3
 */

bool Script::load(string filename) {
    char line[255];
    bool ok;
    ifstream ifs(filename);
    int i = 0;

    if (!ifs) {
        error = "script file not found";
        return false;
    }

    while (ifs.getline(line, 254)) {
        i++;
        auto qsline = QString(line); //::fromStdString(string(line));
        auto spl = qsline.split(" ");
        if (spl.size() < 4) {
            ifs.close();
            error = "syntax error, num of parameters incorrect.";
            return false;
        }
        if (spl[0][0] != '#' && (spl[0] == "IN" || spl[0] == "OUT")) {

            ScriptRule *rule = new ScriptRule();

            if (spl[0] == "IN")
                rule->direction = IN;
            if (spl[0] == "OUT")
                rule->direction = OUT;

            rule->num_packet = spl[1].toInt(&ok, 10);
            if (!ok) {
                ifs.close();
                error = "sytax error, incorrect patcket number.";
                return false;
            }

            rule->position = spl[2].toInt(&ok, 10);
            if (!ok) {
                ifs.close();
                error = "syntax error, incorrect position number.";
                return false;
            }

            rule->replacement = (spl[3].toInt(&ok, 16) & 0x000000ff);
            if (!ok) {
                ifs.close();
                error = "syntax error, incorrect replacement hexa.";
                return false;
            }

            this->rules.push_back(rule);
        }
    }


    ifs.close();

    cout << rules.size() << " rules loaded " << endl;

    return true;
}



void Script::exec(Direction dir, int packet_num, char *buffer, int sz) {
    for (auto rule : rules) {
        if (rule->direction == dir && rule->num_packet == packet_num+1) {
            cout << "rule match !!!!!!!!" << endl;
            buffer[rule->position] = rule->replacement;
        }
    }
}


