//
// Created by Michal on 06.12.2018.
//

#include "Test.h"
#include "Rotor.h"

void Test::runTests() {
    plugboardSetTest();
    rotorsSetTest();
    rotorMoveTest();
    rotorLoadTest();
    plugboardSwitchTest();
    EncytpTest();

}

void Test::rotorLoadTest() {
    char Rotor4[] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    Rotor *r = new Rotor(4);
    Node<char> *temp = r->getCypher().getHead();

    for (int i = 0; temp->next != r->getCypher().getHead(); i++) {
        if (temp->data == Rotor4[i])
            temp = temp->next;
        else {
            cout << "something goes wrong in rotor's loading" << endl;
            break;
        }
    }
    cout << "rotor's loading is ok" << endl;
}


void Test::rotorMoveTest() {

    char Rotor5[] = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    Rotor *r = new Rotor(5);

    for (int i = 0; r->getCypher().getHead()->next->data != 'E'; i++) {
        if (r->getCypher().getHead()->data == Rotor5[i])
            r->moveRotor();
        else {
            cout << "something goes wrong in rotor's Moving" << endl;
            break;
        }
    }
    cout << "rotor's Moving is ok" << endl;
}

void Test::plugboardSetTest() {
    int rotorsType[] = {1, 2, 3};
    string plug = "SZEWTGHP";
    string rotorsSettings = "ELA";
    E = new Enigma(rotorsType, plug, rotorsSettings);
    Node<Pair> *temp = E->getPlugboard()->getPlugBoardChnages().getHead();

    for (int i = 0; plug[i] != '\0'; i += 2) {
        if (temp->data.first == plug[i] && temp->data.second == plug[i + 1])
            temp = temp->next;
        else {
            cout << "something goes wrong in setting plugboard" << endl;
        }

    }

    cout << "plugboard setting is ok" << endl;
}

void Test::rotorsSetTest() {
    string rotorsSettings = "ELA";
    Rotor *tempRotors[3];
    for (int i = 0; i < 3; i++)
        tempRotors[i] = E->getRotor(i);

    for (int i = 0; i < 3; i++) {
        if (tempRotors[i]->getCypher().getHead()->data == rotorsSettings[i])
            continue;
        else {
            cout << "something goes wrong in setting rotors" << endl;
        }
    }
    cout << "rotors' setting is ok" << endl;
}

void Test::plugboardSwitchTest() {
    string example = "SWITCHINGXXTEST";
    for (int i = 0; example[i] != '\0'; i++) {
        E->getPlugboard()->switchLetter(example[i]);
    }
    if (example == "ZEIGCPINTXXGWZG")
        cout << "plugboard switching is ok" << endl;
    else {
        cout << "something goes wrong in switching letters with plugboard" << endl;
    }
}

void Test::EncytpTest() {
    int rotorsType[] = {1, 2, 3};
    string plug = "SZEWTGHP";
    string rotorsSettings = "ELA";
    string example = "ENCRYTINGXTEST";
    Enigma *check = new Enigma(rotorsType, plug, rotorsSettings);

    E->go(example);
    check->go(example);

    if (example == "ENCRYTINGXTEST")
        cout << "encytping and decrypting is ok" << endl;
    else {
        cout << "something goes wrong in encrypting or decrypting " << endl;
    }

}

