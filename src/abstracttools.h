/* AbstractTools.h */


#ifndef ABSTRACTTOOLS_H
#define ABSTRACTTOOLS_H


class AbstractTools {
    protected:
        unsigned int weapon{0};
        unsigned int defense{0};
        unsigned int health{0};
    public:
        void attack();
        bool hit();
};

#endif // ABSTRACTTOOLS_H
