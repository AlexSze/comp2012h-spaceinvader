#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QObject>

enum ATTACK_TYPE {LASER /* default */, MINION, COLLISION};
enum DEFENSE_TYPE {NUL /* default */, BARRIER};

class abstractobjects : public QObject {
    protected:
        unsigned int health;
        const int attack_type;
        const int defense_type;
        int speed;

    public:
        // default constructor
        abstractobjects();
        // health, attack_type, defense_type, speed
        abstractobjects(unsigned int, int, int, int);

        ~abstractobjects();

        void destruct();

        bool alive();
        void attack();
        void hurt();
};



#endif // ABSTRACTOBJECT_H
