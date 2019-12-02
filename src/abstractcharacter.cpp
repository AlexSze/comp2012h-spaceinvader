/* AbstractCharacter.cpp */

#include "abstractcharacter.h"
#include <stdlib.h> // to get randomised starting position
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QTimer>
//#include <main.h>

// constructor
AbstractCharacter::AbstractCharacter(unsigned int health, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent),
    health(health) {
        // set the character at a random position at the top of the screen
        int xpos = rand()%600;
        setPos(xpos, 0);

        // draw the character
        setPixmap(QPixmap(":/images/character.png"))
        setTransformOriginPoint(50,50);

    // create a timer
    // since timer has this object as parent, it will be
    // killed automatically when this object is killed
    QTimer * t = new QTimer(this);
    // connect a timer to call move()
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    // start a timer for 25fps of motion
    t->start(40);
}

// copy constructor
/*
AbstractCharacter::AbstractCharacter(AbstractCharacter& a)
    : weaponType(a.weaponType),
    defenseType(a.defenseType),
    health(a.health) {}
    */

// create laser beam or minions
void AbstractCharacter::attack() {}

// get hit by a laser beam or minion; returns living or not
bool AbstractCharacter::hit() {
    return (--health == 0);
}
