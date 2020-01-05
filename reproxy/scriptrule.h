#ifndef SCRIPTRULE_H
#define SCRIPTRULE_H

enum Direction {
    IN,
    OUT
};

class ScriptRule {
public:
    Direction direction;
    int num_packet;
    int position;
    char replacement;

    ScriptRule();
};

#endif // SCRIPTRULE_H
