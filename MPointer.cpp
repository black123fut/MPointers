#include "MPointer.h"
#include "MPointerGC.h"

#include "LinkedList.cpp"
#include <iostream>


using namespace std;

/*
 *    MPOINTER
 */

template<class T>
MPointer<T>::MPointer() {
    pointerGC = MPointerGC::Singleton();
    data = new int;
}

template<class T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

template<class T>
T &(MPointer<T>::operator *()){
    return *data;
}

template<class T>
T MPointer<T>::operator &() {
    return *data;
}

template<class T>
void MPointer<T>::operator =(MPointer<T> pointer) {
    data = pointer.data;
}

template<class T>
void MPointer<T>::operator =(T pointer) {
    data = &pointer;
}

template class MPointer<int>;

/*
 *     MPOINTERGC
 */

MPointerGC *MPointerGC::pointerGC = nullptr;


void MPointerGC::addPointer(MPointer<int> pointer) {
    pointerList = new LinkedList< MPointer<int> >;
    pointerList->add(pointer);
}

MPointerGC *MPointerGC::Singleton() {
    if (pointerGC == nullptr){
        pointerGC = new MPointerGC;
    }
    return pointerGC;
}

