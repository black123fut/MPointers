#include <iostream>
#include "DoubleLinkedList.cpp"

using namespace std;

class Sort{
public:
    void bubblesort(DoubleLinkedList *list, int length){
        for (int i = 0; i < length - 1; i++) {

            for (int j = 0; j < length - 1 - i; ++j) {
                if (&list->get(j) > &list->get(j + 1)){
                    MPointer<int> tmp = MPointer<int>::New();
                    tmp = list->get(j);
                    list->get(j) = list->get(j + 1);
                    list->get(j + 1) = tmp;
                }
            }
        }
    }

    void quickSort(DoubleLinkedList *list, int left, int length){
        int i = left, j = length;
        MPointer<int> tmp = MPointer<int>::New();
        MPointer<int> pivot = list->get((left + length) / 2);

        while (i <= j) {
            while (&list->get(i) < &pivot)
                i++;
            while (&list->get(j) > &pivot)
                j--;
            if (i <= j){
                tmp = list->get(i);
                list->get(i) = list->get(j);
                list->get(j) = tmp;
                i++;
                j--;
            }
        }

        if (left < j)
            quickSort(list, left, j);
        if (i < length)
            quickSort(list, i, length);

    }

    void insertionSort(DoubleLinkedList *list, int length){
        int i, j;
        MPointer<int> key = MPointer<int>::New();

        for (i = 0; i < length; i++) {
            key = list->get(i);
            j = i - 1;

            while (j >= 0 && &list->get(j) > &key) {
                list->get(j + 1) = list->get(j);
                j = j - 1;
            }
            list->get(j + 1) = key;
        }
    }
private:

};
