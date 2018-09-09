#ifndef MPOINTERS_MPOINTER_H
#define MPOINTERS_MPOINTER_H

#include <iostream>

using namespace std;

class MPointerGC;
template <class T>
class MPointer{
public:
    MPointer();
    MPointer<T> static New();
    T &(operator *());
    T operator &();
    void operator =(MPointer<T>);
    void operator =(T);

private:
    T *data;
    MPointerGC *pointerGC;
};

#endif //MPOINTERS_MPOINTER_H
