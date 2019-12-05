#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include <QTimer>
#include <QImage>
#include <QBrush>

#include "gamescene.h"
#include "abstractenemy.h"
#include "constants.h"

/* game element classes here */
GameScene::GameScene(QWidget* parent) {
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    // set window background
    setBackgroundBrush(QBrush(QImage(":/src/images/background.png")));

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

    //create score
    score = new Score();
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);


    for (unsigned int i=0; i<8; ++i) {
        abstractEnemy* e = new abstractEnemy(2, 10, true);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT/2);
        scene->addItem(e);

        e = new abstractEnemy(1, 10, false);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT*3/2);
        scene->addItem(e);
    }
    show();
}
