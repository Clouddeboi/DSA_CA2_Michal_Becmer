#include "FileReader.h"
#include "RPGCharacter.h"
#include <sstream>

using namespace std;

//Method to load words from a file into a BinaryTree
void FileReader::loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree) {
    ifstream file(filename);//Open file to read words
    if (!file.is_open()) 
    {
        cout << "Error opening file: " << filename << endl;//Error if file can't be opened
        return;
    }

    string word;
    while (file >> word) 
    {
        if (!word.empty()) 
        {
            //Create a pair of the word and its first letter
            Pair<string, char> wordPair(word, toupper(word[0]));
            tree.add(wordPair);//Add the pair to the tree
        }
    }

    file.close();//Close the file after reading
}


//Updated method to load RPG characters into TreeMap
void FileReader::loadCharactersToTree(const string& filename, TreeMap<string, vector<RPGCharacter>>& treeMap, const string& keyField) {
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string name, element, characterClass;
        int id, level;
        bool isLegendary;

        //Read values separated by commas
        //Store them in variables and parse them if they aren't strings
        if (getline(ss, line, ',')) { id = stoi(line); }
        if (getline(ss, name, ',')) {}
        if (getline(ss, element, ',')) {}
        if (getline(ss, characterClass, ',')) {}
        if (getline(ss, line, ',')) { level = stoi(line); }
        if (getline(ss, line, ',')) { isLegendary = (line == "TRUE"); }

        RPGCharacter character(id, name, element, characterClass, level, isLegendary);

        //Based on the users input, it sets the key to match the keyField
        string key;
        if (keyField == "element") 
        {
            key = element;
        }
        else if (keyField == "character_class") 
        {
            key = characterClass;
        }
        else if (keyField == "name")
        {
            key = name;
        }
        else if (keyField == "level")
        {
            key = to_string(level);//Converts level to string for the TreeMap key
        }
        else if (keyField == "legendary")
        {
            key = isLegendary ? "TRUE" : "FALSE";//Using "TRUE" or "FALSE" as key
        }
        else 
        {
            //Error if the key doesn't match
            cout << "Invalid key field" << endl;
            return;
        }

        //Using operator[] to insert the character into the TreeMap
        //Adds the character to the vector for the key
        //If the key doesnt exist, it creates a new vector with that key
        treeMap[key].push_back(character);
    }

    file.close();
}

