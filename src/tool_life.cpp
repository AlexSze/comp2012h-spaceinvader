#include "tool_life.h"

tool_life::tool_life(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/src/images/tool_defense.png"));
    setTransformOriginPoint(50,50);

    move_timer();
}

void tool_life::collide_action()
{
    QList<QGraphicsItem *> colliding = collidingItems();
    int size = colliding.size();

    for (int i=0; i<size; ++i) {
       if (typeid(*(colliding[i])) == typeid(Player)) {
          lifes->increase();

          delete this;
          return;
        }
    }
}

void tool_life::move()
{
    setPos(x(), y()+10);

    // check out of bounce
    if (y() > SCREEN_HEIGHT) {
        delete this;
        return;
    }

    collide_action();
}
