#pragma once
#include <string>
#include <iostream> 

using namespace std;

class RPGCharacter {
public:
    string name;    //Character name
    string element; //Characters element (this will be something like water, fire etc.)
    int hp;         //Characters Health stat
    int attack;     //Characters attack stat
    int defense;    //Characters defensive stat

    //Constructor to initialize an RPGCharacter object
    RPGCharacter(string name, string element, int hp, int attack, int defense)
        : name(name), element(element), hp(hp), attack(attack), defense(defense) {}

    //Display method to print character's info
    void display() {
        cout << "Name: " << name << ", Element: " << element
            << ", HP: " << hp << ", Attack: " << attack << ", Defense: " << defense << endl;
    }
};

