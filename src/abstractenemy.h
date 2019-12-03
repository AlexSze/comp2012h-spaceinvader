/* AbstractEnemy.h */

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "abstractobjects.h"

class abstractEnemy : public abstractobjects, public QGraphicsPixmapItem{
    Q_OBJECT
    private:
        // true = move right (+ve)
        // false = move left (-ve)
        bool horizontal_dir{true};

        int value{0};

    public:

        // constructor
        abstractEnemy(unsigned int health=1, int speed=10, bool dir=true, QGraphicsItem* parent=nullptr);
        ~abstractEnemy();

        unsigned int get_health() const;
        // dying is handled by the bullet instead

        void hurt();

    public slots:
        void move();
        void attack();
};

#endif // AbstractEnemy_H


