#include "MPointer.h"
#include "MPointerGC.h"

#include "DataStructures/LinkedList.cpp"
#include <iostream>
#include <utility>

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
int MPointer<T>::getID() const {
//    cout << "ID get: " << id << endl;
    return id;
}

template <typename T>
void MPointer<T>::set_dato(T dato) { //Metodo agregado por Gabriel
    Dato=dato;
}

template <typename T>
int MPointer<T>::get_dato() { //Metodo agregado por Gabriel
    return Dato;
}

template <class T>
T * MPointer<T>::getData() const {
    return data;
}

template <class T>
void MPointer<T>::setData(T *data) {
    this->data = data;
    *this->data = *data;

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
MPointer<T> &MPointer<T>::operator =(const MPointer<T> &pointer) {
    this->id = pointer.getID();

    *data = *pointer.data;

    return *this;
}

template<class T>
MPointer<T> & MPointer<T>::operator =(T pointer) {
    *data = pointer;
    return *this;
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

void MPointerGC::garbageCollector() {


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

