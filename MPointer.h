#ifndef MPOINTERS_MPOINTER_H
#define MPOINTERS_MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

using namespace std;


template <class T>
class MPointer{
public:
    MPointer();
    MPointer<T> static New();
    void setID(int);
    int getID();
    T &(operator *());
    T operator &();
    void operator =(MPointer<T>);
    void operator =(T);
    ~MPointer();

private:
    T *data;
    MPointerGC static *pointerGC;
    int id;
};


#endif //MPOINTERS_MPOINTER_H
