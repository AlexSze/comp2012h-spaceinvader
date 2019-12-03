#include "gamescene.h"

#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include <QTimer>
#include <QImage>
#include <QBrush>

#include "abstractenemy.h"
#include "constants.h"
/* game element classes here */

GameScene::GameScene(QWidget* parent) {
    // allocate scene for game
    scene = new QGraphicsScene();
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    // set window background
    setBackgroundBrush(QBrush(QImage(":/image/background.png")));

    // show the scene
    setScene(scene);
    // hide scrollbars
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // set window size
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    // allocate player of the game
    player = new Player();
    // place the player in the bottom of screen
    player->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT);

    // make it main window of focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // put player in scene
    scene->addItem(player);

    for (int i=0; i<10; ++i) {
        AbstractEnemy* e = new AbstractEnemy(1, 10);
        e->setPos(i*SCREEN_WIDTH/10, 0);
        scene->addItem(e);
    }
    show();
}