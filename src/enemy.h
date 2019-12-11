#ifndef ENEMY_H
#define ENEMY_H

#include "abstractenemy.h"

class Enemy : public abstractEnemy
{
public:
    explicit Enemy(unsigned int health=1, int speed=5, bool dir=true, QGraphicsItem* parent=nullptr) : abstractEnemy(health, speed, dir, parent) { }
};

#endif // ENEMY_H
