#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class FileReader {
public:
    //Method to read words from the file and return them as a vector of strings
    vector<string> readWordsFromFile(const string& filename);
};