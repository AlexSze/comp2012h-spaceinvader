#include "gamescene2.h"
#include <QDebug>

void gamescene2::set_bg()
{
    // set window background
    setBackgroundBrush(QBrush(QImage(":/src/images/background2.png")));

    qDebug()<<"ys";
}
