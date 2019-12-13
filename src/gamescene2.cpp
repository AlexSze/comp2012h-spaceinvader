#include "gamescene2.h"
#include <QDebug>

gamescene2::gamescene2(QWidget *parent)
{
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background2.png")));

    /*
    //create score
    score->setPos(score->x(), score->y());

    //create life
    lifes->setPos(0, 50);
    */

    screen_construction();

        qDebug() << "new scene done";
    character_construction(2);

        qDebug() << "new scene done";
    show();
        qDebug() << "new scene done";
}

extern GameScene* s;
gamescene2::~gamescene2()
{
    delete player;
    delete scene;
    foreach ( QGraphicsItem* i, items() )
        delete i;
    s = nullptr;
}
