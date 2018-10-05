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
    MPointerGC();
    void addPointer(MPointer<int> *, int);
    void setIDPointer(int, int);
    static void* garbageCollector(void *);
    MPointer<int> getPointer(int);
    void removePointer(int id);
    void setServerIDPointer(int);
    static MPointerGC *Singleton();
private:
    static MPointerGC *pointerGC;
    int IDs = 0;
    static LinkedList< MPointer<int> * > *pointerList;
};

#endif //MPOINTERS_MPOINTERGC_H
