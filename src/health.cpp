#include "health.h"
#include "constants.h"
#include "score.h"

#include <QFont>

extern Score* score;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = PLAYER_HEALTH;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    // decrease score
    score->increase(PENALTY_GETTING_HIT);
}

void Health::increase()
{
    health++;

    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::reset()
{
    health = PLAYER_HEALTH;

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int Health::get_health()
{
    return health;
}
