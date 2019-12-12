#include "gamesceneinfinity.h"

GameSceneInfinity::GameSceneInfinity(QWidget *parent)
{
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background.png")));

    reset_level();

    screen_construction();

    character_construction();

    show();
}

void GameSceneInfinity::regenerate_enemy()
{
    if (this->enemyCount() <= 8) {
        next_level();
        character_construction(level);
    }
}

void GameSceneInfinity::next_level()
{
    ++level;
}

void GameSceneInfinity::reset_level()
{
    level = 1;
}
