#include "life.h"
#include <QFont>

life::life(QGraphicsItem *parent)
{
    // setup life object
    reset();
}

extern life* lifes;
life::~life() {
    lifes = nullptr;
}

void life::decrease()
{
    if (life_count > 0)
        life_count--;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(life_count));
}

void life::increase()
{
    life_count++;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(life_count));
}

void life::reset()
{
    // set initial life
    life_count = PLAYER_LIFE;
    // draw the text
    setPlainText(QString("Live(s): ") + QString::number(life_count));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

int life::get_life()
{
    return life_count;
}
