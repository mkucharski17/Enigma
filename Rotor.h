//
// Created by Michal on 06.12.2018.
//

#ifndef LAB3_ROTOR_H
#define LAB3_ROTOR_H


#include "List.h"

class Rotor {
    List<char> Output;

public:
    Rotor(int rotorType = 1);
    void loadRotor(int rotorType);

    List<char> &getOutput();
    void setOutput(char* tabPtr);
    Rotor& operator=(Rotor &rotor);

};


#endif //LAB3_ROTOR_H
//"EKMFLGDQVZNTOWYHXUSPAIBRCJ" rotor 1
//"AJDKSIRUXBLHWTMCQGZNPYFVOE" rotor 2
//"BDFHJLCPRTXVZNYEIWGAKMUSQO" rotor 3