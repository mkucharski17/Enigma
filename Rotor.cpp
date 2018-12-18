//
// Created by Michal on 06.12.2018.
//

#include "Rotor.h"

char Rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char Rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char Rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char Rotor4[] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
char Rotor5[] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
char Reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";


Rotor::Rotor(int rotorType) {
    loadRotor(rotorType);
}


void Rotor::loadRotor(int rotorType) {
    switch (rotorType) {

        case 1 :
            setCypher(Rotor1);
            break;

        case 2 :
            setCypher(Rotor2);
            break;

        case 3:
            setCypher(Rotor3);
            break;
        case 4:
            setCypher(Rotor4);
            break;
        case 5:
            setCypher(Rotor5);
            break;
        case 6:
            setCypher(Reflector);
            break;

    }
}

List<char> &Rotor::getCypher() {
    return Cypher;
}

void Rotor::setCypher(char *tabPtr) {
    Cypher.loadList(tabPtr);
}

Rotor &Rotor::operator=(Rotor &rotor) {
    Cypher = rotor.Cypher;
    return *this;
}


void Rotor::encrypt(char &letter) {

    letter = Cypher.getData(letter - 65);
}

void Rotor::returnEncrypt(char &letter) {

    letter = (char) (65 + Cypher.getNumb(letter));
}

void Rotor::moveRotor() {
    Cypher.moveHead();
}


