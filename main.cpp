#include "MPointer.h"
#include "MPointerGC.h"
#include "Mapa_Memoria.h"
#include "Sort.cpp"

#include <iostream>
#include "Mapa_Memoria.cpp"

using namespace std;


class DoubleLinkedList;
int main() {

    int contador_direcciones=0;
    int IDs=0;


    MPointer<int> pointer1 = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();
    MPointer<int> pointer3 = MPointer<int>::New();
    MPointer<int> pointer4 = MPointer<int>::New();
    MPointer<int> pointer5 = MPointer<int>::New();
    MPointer<int> pointer6 = MPointer<int>::New();
    MPointer<int> pointer7 = MPointer<int>::New();
    MPointer<int> pointer8 = MPointer<int>::New();

    pointer1 = 7;
    pointer2 = 5;
    pointer3 = 1;
    pointer4 = 11;
    pointer5 = 17;
    pointer6 = 4;
    pointer7 = 25;
    pointer8 = 22;


    DoubleLinkedList *list = new DoubleLinkedList;
    list->add(pointer1);
    list->add(pointer2);
    list->add(pointer3);
    list->add(pointer4);
    list->add(pointer5);
    list->add(pointer6);
    list->add(pointer7);
    list->add(pointer8);

    for (int j = 0; j < list->length(); ++j) {
        cout << &list->get(j) << ", ";
    }

    cout << endl;

    Sort *sort = new Sort;
    sort->insertionSort(list, list->length());
    cout << endl;

    for (int i = 0; i < list->length(); ++i) {
        cout << &list->get(i) << ", ";
    }
    cout << endl;

    //pointer1.set_dato(47);
    //cout<<pointer1.get_dato()<<endl;

    Mapa_Memoria<int> n(1000);

    //Pruebas de la reservacion de memoria en el heap

    contador_direcciones+=n.reservar_memoria(IDs,contador_direcciones,45);
    IDs+=1;


    contador_direcciones+=n.reservar_memoria(IDs,contador_direcciones,78);
    IDs+=1;


    contador_direcciones+=n.reservar_memoria(IDs,contador_direcciones,89);
    IDs+=1;

    contador_direcciones+=n.reservar_memoria(IDs,contador_direcciones,56);
    IDs+=1;


    cout<<"Dato:"<<endl;

    n.asignar_dato(0,35);
    n.asignar_dato(1,53);
    n.asignar_dato(2,80);
    n.asignar_dato(3,100);

    cout << n.obtener_dato(0) << endl;
    cout<< n.buscar_Mpointer(0)<<endl;

    cout << n.obtener_dato(3) << endl;
    cout<< n.buscar_Mpointer(3)<<endl;

    cout << n.obtener_dato(2) << endl;
    cout<< n.buscar_Mpointer(2)<<endl;

    cout << n.obtener_dato(1) << endl;
    cout<< n.buscar_Mpointer(1)<<endl;





    //cout << *pointer1<< endl;
    //cout << "ID: " << pointer1.getID() << endl;
    //cout << "ID: " << pointer2.getID() << endl;


   // cout << &n.buscar(1) << endl;
    return 0;
}