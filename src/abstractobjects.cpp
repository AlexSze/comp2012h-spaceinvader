#include "abstractobjects.h"

abstractobjects::abstractobjects()
    : health(1),
    attack_type(LASER),
    defense_type(NUL),
    speed(1) {}

abstractobjects::abstractobjects(unsigned int health, int attack_type, int defense_type, int speed)
    : QObject(),
    health(health),
    attack_type(attack_type),
    defense_type(defense_type),
    speed(speed) {}

abstractobjects::~abstractobjects() {
}

