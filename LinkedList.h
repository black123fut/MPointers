//
// Created by enrique on 13/09/18.
//

#ifndef MPOINTERS_LINKEDLIST_H
#define MPOINTERS_LINKEDLIST_H
#include "MPointer.h"

template <typename T>

class LinkedList{
private:
    int size;
    MPointer<T> *head;

public:
    LinkedList();
    void add(T data);
    void remove(int index);
    T get(int index);

};

#endif //MPOINTERS_LINKEDLIST_H
