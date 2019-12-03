/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <abstractobjects.h>

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player : public abstractobjects, public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    private:
        //what is it??
        int horizontal_beam{0};
        int mark{0};

        // audio player object
        QMediaPlayer* pew_sound;

    public:
        // constructor
        Player(QGraphicsItem* parent=nullptr);

        unsigned int get_health() const;
        int get_attack_type() const;
        int get_defence_type() const;

        void heal();
        void get_tool();
        void get_mark();

        // overriding key event handler
        void keyPressEvent(QKeyEvent* event);


    public slots:
        //void revive();
};

#endif // PLAYER_H


