//
// Created by Michal on 06.12.2018.
//

#include "Rotor.h"

char Rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char Rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char Rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char Reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";


Rotor::Rotor(int rotorType) {
    loadRotor(rotorType);
}


void Rotor::loadRotor(int rotorType) {
    switch (rotorType) {

        case 1 :
            setOutput(Rotor1);
            break;

        case 2 :
            setOutput(Rotor2);
            break;

        case 3:
            setOutput(Rotor3);
            break;
        case 4:
            setOutput(Reflector);
    }
}

List<char> &Rotor::getOutput() {
    return Output;
}

void Rotor::setOutput(char *tabPtr) {
    Output.loadList(tabPtr);
}

Rotor& Rotor::operator=(Rotor &rotor) {

        Output = rotor.Output;

    return *this;
    }






