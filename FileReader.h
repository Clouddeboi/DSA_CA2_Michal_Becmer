#pragma once
#include <string>
#include "BinaryTree.h"
#include "Pair.h"
#include <fstream>
#include <iostream>
#include <cctype>//For toupper

using namespace std;

class FileReader {
public:
    //Method to load words from a file into a BinaryTree
    void loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree);

    //Method to find words by their first letter in the tree
    void findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree);
};
