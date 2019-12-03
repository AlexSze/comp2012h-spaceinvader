#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

class abstractobjects{
    protected:
        unsigned int health;
        int attact_type;
        int defence_type;
        int speed;

    public:
        abstractobjects();
        ~abstractobjects();

        bool alive();
        void attacked();
};



#endif // ABSTRACTOBJECT_H
