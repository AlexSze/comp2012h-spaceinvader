#include "health.h"
#include "constants.h"

#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = playerhealth;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

void Health::increase()
{
    health++;
}

void Health::reset()
{
    health = playerhealth;
}

int Health::get_health()
{
    return health;
}
