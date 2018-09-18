#include "MPointer.h"
#include "MPointerGC.h"
#include "Mapa_Memoria.h"
#include <iostream>
#include "Mapa_Memoria.cpp"

using namespace std;

int main() {

    int contador_direcciones=0;
    int IDs=0;


    MPointer<int> pointer1 = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();
    pointer1 = 7;

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