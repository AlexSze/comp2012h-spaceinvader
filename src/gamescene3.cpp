#include "gamescene3.h"

gamescene3::gamescene3(QWidget *parent)
{
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background3.png")));

    screen_construction();

    character_construction(3);

    show();
}

extern GameScene* s;
gamescene3::~gamescene3()
{
    delete health;
    delete player;
    delete scene;
    foreach ( QGraphicsItem* i, items() )
        delete i;
    e.clear();
    boss.clear();
    tt.clear();
    s = nullptr;
}
