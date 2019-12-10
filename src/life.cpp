#include "life.h"
#include <QFont>

life::life(QGraphicsItem *parent)
{
    // initialize the score to 0
    lifes = playerlife;

    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(lifes)); // Life=2
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void life::decrease()
{
    lifes--;

    setPlainText(QString("Live(s): ") + QString::number(lifes));
}

void life::increase()
{
    lifes++;
    setPlainText(QString("Live(s): ") + QString::number(lifes));
}

void life::reset()
{
    lifes=playerlife;

    setPlainText(QString("Live(s): ") + QString::number(lifes));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int life::get_life()
{
    return lifes;
}
