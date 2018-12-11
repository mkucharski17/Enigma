//
// Created by Michal on 09.12.2018.
//

#include "Enigma.h"

Enigma::Enigma(int *rotorsType, string plugboardSettings) {
    for (int i = 0; i < 3; i++) {
        Rotor *newRotor = new Rotor(rotorsType[i]);
        rotors[i] = newRotor;
    }
    reflector = new Rotor(6);

    plugboard = new Plugboard(plugboardSettings);

}

void Enigma::makeEncyrption(char &letter) {
    plugboard->switchLetter(letter);

    for (int i = 0; i < 3; i++)
        rotors[i]->encrypt(letter);

    reflector->encrypt(letter);

    for (int i = 2; i >= 0; i--)
        rotors[i]->returnEncrypt(letter);

    plugboard->switchLetter(letter);
}

void Enigma::go(string &order) {
    for (int i = 0; order[i] != '\0'; i++)
        makeEncyrption(order[i]);
}


Plugboard* Enigma::getPlugboard() {
    return plugboard;
}

