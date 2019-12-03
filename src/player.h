/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <abstractobjects.h>

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player : public abstractobjects, public QGraphicsPixmapItem{
    Q_OBJECT

    private:
        // horizontal vector of beam direction
        int horizontal_beam{0};
        int mark{0};

        // audio player object
        QMediaPlayer* pew_sound;

    public:
        // constructor
        Player(QGraphicsItem* parent=nullptr);

        unsigned int get_health() const;
        int get_attack_type() const;
        int get_defense_type() const;

        void heal();
        void attack();
        void get_tool();
        int get_mark() const;

        // overriding key event handler
        void keyPressEvent(QKeyEvent* event);

        void destruct();

    public slots:
        //void revive();
};

#endif // PLAYER_H


