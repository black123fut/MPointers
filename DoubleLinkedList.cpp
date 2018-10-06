#include <iostream>
#include "MPointer.h"

using namespace std;


class DoubleNode{
public:
    DoubleNode(const MPointer<int> &data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    DoubleNode(){
        next = nullptr;
        prev = nullptr;
    }

    const MPointer<int> getData() const {
        return data;
    }

    MPointer<int> getData(){
        return data;
    }

    void setData(const MPointer<int> &data) {
        this->data = data;
    }

    DoubleNode *getPrev() {
        return prev;
    }

    void setPrev(DoubleNode *prev) {
        this->prev = prev;
    }

    void setNext(DoubleNode *next){
        this->next = next;
    }

    DoubleNode *getNext() {
        return next;
    }

private:
    MPointer<int> data;
    DoubleNode *prev;
    DoubleNode *next;
};

class DoubleLinkedList{
public:
    /**
     * Constructor.
     */
    DoubleLinkedList(){
        head = nullptr;
        size = 0;
    }

    /**
     * Agrega MPointer a la lista.
     * @param data MPointer para agregar.
     */
    void add(const MPointer<int> &data){
        if (head == nullptr){
            head = new DoubleNode(data);
        } else {
            DoubleNode *tmp = head;

            while (tmp->getNext() != nullptr){
                tmp = tmp->getNext();
            }
            DoubleNode *newNode = new DoubleNode(data);
            tmp->setNext(newNode);
            newNode->setPrev(tmp);
        }
        size++;
    }

    void remove(int i){
        if (i == 0){
            DoubleNode *tmp = head;
            head = head->getNext();
            head->setPrev(nullptr);
            free(tmp);
            size--;
        }
        else {
            DoubleNode *tmp = head;
            int cont = 1;
            while (tmp->getNext() != nullptr){
                if (i == cont){
                    tmp->setNext(tmp->getNext()->getNext());
                    if (tmp->getNext() != nullptr)
                        tmp->getNext()->setPrev(tmp);
                    size--;
                    return;
                } else {
                    cont++;
                    tmp = tmp->getNext();
                }
            }
        }
    }

    DoubleNode * get(int i) const {
        if (i < size){
            DoubleNode *tmp = head;

            for (int j = 0; j < i; ++j) {
                tmp = tmp->getNext();
            }
            return tmp;
        }
    }

    int length(){
        return size;
    }

private:
    DoubleNode *head;
    int size;
};