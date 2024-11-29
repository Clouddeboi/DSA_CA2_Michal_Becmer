#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "TreeMap.h"
#include "RPGCharacter.h"

using namespace std;

class FileReader {
public:
    //Method to load words from a file into a BinaryTree
    //The tree will store Pair objects with string keys and char values
    void loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree);

    //Method to find words by their first letter in the tree
    //Takes a char index and searches for words starting with that letter
    void findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree);

    //Method to load RPG characters from a CSV file into a BinaryTree
    //Uses a key (e.g., element or character_class) for indexing RPGCharacter objects
    void loadCharactersToTree(const string& filename, TreeMap<string, vector<RPGCharacter>>& treeMap, const string& keyField);

    //Method to find RPG characters by the first letter of the specified field (e.g., element or character class)
    //Searches within the TreeMap based on the index letter
    void findCharactersByIndex(char index, TreeMap<string, vector<RPGCharacter>>& tree);

    //Method to view all RPG characters from the CSV file
    //Displays all the characters stored in the TreeMap
    void viewAllCharacters(const TreeMap<string, vector<RPGCharacter>>& tree);
};
