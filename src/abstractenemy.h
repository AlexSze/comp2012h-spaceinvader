/* abstractenemy */

#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H
#include "abstractcharacter.h"

class AbstractEnemy: public AbstractCharacter {
    public:
        // default constructor
        AbstractEnemy(unsigned int, unsigned int, unsigned int);
        // destructor does nothing, no dynamically allocated variables
        virtual ~AbstractEnemy() {}

        void attack();
};

#endif // ABSTRACTENEMY_H
