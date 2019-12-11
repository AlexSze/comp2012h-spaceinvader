#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(int increment){
    // cap score at 0 minimum, no underflow
    if ((int)score + increment < 0)
        score = 0;
    else
        score += increment;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

void Score::reset()
{
    score=0;
}
