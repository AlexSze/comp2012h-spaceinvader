#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QGraphicsTextItem>

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

    //create life
    lifes = new life();
    lifes->setPos(lifes->x(), lifes->y() + 50);
    scene->addItem(lifes);


    for (unsigned int i=0; i<8; ++i) {
        abstractEnemy* e = new abstractEnemy(2, 10, true);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT/2);
        scene->addItem(e);

        e = new abstractEnemy(1, 10, false);
        e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT*3/2);
        scene->addItem(e);
    }

    abstractEnemy* boss= new abstractEnemy(5, 4, true);
    boss->setPos(SCREEN_WIDTH/2, BASE_ENEMY_HEIGHT/2);
    scene->addItem(boss);

    show();
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
