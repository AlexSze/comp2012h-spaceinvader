#include "abstracttools.h"

#include <stdlib.h> // to get randomised starting position
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <QTimer>

abstracttools::abstracttools() {
    setPixmap(QPixmap(":/src/images/tool_defense.png"));
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
}

void abstracttools::move()
{
    setPos(x(), y()+10);
}
