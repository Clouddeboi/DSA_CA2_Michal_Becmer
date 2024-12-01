#include "RPGCharacter.h"

using namespace std;

//Default constructor
//Initializes the RPGCharacter with default values
RPGCharacter::RPGCharacter()
    : id(0), name("Unknown"), element("None"), characterClass("Unknown"), level(0), isLegendary(false) {}

//Parameterized constructor
//Initializes the RPGCharacter with provided values
RPGCharacter::RPGCharacter(int id, string name, string element, string characterClass, int level, bool isLegendary)
    : id(id), name(name), element(element), characterClass(characterClass), level(level), isLegendary(isLegendary) {}

//Comparison operator to enable sorting by name
//Returns true if this character's name is less than the other character's name
bool RPGCharacter::operator<(const RPGCharacter& other) const {
    return this->name < other.name;//Compares characters by name
}

//Equality operator for RPGCharacter
//Returns true if this character's ID is equal to the other character's ID
bool RPGCharacter::operator==(const RPGCharacter& other) const {
    return this->id == other.id;//Compares characters by ID
}

//Display method to print character's information
//Displays the character's ID, name, element, class, level, and legendary status
void RPGCharacter::display() const {
    printf("%-5d %-15s %-10s %-15s %-5d %-10s\n",
        id, name.c_str(), element.c_str(), characterClass.c_str(), level, (isLegendary ? "TRUE" : "FALSE"));//Character Data
}

//Getter methods

//Returns the character's ID
int RPGCharacter::getId() const { return id; }

//Sets the character's ID
void RPGCharacter::setId(int id) { this->id = id; }

//Returns the character's name
string RPGCharacter::getName() const { return name; }

//Sets the character's name
void RPGCharacter::setName(const string& name) { this->name = name; }

//Returns the character's element
string RPGCharacter::getElement() const { return element; }

//Sets the character's element
void RPGCharacter::setElement(const string& element) { this->element = element; }

//Returns the character's class
string RPGCharacter::getCharacterClass() const { return characterClass; }

//Sets the character's class
void RPGCharacter::setCharacterClass(const string& characterClass) { this->characterClass = characterClass; }

//Returns the character's level
int RPGCharacter::getLevel() const { return level; }

//Sets the character's level
void RPGCharacter::setLevel(int level) { this->level = level; }

//Returns whether the character is legendary
bool RPGCharacter::getIsLegendary() const { return isLegendary; }

//Sets the character's legendary status
void RPGCharacter::setIsLegendary(bool isLegendary) { this->isLegendary = isLegendary; }
