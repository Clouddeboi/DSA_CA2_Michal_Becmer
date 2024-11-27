#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "BinaryTree.h"
#include "Pair.h"

using namespace std;

class FileReader {
public:
    // Method to read words from a file
    static vector<string> readWordsFromFile(const string& filename);

    // Method to load words into the binary tree with the first letter as the key
    static void loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree);
};
