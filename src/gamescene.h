#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
/* game element class here */

class GameScene : public QGraphicsView {
public:
    GameScene(QWidget* parent = nullptr);
    QGraphicsScene* scene;
    Player* player;
};

#endif // GAMESCENE_H
