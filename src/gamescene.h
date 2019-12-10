#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include "life.h"
#include "abstractenemy.h"

/* game element class here */

class GameScene : public QGraphicsView {
public:
    GameScene(QWidget* parent = nullptr);
    QGraphicsScene* scene{nullptr};
    Player* player{nullptr};
    Score* score{nullptr};
    Health* health{nullptr};
    life* lifes{nullptr};
    abstractEnemy* boss;

    virtual void set_bg();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void mainwindow();

    void newPlayer();
};

#endif // GAMESCENE_H
