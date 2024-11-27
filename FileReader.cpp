#include "FileReader.h"

vector<string> FileReader::readWordsFromFile(const string& filename) {
    vector<string> words; //Vector to store words
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "Unable to open the file!" << endl;
        return words; //Return an empty vector if error occurs
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word); //Add word to the vector
        }
    }

    file.close();
    return words;
}

void FileReader::loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree) {
    vector<string> words = readWordsFromFile(filename);  // Get the words from the file

    for (const string& word : words) {
        char firstLetter = word[0];  // Use the first letter of the word
        Pair<string, char> pair(word, firstLetter);  // Pair the word with the first letter
        tree.add(pair);  // Add each word to the BinaryTree
    }
}

