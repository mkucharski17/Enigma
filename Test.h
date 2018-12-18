//
// Created by Michal on 06.12.2018.
//

#ifndef LAB3_TEST_H
#define LAB3_TEST_H


#include "Enigma.h"

class Test {
    Enigma *E;
    void rotorLoadTest();
    void rotorMoveTest();
    void plugboardSetTest();
    void rotorsSetTest();
    void plugboardSwitchTest();
    void EncytpTest();

public:
    void runTests();


};


#endif //LAB3_TEST_H
