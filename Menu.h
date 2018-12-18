//
// Created by Michal on 17.12.2018.
//

#ifndef LAB3_MENU_H
#define LAB3_MENU_H


#include "Enigma.h"
#include "Test.h"

class Menu {
    Enigma *enigma;
    Enigma *decryptingEnigma;
    Test *test;
    string order;
    bool alreadyUse = false;

public:
    Menu();
    void enryptMenu();
    void getInformation();
    void getOrder();
    void save();
    void load();


};


#endif //LAB3_MENU_H
