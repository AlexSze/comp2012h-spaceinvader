#include "abstractobjects.h"

// default constructor
abstractobjects::abstractobjects()
    : health(1),
    attack_type(LASER),
    defense_type(NUL),
    speed(1) {}

// copy constructor
abstractobjects::abstractobjects(unsigned int health, int attack_type, int defense_type, int speed)
    : QObject(),
    health(health),
    attack_type(attack_type),
    defense_type(defense_type),
    speed(speed) {}

// destructor
abstractobjects::~abstractobjects() {}

// check living status
bool abstractobjects::alive(){
    return health;
}

void abstractobjects::attack(){

}
