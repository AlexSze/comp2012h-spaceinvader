/* Protagonist.h */

#ifndef PROTAGONIST_H
#define PROTAGONIST_H
#include "abstractcharacter.h"

class Protagonist : public AbstractCharacter {
    public:
        // default constructor
        Protagonist();
        // destructor does nothing, no dynamically allocated variables
        virtual ~Protagonist() {}

        void attack();
};

#endif // PROTAGONIST_H
