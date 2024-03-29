#include "abstracttools.h"

#include <stdlib.h> // to get randomised starting position
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QTimer>

#include "player.h"
#include "constants.h"

abstracttools::abstracttools(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent) {}

void abstracttools::move_timer()
{
    // create timer for movement
    QTimer* t = new QTimer(this);
    // connect a timer to call move()
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    // start a timer for 10fps of motion
    t->start(100);
}

void abstracttools::move()
{
    // move vertically down
    setPos(x(), y()+ABSTRACT_TOOL_SPEED);
}
