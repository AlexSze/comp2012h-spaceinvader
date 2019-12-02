/* abstractenemy.cpp */
#include "abstractenemy.h"

AbstractEnemy::AbstractEnemy(unsigned int weaponType, unsigned int defenseType, unsigned int health)
    : AbstractCharacter (weaponType, defenseType, health) {}

// create laser beam
void AbstractEnemy::attack() {
    // new beam/enemy
}
