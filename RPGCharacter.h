#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio> 
#include "BinaryTree.h"
#include "Pair.h"
#include "TreeMap.h"

using namespace std;

class RPGCharacter {
private:
    int id;//Character ID
    string name;//Character name
    string element;//Character's element
    string characterClass;//Character's class
    int level;//Character's level
    bool isLegendary;//Legendary check

public:
    //Default constructor
    //Initializes the RPGCharacter with default values
    RPGCharacter();

    //Parameterized constructor
    //Initializes the RPGCharacter with provided values
    RPGCharacter(int id, string name, string element, string characterClass, int level, bool isLegendary);

    //Comparison operator to enable sorting by name
    //Returns true if this character's name is less than the other character's name
    bool operator<(const RPGCharacter& other) const;

    //Equality operator for RPGCharacter
    //Returns true if this character's ID is equal to the other character's ID
    bool operator==(const RPGCharacter& other) const;

    //Display method to print character's information
    //Displays the character's ID, name, element, class, level, and legendary status
    void display() const;

    //Getters and Setters for member variables
    int getId() const;//Returns the character's ID
    void setId(int id);//Sets the character's ID

    string getName() const;//Returns the character's name
    void setName(const string& name);//Sets the character's name

    string getElement() const;//Returns the character's element
    void setElement(const string& element);//Sets the character's element

    string getCharacterClass() const;//Returns the character's class
    void setCharacterClass(const string& characterClass);//Sets the character's class

    int getLevel() const;//Returns the character's level
    void setLevel(int level);//Sets the character's level

    bool getIsLegendary() const;//Returns whether the character is legendary
    void setIsLegendary(bool isLegendary);//Sets the character's legendary status

    friend ostream& operator<<(ostream& out, const RPGCharacter& character) {
        printf("| %-15s | %-20s | %-15s | %-20s | %-15s | %-10s |\n",
            to_string(character.id).c_str(),
            character.name.c_str(),
            character.element.c_str(),
            character.characterClass.c_str(),
            to_string(character.level).c_str(),
            character.isLegendary ? "TRUE" : "FALSE");

        return out;
    }
};

// Add this to RPGCharacter.h, outside the RPGCharacter class
inline ostream& operator<<(ostream& out, const vector<RPGCharacter>& characters) {
    for (const auto& character : characters) {
        out << character << ", "; // Print each RPGCharacter followed by a comma
    }
    return out;
}



