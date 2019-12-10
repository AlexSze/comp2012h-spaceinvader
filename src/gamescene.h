#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <list>
#include <iostream>

#include "player.h"
#include "score.h"
#include "health.h"
#include "life.h"
#include "abstractenemy.h"

using namespace std;

/* game element class here */

class GameScene : public QGraphicsView {
public:
    GameScene(QWidget* parent = nullptr);
    ~GameScene();
    QGraphicsScene* scene{nullptr};
    Player* player{nullptr};
    Score* score{nullptr};
    Health* health{nullptr};
    life* lifes{nullptr};
    abstractEnemy* boss;
    list<abstractEnemy*> e;

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void mainwindow();

    void screen_construction();
    void character_construction();

    void newPlayer();
};

#endif // GAMESCENE_H
