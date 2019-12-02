/* AbstractCharacter.h */

#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class AbstractCharacter {
    protected:
        unsigned int health{1};
    public:

        // constructor
        AbstractCharacter(unsigned int health, QGraphicsItem* parent=nullptr);

        // copy constructor
        //AbstractCharacter(AbstractCharacter&);

        // destructor does nothing, no dynamically allocated variables
        //virtual ~AbstractCharacter();

        unsigned int get_health() const { return this->health; }
        // dying is handled by the bullet instead
        // die();
    public slots:
        void move();
        void shoot();
};

#endif // ABSTRACTCHARACTER_H


