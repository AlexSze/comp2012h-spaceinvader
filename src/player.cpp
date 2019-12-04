/* player.cpp */

#include "player.h"
#include "laser.h"
#include "constants.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QList> // QKeyEvent Key library
#include <QTimer>

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
        Laser* l = new Laser(-10, horizontal_beam);
        l->setPos(this->x() + PLAYER_WIDTH/2, this->y() - PLAYER_HEIGHT);
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
        Player* p= new Player();
        // place the player in the bottom of screen
        p->setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT);

        // make it main window focusable
        p->setFlag(QGraphicsItem::ItemIsFocusable);
        // put player in scene
        scene()->addItem(p);
        // make it main window of focus
        p->setFocus();
    }
    // self destruction
    delete this;
}

Player::~Player() {
    // prepare removal from scene
    QGraphicsItem::prepareGeometryChange();
}
unsigned int Player::get_health() const {
    return health;
}

int Player::get_attack_type() const{
    return attack_type;
}

int Player::get_defense_type() const{
    return defense_type;
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

int Player::get_mark() const {
    return mark;
}
