/* player.cpp */
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QList> // QKeyEvent Key library
#include <QTimer>
#include <QDebug>
#include <iostream>

#include "player.h"

using namespace std;

// constructor
Player::Player(QGraphicsItem* parent)
    : QGraphicsPixmapItem(),
    //proporty setup
    abstractobjects (1, 0, 0, 20) {
        // set the character in the bottom middle of the screen
        setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT);

        // draw the character
        setPixmap(QPixmap(":/src/images/player.png"));
        setTransformOriginPoint(50,50);
        // setup sound oobject
        pew_sound = new QMediaPlayer();
        pew_sound->setMedia(QUrl("qrc:/src/sounds/pew.wav"));
}

// Key Press Event Handler
void Player::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    // move left
    case Qt::Key_A:
        if (x() >= 0)
            setPos(x()-this->speed, y());
        break;
    // move right
    case Qt::Key_D:
        if (x() <= SCREEN_WIDTH - PLAYER_WIDTH)
            setPos(x()+this->speed, y());
        break;
    //move up
    case Qt::Key_W:
        if (y() >= 0)
            setPos(x(), y()-this->speed);
        break;
    //move down
    case Qt::Key_S:
        if (y() <= SCREEN_HEIGHT - PLAYER_HEIGHT)
            setPos(x(), y()+this->speed);
        break;
    // shoot laser gun
    case Qt::Key_Space: {
        // create laser beam
        Laser* l = new Laser(-10, horizontal_beam);
        l->setPos(this->x() + PLAYER_WIDTH/2, this->y() - PLAYER_HEIGHT/2);
        scene()->addItem(l);
        // no storage required, laser beam will be automatically deleted when
        // 1. beam hits somebody
        // 2. beam goes off screen
        // 3. parent (this object) is deleted
        if (pew_sound->state() == QMediaPlayer::StoppedState)
            pew_sound->play();
        else
            pew_sound->setPosition(0);
        break;
    }
    // move laser gun to the left
    case Qt::Key_Up:
        // change angle of laser gun
        if (horizontal_beam > -20)
            horizontal_beam -= 5;
        break;
    // move laser gun to the right
    case Qt::Key_Down:
        // change angle of laser gun
        if (horizontal_beam < 20)
            horizontal_beam += 5;
        break;
    }
}

void Player::hurt() {
    // end scene
    // spawn a new player if there's extra life left
    if (true /* have extra life */) {
        // allocate player of the game
        //s->health->reset();

        Player* p= new Player();
        // place the player in the bottom of screen
        p->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT);

        // make it main window focusable
        p->setFlag(QGraphicsItem::ItemIsFocusable);
        // put player in scene
        scene()->addItem(p);
        // make it main window of focus
        p->setFocus();
    }//else if (s->health->get_health()==0){

        //s->close();
        //delete s;

        //n= new defeat_screen;
        //n->show();
   // }


    // self destruction
    delete this;
}

Player::~Player() {
    // prepare removal from scene
    QGraphicsItem::prepareGeometryChange();
}

int Player::get_attack_type() const{
    return attack_type;
}

int Player::get_defense_type() const{
    return defense_type;
}

void Player::heal(){
    //s->health->increase();
    //TODO, cannot include gamescene as gamescene included player
}

void Player::attack(){
    // TODO
}

void Player::get_tool(){
    // TODO
}

void Player::increase_score()
{
    score++;
    cout<<score<<endl;
}

int Player::get_score() const {
    return score;
}
