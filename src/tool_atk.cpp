#include "tool_atk.h"

tool_atk::tool_atk(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/src/images/tool_weapon.png"));
    setTransformOriginPoint(50,50);

    move_timer();
}

void tool_atk::collide_action()
{
    QList<QGraphicsItem *> colliding = collidingItems();
    int size = colliding.size();

    for (int i=0; i<size; ++i) {
       if (typeid(*(colliding[i])) == typeid(Player)) {
          for (int i=0; i<5; i++)
           s->player->increase_atk();

          delete this;
          return;
        }
    }
}

void tool_atk::move()
{
    setPos(x(), y()+10);

    collide_action();
}
