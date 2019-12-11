#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QObject>

enum ATTACK {LASER /* default */, MINION, COLLISION};
enum DEFENSE {NUL /* default */, BARRIER};

class abstractobjects : public QObject {
    protected:
        int health;
        const int attack_type;
        const int defense_type;
        int speed;

    public:
        // default constructor
        abstractobjects();
        // health, attack_type, defense_type, speed
        abstractobjects(unsigned int, int, int, int);
        // destructor
        ~abstractobjects();

        bool alive();
        void attack();
        // function of object being hurt, to be implemented by derived classes
        virtual bool hurt()=0;
};



#endif // ABSTRACTOBJECT_H
