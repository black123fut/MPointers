#include "MPointer.h"
#include "MPointerGC.h"

#include "DataStructures/LinkedList.cpp"


#include <iostream>
#include <pthread.h>
#include <utility>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

/*
 *    MPOINTER
 */

/**
 * Constructor.
 * @tparam T
 */
template<class T>
MPointer<T>::MPointer() {
    data = new int;
}

/**
 * Destructor.
 * @tparam T
 */
template<class T>
MPointer<T>::~MPointer() {
//    delete data
    //Crea mensaje para eliminar MPointer del servidor.
    string message = "{\"opcode\":\"04\", \"serverID\": 0}";

    char* json = new char[message.length() + 1];
    strcpy(json, message.c_str());

    rapidjson::Document doc;
    doc.Parse(json);

    rapidjson::Value& val2 = doc["serverID"];
    val2.SetInt(serverID);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    string foo = buffer.GetString();
    char *json2 = new char[foo.length() + 1];
    strcpy(json2, foo.c_str());

    //Envia el mensaje.
    client->sendMessage(json2);

    //Lee la respuesta del servidor.
    char* answer = client->readMessage();

    rapidjson::Document response;
    response.Parse(answer);

    rapidjson::Value& opcode = response["opcode"];
    rapidjson::Value& msg = response["message"];
    if (msg.GetInt() == 0)
        cout << "Eliminado con exito en el servidor" << endl;
    else
        cout << "";

    pointerGC->setIDPointer(id, -1);
//    cout << "Eliminado" << endl;
}

/**
 * Crea un nuevo MPointer.
 * @tparam T
 * @return Un MPointer.
 */
template<class T>
MPointer<T> MPointer<T>::New() {
    MPointer<T> *tmp = new MPointer<T>();

    //Escribe un mensaje.
    string message = "{\"opcode\":\"00\"}";

    char* json = new char[message.length() + 1];
    strcpy(json, message.c_str());

    //Envia un mensaje al servidor.
    client->sendMessage(json);

    //Lee el mensaje del servidor.
    char *answer = client->readMessage();
    
    cout << "MPointer exitosos" << endl;
    rapidjson::Document doc;
    doc.Parse(answer);

    int serverID1 = -1;
    rapidjson::Value& opt = doc["opcode"];
    if (strcmp(opt.GetString(), "01") == 0){
        rapidjson::Value& val = doc["id"];
        serverID1 = val.GetInt();
    }
    //Agrega el MPointer a la lista.
    pointerGC->addPointer(tmp, serverID1);
    return *tmp;
}

/**
 * Elimina el dato.
 * @tparam T
 */
template<class T>
void MPointer<T>::deleteData() {
    delete data;
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

template <class T>
int MPointer<T>::getServerID() const {
    return serverID;
}

template <class T>
void MPointer<T>::setServerID(int newID) {
    serverID = newID;
}

template<class T>
T &(MPointer<T>::operator *()) {
    return *data;
}

template<class T>
T &MPointer<T>::operator &() {
    return *data;
}

/**
 * Sobreescribe el operador =.
 * @tparam T
 * @param pointer MPointer al cual se iguala.
 * @return Un MPointer.
 */
template<class T>
MPointer<T> &MPointer<T>::operator =(const MPointer<T> &pointer) {
    this->id = pointer.getID();
    this->serverID = pointer.getServerID();

    *data = *pointer.data;

    return *this;
}

/**
 * Sobreescribe el operador =.
 * @tparam T
 * @param pointer Valor al cual se iguala.
 * @return Un MPointer.
 */
template<class T>
MPointer<T> & MPointer<T>::operator =(const T &pointer) {
    *data = pointer;

    //Escribre el mensaje.
    string message = "{\"opcode\":\"02\", \"data\":0, \"serverID\": 0}";
    char *json = new char[message.length() + 1];
    strcpy(json, message.c_str());

    rapidjson::Document doc;
    doc.Parse(json);

    rapidjson::Value& val = doc["data"];
    val.SetInt(pointer);

    rapidjson::Value& val2 = doc["serverID"];
    val2.SetInt(serverID);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    string foo = buffer.GetString();
    char *json2 = new char[foo.length() + 1];
    strcpy(json2, foo.c_str());

    //Envia el mensaje al servidor.
    client->sendMessage(json2);

    //Lee la respuesta del servidor.
    char* answer = client->readMessage();
    rapidjson::Document response;
    response.Parse(answer);

    rapidjson::Value& opcode = response["opcode"];
    if (strcmp(opcode.GetString(), "03") == 0)
        cout << "Guardado con exito en el servidor" << endl;
    return *this;
}

template<class T>
MPointerGC *MPointer<T>::pointerGC = MPointerGC::Singleton();

template <class T>
Client *MPointer<T>::client = Client::getClient();

template class MPointer<int>;

/*
 *     MPOINTERGC
 */

MPointerGC *MPointerGC::pointerGC = nullptr;
LinkedList< MPointer<int> * > *MPointerGC::pointerList = nullptr;
/**
 * Constructor.
 */
MPointerGC::MPointerGC() {
}

/**
 * Agrega MPointer a la lista.
 * @param pointer MPointer que se agrega a la lista.
 * @param serverID ID del servidor.
 */
void MPointerGC::addPointer(MPointer<int> *pointer, int serverID) {
    if (pointerList == nullptr){
        pointerList = new LinkedList< MPointer<int> * >;
    }
    pointer->setID(IDs);
    pointer->setServerID(serverID);
    IDs++;

    pointerList->add(pointer);

    //Inicia el thread.
    if (IDs == 1){
        pthread_t t1;
        pthread_create(&t1, NULL, &MPointerGC::garbageCollector, this);
    }
}

/**
 * Obtiene un MPointer de la lista.
 * @param id ID del MPointer.
 * @return Un MPointer.
 */
MPointer<int> MPointerGC::getPointer(int id) {
    for (int i = 0; i < pointerList->length(); ++i) {
        if (pointerList->get(i)->getID() == id){
            return *pointerList->get(i);
        }
    }
}

/**
 * Modifica el valor de la ID de un MPointer en la lista.
 * @param id ID del MPointer en la lista.
 * @param elex Nuevo ID del MPointer.
 */
void MPointerGC::setIDPointer(int id, int elex) {
    for (int i = 0; i < pointerList->length(); ++i) {
        if (pointerList->get(i)->getID() == id){
            pointerList->get(i)->setID(elex);
        }
    }
}


void MPointerGC::setServerIDPointer(int serverId) {
    for (int i = 0; i < pointerList->length(); ++i) {
        if (pointerList->get(i)->getServerID() == serverId){
            pointerList->get(i)->setServerID(-1);
        }
    }
}

/**
 * Loop que busca eliminar de la lista los MPointer que ya fueron eliminados.
 * @param ptr MPointerGC.
 * @return None.
 */
void* MPointerGC::garbageCollector(void *ptr) {
    while (true){
        if (pointerList->length() > 0){
            for (int i = 0; i < pointerList->length(); ++i) {
                if (pointerList->get(i)->getID() == -1){
                    cout << "Garbage Collector" << endl;
                    pointerList->get(i)->deleteData();
                    pointerList->remove(i);
                }
            }
        }
        sleep(0.1);
    }
}

/**
 * Remueve MPointer de la lista.
 * @param id ID del puntero a eliminar.
 */
void MPointerGC::removePointer(int id) {
    for (int i = 0; i < pointerList->length(); ++i) {
        if (pointerList->get(i)->getID() == id){
            pointerList->remove(i);
        }
    }
}

/**
 * Obtiene el MPointerGC.
 * @return El MPointerGC.
 */
MPointerGC *MPointerGC::Singleton() {
    if (pointerGC == nullptr){
        pointerGC = new MPointerGC;
    }
    return pointerGC;
}

