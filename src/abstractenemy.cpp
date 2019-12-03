/* abstractEnemy.cpp */



#include "abstractenemy.h"
#include "laser.h"
#include "constants.h"
#include <stdlib.h> // to get randomised starting position
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QTimer>
//#include <main.h>

// constructor
// constructor
abstractEnemy::abstractEnemy(unsigned int health, int speed, bool dir, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent),
    abstractobjects(health, LASER, NUL, speed),
    horizontal_dir(dir) {
        // set the character at a random position at the top of the screen
        //int xpos = rand()%600;
        //setPos(xpos, 0);

        // draw the character
        setPixmap(QPixmap(":/src/images/base_enemy.png"));
        setTransformOriginPoint(50,50);

        // create a timer
        // since timer has this object as parent, it will be
        // killed automatically when this object is killed

        // create timer for movement
        QTimer* t = new QTimer(this);
        // connect a timer to call move()
        connect(t, SIGNAL(timeout()), this, SLOT(move()));
        // start a timer for 10fps of motion
        t->start(100);

        // create timer for shooting
        t = new QTimer(this);
        // connect a timer to call move()
        connect(t, SIGNAL(timeout()), this, SLOT(attack()));
        // start a timer for 10fps of motion
        t->start((rand()%20) * 300);
}

// copy constructor
/*
abstractEnemy::abstractEnemy(abstractEnemy& a)
    : weaponType(a.weaponType),
    defenseType(a.defenseType),
    health(a.health) {}
    */

// create laser beam or minions
void abstractEnemy::attack() {
    // create laser beam
    Laser* l = new Laser(10, 0);
    l->setPos(this->x() + BASE_ENEMY_WIDTH/2, this->y() + BASE_ENEMY_HEIGHT);
    scene()->addItem(l);
    // no storage required, laser beam will be automatically deleted when
    // 1. beam hits somebody
    // 2. beam goes off screen
    // 3. parent (this object) is deleted
}

// move character
void abstractEnemy::move() {
    // move character
    if (
            (horizontal_dir &&
            x() + this->speed > SCREEN_WIDTH)
            ||
            (!horizontal_dir &&
            x() - this->speed <= 0)
            ) {
        // swap direction when reached an edge
        horizontal_dir = !horizontal_dir;
        // move down
        setPos(x(), y() + BASE_ENEMY_HEIGHT);
    }
    else {
        // moove horizontally
        setPos(x() + this->speed * (horizontal_dir? 1: -1), y());
    }

    // check out of frame
    if (pos().y() > SCREEN_HEIGHT){
        // remove from scene and delete of out of frame
        scene()->removeItem(this);
        delete this;
    }
}
void abstractEnemy::destruct() {
    if (--health == 0)
        delete this;
}

abstractEnemy::~abstractEnemy() {
    // prepare removal from scene
    QGraphicsItem::prepareGeometryChange();
}
