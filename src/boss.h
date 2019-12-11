#ifndef BOSS_H
#define BOSS_H

#endif // BOSS_H

#include "abstractenemy.h"
#include "constants.h"

class Boss : public abstractEnemy {
public:
    explicit Boss(unsigned int health=5, int speed=10, bool dir=true, QGraphicsItem* parent=nullptr) : abstractEnemy(health, speed, dir, parent) {
        // draw the character
        // switch the image to boss
        setPixmap(QPixmap(":/src/images/boss.png"));
        setTransformOriginPoint(BASE_ENEMY_WIDTH * 7 / 5, ADVANCED_ENEMY_WIDTH * 7 / 5);
    }
};
