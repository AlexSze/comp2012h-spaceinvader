#include <QGraphicsTextItem>
#include <QMediaPlayer>
#include <QFont>
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsView>

#include "gamescene.h"
#include "abstractenemy.h"
#include "constants.h"
#include "boss.h"
#include "tool_life.h"
#include "tool_atk.h"
#include "enemy.h"

/* game element classes here */
GameScene::GameScene(QWidget* parent) {
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background.png")));

    //create score
    score->setPos(score->x(), score->y());

    //create life
    lifes->setPos(0, 50);

    screen_construction();

    character_construction();

    show();
}

GameScene::~GameScene()
{
    delete health;
    delete player;
    e.clear();
}

void GameScene::screen_construction()
{
    // show the scene
    setScene(scene);
    // hide scrollbars
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // set window size
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    scene->addItem(score);
    scene->addItem(lifes);

    //create health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);
}

void GameScene::character_construction()
{
    // setup player
    newPlayer();


    for (unsigned int i=0; i<8; ++i) {
        e.push_back(new Enemy(2, 10, true));
        e.back()->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT/2);
        scene->addItem(e.back());

        e.push_back(new Enemy(1, 10, false));
        e.back()->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT*3/2);
        scene->addItem(e.back());
    }

    boss= new Boss(5, 4, true);
    boss->setPos(SCREEN_WIDTH/2, BASE_ENEMY_HEIGHT/2);
    scene->addItem(boss);

    int random= rand()% SCREEN_WIDTH;
    tt.push_back(new tool_life());
    tt.back()->setPos(random, 0);
    scene->addItem(tt.back());

    int random1= rand()% SCREEN_WIDTH;
    tt.push_back(new tool_atk());
    tt.back()->setPos(random1, 0);
    scene->addItem(tt.back());


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

bool GameScene::enemyExist() {
    QList<QGraphicsItem *> objectList = items();
    int size = objectList.size();
    for (int i = 0; i < size; ++i){
        // check enemy types
        if (
                typeid(*objectList[i]) == typeid(Boss) ||
                typeid(*objectList[i]) == typeid(Enemy) ||
                typeid(*objectList[i]) == typeid(abstractEnemy)
                ){
            return true;
        }
    }
    // if no more enemies exist, return false and go on to win screen
    return false;
}
