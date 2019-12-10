#ifndef TOOL_LIFE_H
#define TOOL_LIFE_H

#include "abstracttools.h"
#include "life.h"

extern life* lifes;

class tool_life: public abstracttools
{
public:
    tool_life(QGraphicsItem* parent=nullptr);
    void collide_action();

public slots:
    virtual void move() override;
};

#endif // TOOL_LIFE_H
