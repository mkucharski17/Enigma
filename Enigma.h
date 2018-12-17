//
// Created by Michal on 09.12.2018.
//

#ifndef LAB3_ENIGMA_H
#define LAB3_ENIGMA_H


#include "Rotor.h"
#include "Plugboard.h"


class Enigma {
    Rotor *rotors[3];
    Rotor *reflector;
    Plugboard *plugboard;
    int counters[3];


public:

    Enigma(int *tabPtr, string &plugboardSettings, string &rotorsSettings);

    void makeEncyrption(char &letter);

    void go(string &order);

    Plugboard *getPlugboard();

    void rotate();

    void setRotors(string rotorsSettings);


};


#endif //LAB3_ENIGMA_H
