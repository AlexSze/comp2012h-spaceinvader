/* AbstractTools.h */


#ifndef ABSTRACTTOOLS_H
#define ABSTRACTTOOLS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class abstracttools : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    protected:
        unsigned int weapon{0};
        unsigned int defense{0};
        unsigned int heal{0};

    public:
        abstracttools(QGraphicsItem* parent=nullptr);

    public slots:
        void move();
};

#endif // ABSTRACTTOOLS_H
