#ifndef TOOLATTACK_H
#define TOOLATTACK_H

#include "abstracttools.h"

class toolattack: public abstracttools{
private:
    int attack_type;
    int damage;

public:
    //constructor
    toolattack(int attact_type, int damage);

    //tool graphic
};

#endif // TOOLATTACK_H
