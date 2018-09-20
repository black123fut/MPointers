#include <iostream>
#include "MPointer.h"

using namespace std;


template <class T>
class DoubleNode{
public:

    DoubleNode(MPointer<int> data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    DoubleNode(){
        data = NULL;
        next = nullptr;
        prev = nullptr;
    }

    MPointer<int> &getData() {
        return data;
    }

    void setData(MPointer<int> data) {
        this->data = data;
    }

    DoubleNode<T> *getPrev() {
        return prev;
    }

    void setPrev(DoubleNode<T> *prev) {
        this->prev = prev;
    }

    void setNext(DoubleNode<T> *next){
        this->next = next;
    }

    DoubleNode<T> *getNext() {
        return next;
    }

private:
    MPointer<int> data;
    DoubleNode<T> *prev;
    DoubleNode<T> *next;
};

class DoubleLinkedList{
public:
    DoubleLinkedList(){
        head = nullptr;
        size = 0;
    }

    void add(MPointer<int> data){
        if (head == nullptr){
            head = new DoubleNode< MPointer<int> >(data);
        } else {
            DoubleNode< MPointer<int> > *tmp = head;

            while (tmp->getNext() != nullptr){
                tmp = tmp->getNext();
            }
            DoubleNode< MPointer<int> > *newNode = new DoubleNode< MPointer<int> >(data);
            tmp->setNext(newNode);
            newNode->setPrev(tmp);
        }
        size++;
    }

    void remove(int i){
        if (i == 0){
            DoubleNode< MPointer<int> > *tmp = head;
            head = head->getNext();
            head->setPrev(nullptr);
            free(tmp);
            size--;
        }
        else {
            DoubleNode< MPointer<int> > *tmp = head;
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

    MPointer<int> get(int i){
        if (i < size){
            DoubleNode< MPointer<int> > *tmp = head;

            for (int j = 0; j < i; ++j) {
                tmp = tmp->getNext();
            }
            return tmp->getData();
        }
    }

    int length(){
        return size;
    }

private:
    DoubleNode< MPointer<int> > *head;
    int size;
};