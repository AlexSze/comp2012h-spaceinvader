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
        const int horizontal_speed;
    public:
        Laser(int speed, int horizontal_speed = 0, QGraphicsPixmapItem* parent=nullptr);
        ~Laser();
    public slots:
        void move();
};

#endif // LASER_H
