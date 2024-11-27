#include "FileReader.h"

vector<string> FileReader::readWordsFromFile(const string& filename) {
    vector<string> words;//vector for strings
    ifstream file(filename);
    string line;

    if (!file.is_open()) 
    {
        cout << "Unable to open the file!" << endl;
        return words; //Return an empty vector in case of error
    }

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string word;
        while (ss >> word) 
        {
            words.push_back(word);
        }
    }

    file.close();
    return words;
}
