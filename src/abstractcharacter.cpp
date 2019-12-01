/* AbstractCharacter.cpp */

#include "abstractcharacter.h"

// constructor
AbstractCharacter::AbstractCharacter(unsigned int weaponType, unsigned int defenseType, unsigned int health)
    : weaponType(weaponType),
    defenseType(defenseType),
    health(health) {}

// copy constructor
AbstractCharacter::AbstractCharacter(AbstractCharacter& a)
    : weaponType(a.weaponType),
    defenseType(a.defenseType),
    health(a.health) {}

// create laser beam or minions
void AbstractCharacter::attack() {}

// get hit by a laser beam or minion; returns living or not
bool AbstractCharacter::hit() {
    return (--health == 0);
}
