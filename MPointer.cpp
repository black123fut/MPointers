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
    data = new int;
}

template<class T>
MPointer<T>::~MPointer() {
    pointerGC->removePointer(getID());
}

template<class T>
MPointer<T> MPointer<T>::New() {
    MPointer<T> *tmp = new MPointer<T>();
    pointerGC->addPointer(tmp);
    return *tmp;
}

template<class T>
void MPointer<T>::setID(int idn) {
    id = idn;
}

template<class T>
int MPointer<T>::getID() {
//    cout << "ID get: " << id << endl;
    return id;
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
    id = pointer.getID();
}

template<class T>
void MPointer<T>::operator =(T pointer) {
    data = &pointer;
}

template<class T>
MPointerGC *MPointer<T>::pointerGC = MPointerGC::Singleton();

template class MPointer<int>;

/*
 *     MPOINTERGC
 */

MPointerGC *MPointerGC::pointerGC = nullptr;


void MPointerGC::addPointer(MPointer<int> *pointer) {
    if (pointerList == nullptr)
        pointerList = new LinkedList< MPointer<int> * >;
    pointer->setID(IDs);
    IDs++;

    pointerList->add(pointer);
}

void MPointerGC::removePointer(int id) {
    for (int i = 0; i < pointerList->length(); ++i) {
        if (pointerList->get(i)->getID() == id){
            pointerList->remove(i);
        }
    }
}

MPointerGC *MPointerGC::Singleton() {
    if (pointerGC == nullptr){
        pointerGC = new MPointerGC;
    }
    return pointerGC;
}

