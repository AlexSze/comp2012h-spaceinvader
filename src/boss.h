#ifndef BOSS_H
#define BOSS_H

#endif // BOSS_H

#include "abstractenemy.h"

class Boss : public abstractEnemy {
public:
    explicit Boss(unsigned int health=5, int speed=10, bool dir=true, QGraphicsItem* parent=nullptr) : abstractEnemy(health, speed, dir, parent) { }
};
