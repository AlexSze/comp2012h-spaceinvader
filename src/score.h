#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase(int=1);
    void reset();
    unsigned int get_score() const { return score; }

private:
    unsigned int score;
};


#endif // SCORE_H
