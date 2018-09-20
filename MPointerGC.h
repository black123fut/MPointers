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

    void addPointer(MPointer<int> *);
    void garbageCollector();
    void removePointer(int id);
    static MPointerGC *Singleton();
private:
    static MPointerGC *pointerGC;
    int IDs = 0;
    LinkedList< MPointer<int> * > *pointerList = nullptr;
    MPointerGC(){}
};

#endif //MPOINTERS_MPOINTERGC_H
