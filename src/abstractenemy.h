/* AbstractEnemy.h */

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "abstractobjects.h"

class abstractEnemy : public abstractobjects, public QObject, public QGraphicsPixmapItem{
    private:
        // true = move right (+ve)
        // false = move left (-ve)
        bool horizontal_dir{true};

        int value{0};

    public:

        // constructor
        abstractEnemy(unsigned int health=1, int speed=1, QGraphicsItem* parent=nullptr);

        unsigned int get_health() const;
        // dying is handled by the bullet instead

    public slots:
        void move();
        void attack();
};

#endif // AbstractEnemy_H


