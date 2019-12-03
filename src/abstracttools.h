/* AbstractTools.h */


#ifndef ABSTRACTTOOLS_H
#define ABSTRACTTOOLS_H


class abstracttools {
    protected:
        unsigned int weapon{0};
        unsigned int defense{0};
        unsigned int heal{0};

    public:
        abstracttools();
        ~abstracttools();
};

#endif // ABSTRACTTOOLS_H
