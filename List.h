//
// Created by Michal on 05.12.2018.
//

#ifndef LAB3_LIST_H
#define LAB3_LIST_H

#include <iostream>

using namespace std;

template<class Type>

struct Node {
    struct Node *next;
    Type data;
};

template<class Type>

class List {

    struct Node<Type> *head;

public:
    List<Type>();

    List<Type>(List<Type> &list);

    ~List<Type>();

    void loadList(Type *tabPtr);

    void showList();

    int getNumb(Type sth);

    Type &getData(int shift);

    void pushBack(Type value);

    List<Type> &operator=(List<Type> &source);

    Node<Type> *getHead();


};


template<class Type>
List<Type>::List() {
    head = nullptr;
}

template<class Type>

void List<Type>::loadList(Type *tabPtr) {
    if (head == nullptr) {
        for (int i = 0; tabPtr[i] != '\0'; i++)
            pushBack(tabPtr[i]);
    } else {
        this->~List();
        loadList(tabPtr);
    }
}

template<class Type>
void List<Type>::showList() {
    Node<Type> *showingNode;

    if (head == nullptr)
        cout << "List is empty";

    else {
        showingNode = head;
        do {
            cout << showingNode->data;
            showingNode = showingNode->next;
        } while (showingNode != head);

    }
}

template<class Type>
void List<Type>::pushBack(Type value) {
    Node<Type> *newNode = new Node<Type>;
    newNode->data = value;


    if (head == nullptr) {
        head = newNode;
        newNode->next = newNode;
    } else {
        Node<Type> *tempPtr;
        tempPtr = head->next;
        while (tempPtr->next != head)
            tempPtr = tempPtr->next;
        newNode->next = head;
        tempPtr->next = newNode;

    }
}

template<class Type>
List<Type>::List(List<Type> &source) {

    List<Type> *tempList = new List();
    Node<Type> *tempPtr;
    tempPtr = source.head;

    do {
        tempList->pushBack(tempPtr->data);
        tempPtr = tempPtr->next;
    } while (tempPtr != source.head);

    head = tempList->head;
}

template<class Type>
List<Type> &List<Type>::operator=(List<Type> &source) {

    this->head = nullptr;
    Node<Type> *tempPtr;
    tempPtr = source.head;

    do {
        this->pushBack(tempPtr->data);
        tempPtr = tempPtr->next;
    } while (tempPtr != source.head);

    head = this->head;

    return *this;
}

template<class Type>
List<Type>::~List() {
    Node<Type> *tempPtr = head;
    Node<Type> *tempHead = head;


    while (tempPtr != tempHead) {
        tempPtr = head;
        head = head->next;
        delete tempPtr;
    }
    delete tempPtr;
    head = nullptr;

}

template<class Type>
Node<Type> *List<Type>::getHead() {
    return head;
}

template<class Type>
Type &List<Type>::getData(int shift) {
    Node<Type> *temp = head;
    for (int i = 0; i != shift; i++)
        temp = temp->next;

    return temp->data;
}

template<class Type>
int List<Type>::getNumb(Type sth) {
    Node<Type> *temp = head;
    int counter = 0;
    for (int i = 0; temp->data != sth; i++) {
        temp = temp->next;
        counter++;
    }


    return counter;
}


#endif //LAB3_LIST_H
