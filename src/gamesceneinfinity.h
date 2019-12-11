#ifndef GAMESCENEINFINITY_H
#define GAMESCENEINFINITY_H

#include "gamescene.h"

class GameSceneInfinity : public GameScene
{
public:
    GameSceneInfinity(QWidget * = nullptr);
    void next_level();
    void reset_level();

public slots:
    void regenerate_enemy();

private:
    unsigned int level{1};
};

#endif // GAMESCENEINFINITY_H
