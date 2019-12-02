#include "laser.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
//#include "Player.h"
//#include "Game.h"

#include <QDebug>
Laser::Laser(int speed, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), speed(speed) {
    // set laser graphic
    setPixmap(QPixmap(":/images/laser.png"));
    // draw the rectangle in place for a laser
    //setRect(0,0,5,40);

    // create a timer
    // since timer has this object as parent, it will be
    // killed automatically when this object is killed
    QTimer * t = new QTimer(this);
    // connect a timer to call move()
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    // start a timer for 25fps of motion
    t->start(40);
}

void Laser::move(){
    // check if laser collided with anything
    QList<QGraphicsItem *> colliding = collidingItems();
    int size = colliding.size();
    for (int i=0; i<size; ++i) {
        // check colliding type
        if (typeid(*(colliding[i])) == typeid(Enemy)) {
            // remove both laser and enemy type
            scene()->removeItem(this);
            scene()->removeItem(colliding[i]);
            // delete both
            delete colliding[i];
            delete this;
            return;
        }
        else if (typeid(*(colliding[i])) == typeid(Hero)) {
            // hero is defeated
            // remove both laser and hero
            scene()->removeItem(this);
            scene()->removeItem(colliding[i]);
            // delete laser and call end game
            delete this;
            // lose_a_life();
            return;
        }
    }

    // move laser
    setPos(x(), y() + this->speed);
    // check out of frame
    if (pos().y() + rect().height() < 0){
        // remove from scene and delete of out of frame
        scene()->removeItem(this);
        delete this;
    }
}
