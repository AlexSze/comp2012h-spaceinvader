#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsView>

#include "score.h"
#include "laser.h"
#include "constants.h"
#include "abstractenemy.h"
#include "player.h"
#include "gamescene.h"
#include "defeat_screen.h"
#include "win_screen.h"
#include "boss.h"
#include "gamescene3.h"
#include "win_scene_gs3.h"
#include "enemy.h"

#include <QDebug>

extern GameScene* s;
extern win_screen* a;
extern win_scene_gs3* u;
extern defeat_screen* n;

Laser::Laser(int speed, int horizontal_speed, QGraphicsPixmapItem* parent)
    : QObject(),
      QGraphicsPixmapItem(parent),
      speed(speed),
      horizontal_speed(horizontal_speed) {
    // set laser graphic
    setPixmap(QPixmap(":/src/images/laser.png"));
    // draw the rectangle in place for a laser
    //setRect(0,0,5,40);

    // create a timer
    // since timer has this object as parent, it will be
    // killed automatically when this object is killed
    QTimer* t = new QTimer(this);
    // connect a timer to call move()
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    // start a timer for 25fps of motion
    t->start(40);
}

void Laser::move() {
    // check if laser collided with anything
    QList<QGraphicsItem *> colliding = collidingItems();
    int size = colliding.size();
    for (int i=0; i<size; ++i) {
        // check colliding type
        if (
                // make sure only bullet from the player hurts enemy
                speed < 0 &&
                // kill collided enemies
                (typeid(*colliding[i]) == typeid(Enemy) ||
                 typeid(*colliding[i]) == typeid(Boss))) {
            //add score
            score->increase();

            // remove both laser and colliding object

            // hurt colliding object
            static_cast <abstractEnemy*>
                (colliding[i])->hurt();

            // uncomment if develop infinity mode
            /*
            // if in infinity mode, regenerate enemies
            if (typeid(*s) == typeid(GameSceneInfinity)) {
                // regenerate enemies when there are not enough
                if (s->enemyCount() <= 8) {
                    reinterpret_cast<GameSceneInfinity*>(s)->regenerate_enemy();
                }
            }
            */

            // check if all enemies are killed
            if (s->enemyCount() == 0) {
                //show win_screen
                if (typeid (*s)==typeid(gamescene3)) {
                    // player reached the end, show ultimate win screen
                    if (u == nullptr) {
                        u = new win_scene_gs3;
                        u->show();
                    }
                }
                else {
                    // show win screen to proceed to next level
                    if (a == nullptr) {
                        a = new win_screen;
                        a->show();
                    }
                }

                s->scene->removeItem(score);
                s->scene->removeItem(lifes);
                s->close();
                //delete s; it is deleted on win_screen
                return;
            }

            // delete laser
            delete this;
            return;
        }
        else if (
                // make sure only bullet from enemies hurts the player
                speed > 0 &&
                typeid(*(colliding[i])) == typeid(Player)
                ) {
            // decrease health
            s->health->decrease();

            if (s->health->get_health()==0) {
                if (!(static_cast <Player*>(colliding[i])->hurt())) {
                    //show defeat screen
                    if (n == nullptr) {
                        n = new defeat_screen;
                        n->show();

                        s->scene->removeItem(score);
                        s->scene->removeItem(lifes);
                        s->close();
                    }
                }
            }
            // delete laser
            delete this;
            return;
        }
        else if (typeid(*(colliding[i])) == typeid(Laser)) {
            // delete laser
            delete this;
            return;
        }
    }

    // move laser
    setPos(x() + this->horizontal_speed, y() + this->speed);
    // check out of frame
    if (pos().y() > SCREEN_HEIGHT || pos().y() < 0) {
        // player wasted a bullet, mark panelty
        if (pos().y() < 0)
            score->increase(PENALTY_WASTING_BULLET);
        // remove from scene and delete of out of frame
        scene()->removeItem(this);
        delete this;
    }
}

Laser::~Laser() {
    // prepare removal from scene
    QGraphicsItem::prepareGeometryChange();
}
