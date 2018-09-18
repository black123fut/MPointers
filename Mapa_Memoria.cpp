//
// Created by enrique on 11/09/18.
//

#include <iostream>
#include "MPointer.h"
#include "MPointerGC.h"
#include "Mapa_Memoria.h"
#include "LinkedList.cpp"

using namespace std;


template <typename T>

Mapa_Memoria<T>::Mapa_Memoria(int size_heap) {
        lista_memoria= new LinkedList<MPointer<int>*>;
        cout<<"Lista memoria:"<<endl;
        cout<<lista_memoria<<endl;
        heap = (MPointer<int>*) malloc(size_heap);
        cout<<"heap:"<<endl;
        cout<<heap<<endl;
    }

template <typename T>
int Mapa_Memoria<T>::reservar_memoria(int IDs, int contador_direcciones,int A) {


    MPointer<int> *x= new MPointer<int>();
    x=heap+contador_direcciones;
    x->setID(IDs);
    lista_memoria->add(x);
    return sizeof(x);
}


template <typename T>
void Mapa_Memoria<T>::asignar_dato(int ID, int dato) {
    for (int i=0;i<(lista_memoria->length());i++){
        if (lista_memoria->get(i)->getID()==ID){
            (lista_memoria->get(i))->set_dato(dato);

        }
    }
}

template <typename T>
T Mapa_Memoria<T>::obtener_dato(int ID) {
    for (int i=0;i<lista_memoria->length();i++){
        if (lista_memoria->get(i)->getID()==ID){
            return lista_memoria->get(i)->get_dato();
        }
    }
}

template <typename T>
MPointer<T>* Mapa_Memoria<T>::buscar_Mpointer(int ID) {
    for (int i=0;i<lista_memoria->length();i++){
        if (lista_memoria->get(i)->getID()==ID){
            return lista_memoria->get(i);
        }
    }
}


;



