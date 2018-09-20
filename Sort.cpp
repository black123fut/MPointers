//
// Created by isaac on 19/09/18.
//

#include <iostream>
#include "DoubleLinkedList.cpp"

using namespace std;

class Sort{
public:
    void quickSort(DoubleLinkedList *list, int left, int rigth);

    void insertionSort(DoubleLinkedList *list, int length){
        int i, j;
        MPointer<int> pivot = MPointer<int>::New();

        for (i = 0; i < length; i++) {
            pivot = list->get(i);
            j = i -1;

            while (j >= 0 && &list->get(j) > &pivot){
                list->get(j + 1) = list->get(j);
                j = j -1;
            }
            list->get(j + 1) = pivot;
        }
    }

};