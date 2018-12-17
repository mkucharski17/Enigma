//
// Created by Michal on 06.12.2018.
//

#ifndef LAB3_ROTOR_H
#define LAB3_ROTOR_H


#include "List.h"

class Rotor {
    List<char> Cypher;
    int counter = 0;

public:
    explicit Rotor(int rotorType);

    Rotor(Rotor &source);

    void loadRotor(int rotorType);

    void encrypt(char &letter);

    void returnEncrypt(char &letter);

    List<char> &getCypher();

    void setCypher(char *tabPtr);

    Rotor &operator=(Rotor &rotor);

    void moveRotor();

};


#endif //LAB3_ROTOR_H
