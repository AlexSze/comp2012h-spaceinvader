#include "gamescene2.h"

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
