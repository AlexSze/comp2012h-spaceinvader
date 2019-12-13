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
    // delete existing scene if exist
    delete s;
    // allocate scene for game
    scene = new QGraphicsScene(parent);
    // set window size and coordinate
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    setBackgroundBrush(QBrush(QImage(":/src/images/background.png")));

    //create score
    score->setPos(score->x(), score->y());
    score->reset();

    //create life
    lifes->setPos(0, 50);
    lifes->reset();

    screen_construction();

    character_construction();

    show();
}

GameScene::~GameScene()
{
    delete health;
    delete player;
    delete scene;
    foreach ( QGraphicsItem* i, items() )
        delete i;
    s = nullptr;
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

void GameScene::character_construction(unsigned int level)
{
    // setup player
    newPlayer();

    // designing each level with increased difficulty, with an increased amount of enemies
    for (unsigned int i = 0; i < 8; ++i) {
        for (unsigned int j = level + 1; j > 0; --j) {
            Enemy* e = new Enemy(j, 10, (j + 1) % 2, dynamic_cast<QGraphicsItem*>(this));
            e->setPos(i*SCREEN_WIDTH/8, BASE_ENEMY_HEIGHT*(2 * level - 2 * j + 3)/2);
            scene->addItem(e);
        }
    }

    // designing the boss with increased health, thus making the boss more difficult to kill
    for (unsigned int i = 0; i < level; ++i) {
        Boss* b = new Boss(5 * level, 4, rand() % 2, dynamic_cast<QGraphicsItem*>(this));
        b->setPos(SCREEN_WIDTH * (i + 1) / (level + 1), BASE_ENEMY_HEIGHT/2);
        scene->addItem(b);
    }

    //more pick-ups as levels become more difficult
    for (unsigned int i = 0; i < (level + 1) / 2; ++i) {
        int random= rand()% SCREEN_WIDTH;
        tool_life* tl = new tool_life(dynamic_cast<QGraphicsItem*>(this));
        tl->setPos(random, 0);
        scene->addItem(tl);

        int random1= rand()% SCREEN_WIDTH;
        tool_atk* ta = new tool_atk(dynamic_cast<QGraphicsItem*>(this));
        ta->setPos(random1, 0);
        scene->addItem(ta);
    }


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

unsigned int GameScene::enemyCount() {
    QList<QGraphicsItem *> objectList = items();
    int size = objectList.size();
    unsigned int count = 0;
    for (int i = 0; i < size; ++i){
        // check enemy types
        if (
                typeid(*objectList[i]) == typeid(Boss) ||
                typeid(*objectList[i]) == typeid(Enemy) ||
                typeid(*objectList[i]) == typeid(abstractEnemy)
                ){
            ++count;
        }
    }
    // if no more enemies exist, return false and go on to win screen
    return count;
}
