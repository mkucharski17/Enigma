//
// Created by Michal on 17.12.2018.
//

#include "Menu.h"
#include <iostream>
#include <fstream>

using namespace std;

Menu::Menu() {
    int choice = 1;
    cout << "WELCOME IN ENIGMA SIMULATOR "<<endl;
    while (choice != 0) {
        cout<< endl << "Choose one from following options: " << endl << "Run tests - 1" << endl << "Encrypt text- 2"<<endl
             << "Exit - 0 ";
        cin >> choice;

        switch (choice) {

            case 1 :
                test = new Test();
                test->runTests();
                break;

            case 2:
                enryptMenu();
                break;

            case 3:
                choice = 0;
        }
    }
}

void Menu::enryptMenu() {
    int choice = 1;
    getInformation();
    getOrder();
    while (choice != 0) {

        cout << endl << "Choose, what do you want to do now: " << endl << "Encrypt - 1" << endl;

        if (encrypted)
            cout << "Decrypt - 2 " << endl;

        cout << "Show text - 3" << endl << "Save text - 4" << endl << "Exit - 0";
        cin >> choice;

        switch (choice) {

            case 1 :
                enigma->go(order);
                encrypted = true;
                break;

            case 2:
                decryptingEnigma->go(order);
                encrypted = false;
                break;

            case 3:
                cout << order;
                break;

            case 4:
                save();
                break;

            case 0:
                choice = 0;

        }
    }

}

void Menu::getInformation() {

    string rotorsSettings, plugboardSettings;
    int rotorsTypes[3];

    cout << "Type three rotors (1-5) which you want to use in your Enigma: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "rotor " << i + 1 << ": ";
        cin >> rotorsTypes[i];
    }
    cout << "Type pairs of letters which you want to exchange in plugboard. For example ABCD means A and B is one pair "
         << "and C and D is another pair: ";
    cin >> plugboardSettings;

    cout << "Write how you want to set rotors at the beginning, sequence of rotors is like when choosing types ";
    cin >> rotorsSettings;


    enigma = new Enigma(rotorsTypes, plugboardSettings, rotorsSettings);
    decryptingEnigma = new Enigma(rotorsTypes, plugboardSettings, rotorsSettings);

}

void Menu::getOrder() {
    int choice;
    cout << "Write text to encrypt - 1" << endl << "Read text to encrypt from file - 2";
    cin >> choice;
    if (choice == 1) {
        cout << "Type words which you want to encrypt,use only capital letters and  use X instead of space button: ";
        cin >> order;
    } else {
        load();
    }
}

void Menu::save() {
    fstream file;
    file.open("save.txt", ios::out);
    file << order << endl;
    file.close();
}

void Menu::load() {
    string fileName;
    cout << "Write name of file which you want to load from: ";
    cin >> fileName;
    fstream file;
    file.open(fileName, ios::in);
    file >> order;
    file.close();
}