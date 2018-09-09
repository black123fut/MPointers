#ifndef MPOINTERS_MPOINTERGC_H
#define MPOINTERS_MPOINTERGC_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList;
template <class T>
class MPointer;
class MPointerGC {
public:

    void addPointer(MPointer<int>);
    static MPointerGC *Singleton();
private:
    static MPointerGC *pointerGC;
    LinkedList< MPointer<int> > *pointerList;
    MPointerGC(){}
};

#endif //MPOINTERS_MPOINTERGC_H
