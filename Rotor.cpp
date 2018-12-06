//
// Created by Michal on 06.12.2018.
//

#include "Rotor.h"

char Rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char Rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char Rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";


Rotor::Rotor(int rotorType) {
    loadRotor(rotorType);
}


void Rotor::loadRotor(int rotorType) {
    switch (rotorType) {

        case 1 :
            Output.loadList(Rotor1);
            break;

        case 2 :
            Output.loadList(Rotor2);
            break;

        case 3:
            Output.loadList(Rotor3);
            break;
    }
}

List<char> &Rotor::getOutput() {
    return Output;
}

