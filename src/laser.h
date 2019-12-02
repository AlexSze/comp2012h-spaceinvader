#ifndef LASER_H
#define LASER_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Laser: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    private:
        const int speed;
    public:
        Laser(int speed, QGraphicsPixmapItem* parent=nullptr);
    public slots:
        void move();
};

#endif // LASER_H
