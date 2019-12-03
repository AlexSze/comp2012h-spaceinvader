/* player.cpp */

#include "player.h"
#include "laser.h"
#include "constants.h"
#include <stdlib.h> // to get randomised starting position
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QList>
#include <QTimer>

// constructor
Player::Player(QGraphicsItem* parent)
    : QObject (),
    QGraphicsPixmapItem(parent) {
        // set the character at a random position at the top of the screen
        setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT);

        // draw the character
        setPixmap(QPixmap(":/src/images/player.png"));
        setTransformOriginPoint(50,50);
        pew_sound = new QMediaPlayer();
        pew_sound->setMedia(QUrl("qrc:/src/sounds/pew.wav"));

        //proporty setup
        health{1};
        speed{20};
        attack_type{0};
        defence_type{0}

        horizontal_beam{0};
}

// Key Press Event Handler
void Player::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    // move left
    case Qt::Key_Left:
        if (x() >= 0)
            setPos(x()-this->speed, y());
        break;
    // move right
    case Qt::Key_Right:
        if (x() <= SCREEN_WIDTH - PLAYER_WIDTH)
            setPos(x()+this->speed, y());
        break;
    // shoot laser gun
    case Qt::Key_Space: {
        // create laser beam
        Laser* l = new Laser(-10, this, horizontal_beam);
        l->setPos(this->x() + PLAYER_WIDTH/2, this->y() - PLAYER_HEIGHT);
        scene()->addItem(l);
        // no storage required, laser beam will be automatically deleted when
        // 1. beam hits somebody
        // 2. beam goes off screen
        // 3. parent (this object) is deleted
        break;
    }
    // move laser gun to the left
    case Qt::Key_Up:
        // change angle of laser gun
        if (horizontal_beam > -20)
            horizontal_beam -= 10;
        break;
    // move laser gun to the right
    case Qt::Key_Down:
        // change angle of laser gun
        if (horizontal_beam < 20)
            horizontal_beam += 10;
        break;
    }

}

unsigned int Player::get_health() const {
    return health;
}

int Player::get_attack_type() const{
    return attact_type;
}

int Player::get_defence_type() const{
    return defence_type;
}

void Player::heal(){
    // TODO
}

void Player::attack(){
    // TODO
}

void Player::get_tool(){
    // TODO
}

void Player::get_mark(){
    // TODO
}
