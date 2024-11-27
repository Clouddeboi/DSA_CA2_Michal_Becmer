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
    vector<string> readWordsFromFile(const string& filename) {
        vector<string> words;
        ifstream file(filename);
        string line;

        if (!file.is_open()) 
        {
            cout << "Unable to open the file!" << endl;
            return words; //Return an empty vector in case of an error
        }
        //Reads from line to line
        while (getline(file, line)) 
        {
            stringstream ss(line);
            string word;
            while (ss >> word) 
            {
                words.push_back(word);
            }
        }
        //close file
        file.close();
        return words;
    }
};