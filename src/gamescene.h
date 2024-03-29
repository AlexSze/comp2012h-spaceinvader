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
#include "abstracttools.h"

using namespace std;

extern Score* score;
extern life* lifes;

/* game element class here */

class GameScene : public QGraphicsView {
public:
    GameScene(QWidget* parent = nullptr);
    ~GameScene();
    QGraphicsScene* scene{nullptr};
    Player* player{nullptr};
    Health* health{nullptr};

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void mainwindow();

    void screen_construction();
    void character_construction(unsigned int = 1);

    void newPlayer();

    unsigned int enemyCount();
};

#endif // GAMESCENE_H
