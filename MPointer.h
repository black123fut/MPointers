#ifndef MPOINTERS_MPOINTER_H
#define MPOINTERS_MPOINTER_H

#include <iostream>
#include "MPointerGC.h"

using namespace std;


template <class T>
class MPointer{
public:
    MPointer();
    MPointer<T> static New();
    void setID(int);

    //Metodos agregados por Gabriel (set_dato y get_dato)
    void set_dato(T dato);
    int get_dato();
    //
    int getID() const;
    T * getData() const;
    void setData(T *);

    T &(operator *());
    T operator &();
    MPointer<T> & operator =(const MPointer<T> &);
    MPointer<T> & operator =(T);
    ~MPointer();

private:
    T *data;
    MPointerGC static *pointerGC;
    int id;
    int Dato;//Este atributo fue agregado por Gabriel
};


#endif //MPOINTERS_MPOINTER_H
