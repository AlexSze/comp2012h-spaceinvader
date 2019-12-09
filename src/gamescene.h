#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"

/* game element class here */

class GameScene : public QGraphicsView {
public:
    GameScene(QWidget* parent = nullptr);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void mainwindow();

};

#endif // GAMESCENE_H
