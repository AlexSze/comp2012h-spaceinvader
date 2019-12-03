// KeyPress.cpp file modeled after https://forum.qt.io/topic/20982/solved-how-to-handle-all-the-keys-in-key-press-release-event/2
// Reads keyboard event

#include <QApplication>
#include <QKeyEvent>
#include "KeyPress.h"
#include "laser.h"

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent) {
    myLabelText = new QLabel ("You Didn't Pressed / Released any Key");
}

void KeyPress::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {

    case Qt::Key_W:
        //move_up();
        break;
    case Qt::Key_A:
        //move_left();
        break;
    case Qt::Key_S:
        //move_down();
        break;
    case Qt::Key_D:
        //move_right();
        break;
    case Qt::Key_Escape:
        //esc();
        break;
    case Qt::Key_Space:
        //shoot();
        break;
    }
}

void KeyPress::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {

    case Qt::Key_W:
        //stop_move_up();
        break;
    case Qt::Key_A:
        //stop_move_left();
        break;
    case Qt::Key_S:
        //stop_move_down();
        break;
    case Qt::Key_D:
        //stop_move_right();
        break;
    case Qt::Key_Escape:
        //stop_esc();
        break;
    case Qt::Key_Space:
        //stop_shoot();
        break;
    }
}
