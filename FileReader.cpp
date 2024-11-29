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

//Method to find words by their first letter in the tree
void FileReader::findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree) {
    index = toupper(index);//Ensure the index is uppercase

    //Callback function to print matching words
    auto callback = [&](BSTNode<Pair<string, char>>* node) 
        {
            if (node != nullptr && node->getItem().getSecond() == index) 
            {
                cout << node->getItem().getFirst() << endl;//Print the word
            }
        };

    tree.traverseInOrder(callback);//Traverse the tree in order
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
        if (getline(ss, line, ',')) { id = stoi(line); }
        if (getline(ss, name, ',')) {}
        if (getline(ss, element, ',')) {}
        if (getline(ss, characterClass, ',')) {}
        if (getline(ss, line, ',')) { level = stoi(line); }
        if (getline(ss, line, ',')) { isLegendary = (line == "TRUE"); }

        RPGCharacter character(id, name, element, characterClass, level, isLegendary);

        string key;
        if (keyField == "element") 
        {
            key = element;
        }
        else if (keyField == "character_class") 
        {
            key = characterClass;
        }
        else 
        {
            cout << "Invalid key field" << endl;
            return;
        }

        //Using operator[] to insert the character into the TreeMap
        treeMap[key].push_back(character);//Adds the character to the vector for the key
    }

    file.close();
}

//Method to find RPG characters by the first letter of the specified field (e.g., element or character class)
void FileReader::findCharactersByIndex(char index, TreeMap<string, vector<RPGCharacter>>& tree) {
    index = toupper(index);//Convert index to uppercase to match the keys in the tree

    //Function to check and print matching characters
    auto callback = [&](BSTNode<Pair<string, vector<RPGCharacter>>>* node) 
        {
            if (node != nullptr) 
            {
                //Search for characters within the vector whose field starts with the specified index
                for (const auto& character : node->getItem().getSecond()) 
                {
                    if (toupper(character.getElement()[0]) == index || toupper(character.getCharacterClass()[0]) == index) 
                    {
                        character.display();//Display character's information
                    }
                }
            }
        };

    tree.traverseInOrder(callback);//Traverse the TreeMap in order
}

//Method to view all RPG characters from the TreeMap
void FileReader::viewAllCharacters(const TreeMap<string, vector<RPGCharacter>>& tree) {
    //Function to display all RPG characters in the TreeMap
    auto callback = [&](BSTNode<Pair<string, vector<RPGCharacter>>>* node) 
        {
            if (node != nullptr) 
            {
                //Iterate through each vector of characters
                for (const auto& character : node->getItem().getSecond()) 
                {
                    character.display();//Display each character's information
                }
            }
        };

    tree.traverseInOrder(callback);//Traverse the TreeMap in order and display each character
}
