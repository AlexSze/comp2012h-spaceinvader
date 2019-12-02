/* AbstractEnemy.h */

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class AbstractEnemy : public QObject, public QGraphicsPixmapItem{
    protected:
        unsigned int health{1};
        const int speed;
    private:
        // true = move right (+ve)
        // false = move left (-ve)
        bool horizontal_dir{true};
    public:

        // constructor
        AbstractEnemy(unsigned int health, int speed, QGraphicsItem* parent=nullptr);

        // copy constructor
        //AbstractEnemy(AbstractEnemy&);

        unsigned int get_health() const { return this->health; }
        // dying is handled by the bullet instead
        // die();
    public slots:
        void move();
        void shoot();
};

#endif // AbstractEnemy_H


