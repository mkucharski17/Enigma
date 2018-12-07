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

    struct Node<Type> *head, *tail;

public:
    List<Type>();
    void loadList(Type* tabPtr);
    void showList();
    void pushBack(Type value);
    List<Type>(List<Type> &list);
};


template<class Type>
List<Type>::List(){
    head = nullptr;
    tail = nullptr;
}

template<class Type>

void List<Type>::loadList(Type* tabPtr) {
    for(int i = 0 ; tabPtr[i] != '\0'; i++)
        pushBack(tabPtr[i]);


}

template<class Type>
void List<Type>::showList() {
    Node<Type> *showingNode;

    if(head == nullptr && tail == nullptr)
        cout<<"List is empty";

    else {
        showingNode = head;
        do {
            cout << showingNode->data;
            showingNode = showingNode->next;
        } while (showingNode != tail->next);

    }
}

template<class Type>
void List<Type>::pushBack(Type value) {
    Node<Type> *newNode = new Node<Type>;
    newNode->data = value;


    if(tail==nullptr && head== nullptr){
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    }

    else{
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

template <class Type>
List<Type>::List(List<Type> &source) {

List<Type> *tempList = new List();
Node<Type> *tempPtr;
tempPtr = source.head;

do{
    tempList->pushBack(tempPtr->data);
    tempPtr = tempPtr->next;
}while(tempPtr != source.tail->next);

head = tempList->head;
tail = tempList->tail;






}





#endif //LAB3_LIST_H
