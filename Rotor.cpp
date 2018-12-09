//
// Created by Michal on 06.12.2018.
//

#include "Rotor.h"

char Rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
char Rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
char Rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
char Reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";


Rotor::Rotor(int rotorType) {
    this->loadRotor(rotorType);
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
            setCypher(Reflector);
    }
}

List<char> &Rotor::getCypher() {
    return Cypher;
}

void Rotor::setCypher(char *tabPtr) {
    Cypher.loadList(tabPtr);
}

Rotor& Rotor::operator=(Rotor &rotor) {
        Cypher = rotor.Cypher;
    return *this;
}

Rotor::Rotor(Rotor &source) {
    Cypher = source.Cypher;
}

void Rotor::encrypt(char &letter) {

    letter = Cypher.getData(letter - 65);
}

void Rotor::returnEncrypt(char &letter) {

    letter = (char)(65+Cypher.getNumb(letter));
}






