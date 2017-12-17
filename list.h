#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
class List {
protected:
    Node<T>* begin;
    Node<T>* end;
    int elementsQuantity = 0;

public:
    List()
        : begin(nullptr)
        , end(nullptr)
    {
    }

    ~List()
    {
        delete begin;
        delete end;
    }

    void add(T value)
    {
//        if (this->exists(value)) {
//            return;
//        }

        Node<T>* newNode = new Node<T>(value);

        if (begin == nullptr) {
            Node<T>* newNode = new Node<T>(value);
            this->begin = newNode;
            this->end = newNode;
        } else {
            this->insert(value, this->elementsQuantity);
        }

        this->end = newNode;

        this->elementsQuantity++;
    }

    bool exists(T value)
    {
        if (this->find(value) == -1) {
            return false;
        }

        return true;
    }

    int find(T value)
    {
        Node<T>* currentNode = this->begin;

        for (int i = 0; i < this->elementsQuantity; i++) {
            if (currentNode->getValue() == value) {
                return i;
            }

            currentNode = currentNode->getNext();
        }

        return -1;
    }

    void insert(T value, int position)
    {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* currentNode = begin;

        if (position == 0) {
            newNode->setNext(begin);
            begin = newNode;
        } else {
            for (int i = 0; i < position - 1; i++) {
                currentNode = currentNode->getNext();
                if (currentNode == nullptr)
                    return;
            }

            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
        }

        this->elementsQuantity++;
    }

    int getSize()
    {
        return this->elementsQuantity;
    }

    T get(int indice)
    {
        int i = 0;
        Node<T>* currentNode = begin;
        while (i < indice) {
            i++;
            currentNode = currentNode->getNext();
        }
        return currentNode->getValue();
    }
    Node<T>*& getNode(int index)
    {
        int i = 0;
        Node<T>* currentNode = begin;
        while (i < index) {
            i++;
            currentNode = currentNode->getNext();
        }
        return currentNode;
    }

    T operator[](int index)
    {
        return this->get(index);
    }

    void remove(int index)
    {
        Node<T>* node = this->getNode(index);
        node->getPrevious()->setNext(node->getNext());
        delete node;
        this->elementsQuantity--;
    }

    List* concatenate(List list)
    {
        List* tempList = list.clone();
        for (int i = 0; i < this->lementsQuantity; ++i) {
            tempList.add(this->elements[i]);
        }

        return list;
    }

    List* clone()
    {
        List* tempList = new List();
        Node<T>* currentNode = this->begin;

        for (int i = 0; i < this->elementsQuantity; ++i) {
            tempList->add(currentNode->getValue());
            currentNode = currentNode->getNext();
        }

        return tempList;
    }

    List* sublist(int start, int quantity)
    {
        List tempList = new List();
        int end = quantity = start + 1;
        Node<T>* currentNode = this->begin;

        for (int i = 0; i < end; ++i) {
            tempList->Add(currentNode->getValue());
            currentNode = currentNode->getNext();
        }

        for (int i = 0; i < end; ++i) {
            this->remove(i);
        }

        return tempList;
    }

    T getBack()
    {
        return this->end->getValue();
    }

    void popBack()
    {
        Node<T>* tempNode = this->end;

        this->end = tempNode->getPrevious();
        delete tempNode;
        this->elementsQuantity--;
    }
};

#endif
