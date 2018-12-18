//
// Created by Michal on 09.12.2018.
//

#include "Enigma.h"

Enigma::Enigma(int *rotorsType, string &plugboardSettings, string &rotorsSettings) {
    for (int i = 0; i < 3; i++) {
        Rotor *newRotor = new Rotor(rotorsType[i]);
        rotors[i] = newRotor;
        counters[i] = 0;
    }

    setRotors(rotorsSettings);
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
    for (int i = 0; order[i] != '\0'; i++) {
        rotate();
        makeEncyrption(order[i]);
    }
}


Plugboard *Enigma::getPlugboard() {
    return plugboard;
}


void Enigma::rotate() {
    counters[0]++;
    rotors[0]->moveRotor();

    if (counters[0] == 26) {
        rotors[1]->moveRotor();
        counters[0] = 0;
        counters[1]++;
    } else if (counters[1] == 26) {
        rotors[2]->moveRotor();
        counters[1] = 0;
        counters[2]++;
    }
}

void Enigma::setRotors(string rotorsSettings) {

    for (int i = 0; i < 3; i++) {
        while (rotors[i]->getCypher().getHead()->data != rotorsSettings[i]) {
            rotors[i]->moveRotor();
        }

    }
}

Rotor *Enigma::getRotor(int number) {
    switch (number) {
        case 0:
            return rotors[0];
        case 1:
            return rotors[1];
        case 2:
            return rotors[2];

    }
}




