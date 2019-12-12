#include "gamescene2.h"
#include <QDebug>

gamescene2::gamescene2(QWidget *parent)
{
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background2.png")));

    screen_construction();

    character_construction(2);

    show();
}

extern GameScene* s;
gamescene2::~gamescene2()
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
