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

    //Method to load RPG characters from a CSV file into a BinaryTree
    //Uses a key (e.g., element or character_class) for indexing RPGCharacter objects
    void loadCharactersToTree(const string& filename, TreeMap<string, vector<RPGCharacter>>& treeMap, const string& keyField);

};
