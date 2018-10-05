#ifndef MPOINTERS_MPOINTER_H
#define MPOINTERS_MPOINTER_H

#include <iostream>
#include "MPointerGC.h"
#include "Server/Client.h"

using namespace std;


template <class T>
class MPointer{
public:
    MPointer();
    MPointer<T> static New();

    //Metodos agregados por Gabriel (set_dato y get_dato)
    void set_dato(T);
    int get_dato();

    MPointer<T> *getPointer();
    int getID() const;
    void setID(int);
    T * getData() const;
    void setData(T *);
    int getServerID() const;
    void setServerID(int);
    void deleteData();

    T &(operator *());
    T &operator &();
    MPointer<T> & operator =(const MPointer<T> &);
    MPointer<T> & operator =(const T &);
    ~MPointer();

private:
    T *data;
    MPointerGC static *pointerGC;
    Client static *client;
    int serverID;
    int id;
    int Dato;//Este atributo fue agregado por Gabriel
    bool on;
};


#endif //MPOINTERS_MPOINTER_H
