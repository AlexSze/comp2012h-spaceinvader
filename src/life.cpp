#include "life.h"
#include <QFont>

life::life(QGraphicsItem *parent)
{
    // setup life object
    reset();
}

void life::decrease()
{
    if (lifes > 0)
        lifes--;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(lifes));
}

void life::increase()
{
    lifes++;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(lifes));
}

void life::reset()
{
    // set initial life
    lifes = PLAYER_LIFE;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(lifes));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int life::get_life()
{
    return lifes;
}
