#ifndef TOOL_ATK_H
#define TOOL_ATK_H

#include "gamescene.h"
#include "abstracttools.h"

extern GameScene* s;

class tool_atk: public abstracttools
{
public:
     tool_atk(QGraphicsItem* parent=nullptr);
     void collide_action();

public slots:
     virtual void move() override;

};

#endif // TOOL_ATK_H
