#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent = nullptr);
    ~Score();
    void increase(int=1);
    void reset();
    unsigned int get_score() const { return score_count; }

private:
    unsigned int score_count;
};


#endif // SCORE_H
