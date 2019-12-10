/* AbstractTools.h */


#ifndef ABSTRACTTOOLS_H
#define ABSTRACTTOOLS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "player.h"

class abstracttools : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    protected:
        unsigned int weapon{0};
        unsigned int defense{0};
        unsigned int heal{0};

    public:
        abstracttools(QGraphicsItem* parent=nullptr);
        void move_timer();

    public slots:
        virtual void move();
};

#endif // ABSTRACTTOOLS_H
