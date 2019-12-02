/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    private:
        unsigned int health{1};
        const int speed{20};
        int horizontal_beam{0};
        // audio player object
        QMediaPlayer* pew_sound;
    public:
        // constructor
        Player(QGraphicsItem* parent=nullptr);
        // overriding key event handler
        void keyPressEvent(QKeyEvent* event);
    public slots:
        void revive();
};

#endif // PLAYER_H


