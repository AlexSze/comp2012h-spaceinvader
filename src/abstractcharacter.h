/* AbstractCharacter.h */

#ifndef ABSTRACTCHARACTER_H
#define ABSTRACTCHARACTER_H

#include <QObject>
#include <QWidget>

enum WEAPON_TYPE {NUL, LASER, MINION};
enum DEFENSE_TYPE {/* NUL = 0 */ WALL = 1, GUARD};

class AbstractCharacter {
    protected:
        unsigned int weaponType{0};
        unsigned int defenseType{0};
        unsigned int health{0};
    public:

        // constructor
        AbstractCharacter(unsigned int, unsigned int, unsigned int);

        // copy constructor
        AbstractCharacter(AbstractCharacter&);

        // destructor does nothing, no dynamically allocated variables
        virtual ~AbstractCharacter();

        unsigned int get_health() const { return this->health; }
        virtual void attack(); // create laser beam or minions
        bool hit(); // get hit by a laser beam or minion; returns living or not
};

#endif // ABSTRACTCHARACTER_H


