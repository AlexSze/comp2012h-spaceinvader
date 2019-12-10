#ifndef GAMESCENE2_H
#define GAMESCENE2_H

#include "gamescene.h"

class gamescene2: public GameScene
{
public:
    explicit gamescene2(): GameScene() {}
    virtual void set_bg() override;
};

#endif // GAMESCENE2_H
