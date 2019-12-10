#ifndef LIVE_H
#define LIVE_H

#include <QGraphicsTextItem>

#include "constants.h"


class life: public QGraphicsTextItem
{
public:
    life(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    void reset();
    int get_life();

private:
    int lifes;
};

#endif // LIVE_H
