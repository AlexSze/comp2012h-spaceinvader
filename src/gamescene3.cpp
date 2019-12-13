#include "gamescene3.h"

extern GameScene* s;
gamescene3::gamescene3(QWidget *parent)
{
    // delete existing scene if exist
    delete s;
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background3.png")));

    screen_construction();

    character_construction(3);

    show();
}
