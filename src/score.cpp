#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score_count = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score_count)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

extern Score* score;
Score::~Score() {
    score = nullptr;
}

void Score::increase(int increment){
    // cap score at 0 minimum, no underflow
    if ((int)score_count + increment < 0)
        score_count = 0;
    else
        score_count += increment;
    setPlainText(QString("Score: ") + QString::number(score_count)); // Score: 1
}

void Score::reset()
{
    score_count=0;
}
