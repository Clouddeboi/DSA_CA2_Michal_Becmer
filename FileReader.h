#pragma once
#include <vector>
#include "BinaryTree.h"
#include "Pair.h"
#include <fstream>  // For ifstream
#include <iostream> // For standard input/output
#include <string>   // For using std::string
#include <sstream>  // For std::stringstream
#include <stdexcept>

using namespace std;

class FileReader {
public:
    //Method to load words from a file into a BinaryTree
    void loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree);

    //Method to find a word by its index (position) in the BinaryTree
    Pair<string, char>& findWordByIndex(int index, BinaryTree<Pair<string, char>>& tree);

    //Method to find all words starting with a given letter
    void findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree);
};
