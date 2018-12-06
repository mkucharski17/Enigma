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
    void showList();
    void pushBack(Type value);
};


template<class Type>
List<Type>::List(){
    head = nullptr;
    tail = nullptr;
}

template<class Type>
void List<Type>::showList() {
    Node<Type> *showingNode = new Node<Type>;

    if(head == nullptr && tail == nullptr)
        cout<<"List is empty";

    else {
        showingNode = head;
        do {
            cout << showingNode->data<<endl;
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






#endif //LAB3_LIST_H
