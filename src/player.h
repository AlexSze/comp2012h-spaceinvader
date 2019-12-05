/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <abstractobjects.h>

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QFont>
#include <QGraphicsTextItem>

class Player : public abstractobjects, public QGraphicsPixmapItem{
    Q_OBJECT

    private:
        // horizontal vector of beam direction
        int horizontal_beam{0};
        int score{0};

        // audio player object
        QMediaPlayer* pew_sound;

    public:
        // constructor
        Player(QGraphicsItem* parent=nullptr);
        ~Player();

        unsigned int get_health() const;
        int get_attack_type() const;
        int get_defense_type() const;

        void heal();
        void attack();
        void get_tool();
        void increase_score();
        int get_score() const;

        // overriding key event handler
        void keyPressEvent(QKeyEvent* event);

        virtual void hurt();

    public slots:
        //void revive();
};

#endif // PLAYER_H


