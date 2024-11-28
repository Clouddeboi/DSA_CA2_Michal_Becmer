#pragma once
#include <string>
#include <iostream>
//https://mockaroo.com/
using namespace std;

class RPGCharacter {
public:
    int id;          //Character ID
    string name;     //Character name
    string element;  //Character's element (this will be something like water, fire, etc.)
    int hp;          //Character's Health stat
    int attack;      //Character's attack stat
    int defense;     //Character's defensive stat

    //Default constructor
    RPGCharacter()
        : id(0), name("Unknown"), element("None"), hp(0), attack(0), defense(0) {}

    //Constructor to initialize an RPGCharacter object
    RPGCharacter(int id, string name, string element, int hp, int attack, int defense)
        : id(id), name(name), element(element), hp(hp), attack(attack), defense(defense) {}

    bool operator<(const RPGCharacter& other) const {
        return this->name < other.name;  //Compares the characters by name
    }

    //Equality operator for RPGCharacter, this is needed because of how BSTNode is coded
    bool operator==(const RPGCharacter& other) const {
        return this->id == other.id;  //Allows us to use == to compare character IDs
    }

    //Display method to print character's info
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Element: " << element
            << ", HP: " << hp << ", Attack: " << attack << ", Defense: " << defense << endl;
    }
};
