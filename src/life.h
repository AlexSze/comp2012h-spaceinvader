#ifndef LIVE_H
#define LIVE_H

#include <QGraphicsTextItem>

#include "constants.h"


class life: public QGraphicsTextItem
{
public:
    life(QGraphicsItem * parent=0);
    ~life();
    void decrease();
    void increase();
    void reset();
    int get_life();

private:
    unsigned int life_count;
};

#endif // LIVE_H
