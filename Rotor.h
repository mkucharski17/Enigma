//
// Created by Michal on 06.12.2018.
//

#ifndef LAB3_ROTOR_H
#define LAB3_ROTOR_H


#include "List.h"

class Rotor {
    List<char> Cypher;

public:
    Rotor(int rotorType);
    Rotor(Rotor &source);
    void loadRotor(int rotorType);
    void encrypt(char &letter);
    void returnEncrypt(char &letter);

    List<char> &getCypher();
    void setCypher(char* tabPtr);
    Rotor& operator=(Rotor &rotor);

};


#endif //LAB3_ROTOR_H
