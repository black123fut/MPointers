#include "MPointer.h"
#include "MPointerGC.h"
#include "Mapa_Memoria.h"
#include "Sort.cpp"

#include <iostream>
#include <chrono>
#include <thread>
#include "Mapa_Memoria.cpp"
#include "Server/Server.h"
#include "Server/Client.h"

using namespace std;

void insertionSort(DoubleLinkedList *list, int length){
        int i, j;
        MPointer<int> key;

        for (i = 0; i < length; i++) {
            key = list->get(i)->getData();
            j = i - 1;

            while (j >= 0 && &list->get(j)->getData() > &key) {
                list->get(j + 1)->getData() = list->get(j)->getData();
                j = j - 1;
            }
            list->get(j + 1)->getData() = key;
        }
}

void bubblesort(DoubleLinkedList *list, int length){
        for (int i = 0; i < length - 1; i++) {

            for (int j = 0; j < length - 1 - i; ++j) {

                if (&list->get(j)->getData() > &list->get(j + 1)->getData()){
                    MPointer<int> tmp;
                    tmp = list->get(j)->getData();
                    list->get(j)->getData() = list->get(j + 1)->getData();
                    list->get(j + 1)->getData() = tmp;
                }

            }
        }
    }

void quickSort(const DoubleLinkedList* list, int left, int length){
    int i = left, j = length;
    MPointer<int> tmp;
    MPointer<int> pivot = list->get((left + length) / 2)->getData();

    while (i <= j) {
        while (&list->get(i)->getData() < &pivot)
            i++;
        while (&list->get(j)->getData() > &pivot)
            j--;
        if (i <= j){
            tmp = list->get(i)->getData();
            list->get(i)->getData() = list->get(j)->getData();
            list->get(j)->getData() = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(list, left, j);
    if (i < length)
        quickSort(list, i, length);
}

void pruebasDeGarbage(){
    MPointer<int> pointer1 = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();
    MPointer<int> pointer3 = MPointer<int>::New();
//    MPointer<int> pointer4 = MPointer<int>::New();
//    MPointer<int> pointer5 = MPointer<int>::New();
//    MPointer<int> pointer6 = MPointer<int>::New();
//    MPointer<int> pointer7 = MPointer<int>::New();
//    MPointer<int> pointer8 = MPointer<int>::New();

    pointer1 = 7;
    pointer2 = 5;
    pointer3 = 32;
//    pointer4 = 56;
//    pointer5 = 21;
//    pointer6 = 19;
//    pointer7 = 22;
//    pointer8 = 35;

    DoubleLinkedList *list = new DoubleLinkedList;
    list->add(pointer1);
    list->add(pointer2);
    list->add(pointer3);
//    list->add(pointer4);
//    list->add(pointer5);
//    list->add(pointer6);
//    list->add(pointer7);
//    list->add(pointer8);

    quickSort(list, 0, list->length() - 1);
//    cout << "Bubblesort" << endl;
//    bubblesort(list, list->length());
//    insertionSort(list, list->length());

    cout << "--------------------" << endl;
    for (int i = 0; i < list->length(); ++i) {
        cout << &list->get(i)->getData() << ", " << endl;
    }
    cout << "- - - - - - -" << endl;

//    cout << "Prueba: " << &pointer1 << endl;
//    cout << "Prueba: " << &pointer2 << endl;

//    pointer1 = 1;
//    pointer2 = 11;
//    pointer5 = 17;
//    pointer6 = 4;
//    pointer7 = 25;
//    pointer8 = 22;
}


class DoubleLinkedList;
int main() {

    pruebasDeGarbage();

//    MPointer<int> pointer1 = MPointer<int>::New();
//    MPointer<int> pointer2 = MPointer<int>::New();
//    MPointer<int> pointer3 = MPointer<int>::New();
//    MPointer<int> pointer4 = MPointer<int>::New();
//    MPointer<int> pointer5 = MPointer<int>::New();
//    MPointer<int> pointer6 = MPointer<int>::New();
//    MPointer<int> pointer7 = MPointer<int>::New();
//    MPointer<int> pointer8 = MPointer<int>::New();
//
//    pointer1 = 7;
//    pointer2 = 5;
//    pointer3 = 1;
//    pointer4 = 11;
//    pointer5 = 17;
//    pointer6 = 4;
//    pointer7 = 25;
//    pointer8 = 22;

    //pruebasDeGarbage();

    int r = 20;

    while (r != 0){
        r--;
        this_thread::sleep_for(chrono::seconds(1));
    }



    return 0;
}