#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QDebug>

#include "gamescene.h"
#include "abstractenemy.h"
#include "constants.h"
#include "boss.h"

/* game element classes here */
GameScene::GameScene(QWidget* parent) {
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    set_bg();

    // show the scene
    setScene(scene);
    // hide scrollbars
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // set window size
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    //create score
    score = new Score();
    score->setPos(score->x(), score->y());
    scene->addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    //create life
    lifes = new life();
    lifes->setPos(lifes->x(), lifes->y() + 50);
    scene->addItem(lifes);

    // setup player
    newPlayer();


    for (unsigned int i=0; i<8; ++i) {
        abstractEnemy* e = new abstractEnemy(2, 10, true);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT/2);
        scene->addItem(e);

        e = new abstractEnemy(1, 10, false);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT*3/2);
        scene->addItem(e);
    }

    boss= new Boss(5, 4, true);
    boss->setPos(SCREEN_WIDTH/2, BASE_ENEMY_HEIGHT/2);
    scene->addItem(boss);

    show();
}

void GameScene::set_bg()
{
    // set window background
    setBackgroundBrush(QBrush(QImage(":/src/images/background.png")));
}

/*void GameScene::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void GameScene::mainwindow()
{
    drawPanel(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Qt::lightGray, 1);

    Button* start = new Button(QString("Start"));
    start->setPos(410,300);
    scene->addItem(start);
    connect(start, SIGNAL(clicked()), this, SLOT(startgame()));

}*/

void GameScene::newPlayer() {

    // remove existing player
    delete player;

    // spawn a new player
    player = new Player();

    // place the player in the bottom of screen
    player->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT);

    // make it main window focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // make it main window of focus
    player->setFocus();

    // put player in scene
    scene->addItem(player);

    health->reset();
}
