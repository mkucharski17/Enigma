//
// Created by Michal on 11.12.2018.
//


#include "Plugboard.h"

Plugboard::Plugboard(string &letterPairs) {
    makePlugboard(letterPairs);
}

List<Pair> &Plugboard::getPlugBoardChnages() {
    return plugboardChanges;
}

void Plugboard::makePlugboard(string letterPairs) {
    for (int i = 0; letterPairs[i] != '\0'; i += 2) {
        Pair temp;
        temp.first = letterPairs[i];
        temp.second = letterPairs[i + 1];
        plugboardChanges.pushBack(temp);
    }
}

void Plugboard::switchLetter(char &letter) {
    Node<Pair> *temp = plugboardChanges.getHead();
    do {
        if (letter == temp->data.first)
            letter = temp->data.second;

        else if (letter == temp->data.second)
            letter = temp->data.first;

        temp = temp->next;
    } while (temp != plugboardChanges.getHead());
}

