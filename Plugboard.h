//
// Created by Michal on 11.12.2018.
//

#ifndef LAB3_PLUGBOARD_H
#define LAB3_PLUGBOARD_H

#include "List.h"

struct Pair {
    char first;
    char second;

};

class Plugboard {
    List<Pair> plugboardChanges;

public:
    Plugboard(string &letterPairs);

    List<Pair> &getPlugBoardChnages();

    void makePlugboard(string source);

    void switchLetter(char &letter);

};


#endif //LAB3_PLUGBOARD_H
