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

    //Method to find RPG characters by the specified field (e.g., element or character class)
    //Searches within the TreeMap based on the index 
    void findCharactersByIndex(const string& key, TreeMap<string, vector<RPGCharacter>>& tree);

    void printCharactersByFieldUsingPrintInOrder(TreeMap<std::string, std::vector<RPGCharacter>>& treeMap, const std::string& keyField);
};
