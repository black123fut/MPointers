//
// Created by isaac on 19/09/18.
//

#include "MPointer.h"

class DoubleNode{
public:
    DoubleNode(MPointer<int> data){
        this->data = data;
    }

    DoubleNode(){
        next = nullptr;
        prev = nullptr;
    };

    const MPointer<int> &getData() const {
        return data;
    }

    void setData(const MPointer<int> &data) {
        DoubleNode::data = data;
    }

    DoubleNode *getNext() const {
        return next;
    }

    void setNext(DoubleNode *next) {
        DoubleNode::next = next;
    }

    DoubleNode *getPrev() const {
        return prev;
    }

    void setPrev(DoubleNode *prev) {
        DoubleNode::prev = prev;
    }

private:
    MPointer<int> data;
    DoubleNode *next;
    DoubleNode *prev;
};

class DoubleLinkedList{
public:
    DoubleLinkedList(){
        head = nullptr;
    }

    void add(MPointer<int> dato){
        if (head == nullptr){
            head = new DoubleNode(dato);
            size++;
        } else {
            DoubleNode *tmp = head;
            while(tmp->getNext() != nullptr){
                tmp = tmp->getNext();
            }
            DoubleNode *newNode = new DoubleNode(dato);
            tmp->setNext(newNode);
            newNode->setPrev(tmp);
            size++;
        }
    }

    MPointer<int> get(int index){
        if (index < size){
            DoubleNode *tmp = head;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->getNext();
            }
            return tmp->getData();
        }
    }

    int length(){
        return size;
    }

private:
    DoubleNode *head;
    int size;
};