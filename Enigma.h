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


public:

    Enigma(int *tabPtr, string plugboardSettings);

    void makeEncyrption(char &letter);

    void go(string &order);

    Plugboard* getPlugboard();


};


#endif //LAB3_ENIGMA_H
