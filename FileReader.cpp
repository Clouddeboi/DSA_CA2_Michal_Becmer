#include "FileReader.h"

using namespace std;

//Loads words from the specified file into the BinaryTree
void FileReader::loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree) {

    ifstream file(filename);  //Open file to read words
    //Check if file opened successfully
    if (!file.is_open()) 
    {
        cout << "Error opening file: " << filename << endl;//Error message if file can't be opened
        return;
    }

    string word;
    //Read each word from the file
    while (file >> word) 
    {
        if (!word.empty()) 
        {   //Process only non-empty words
            //Create a Pair of word and its first letter
            Pair<string, char> wordPair(word, word[0]);
            tree.add(wordPair);  //Add the word and letter Pair to the tree
        }
    }

    file.close();  //Close the file after reading
}

//Finds and returns the word at the specified index in the tree
Pair<string, char>& FileReader::findWordByIndex(int index, BinaryTree<Pair<string, char>>& tree) {
    try {
        Pair<string, char>* wordArray = tree.toArray();//Convert tree to an array
        if (index < 0 || index >= tree.count())//Check if index is valid 
        {
            throw out_of_range("Index out of range!");//Throw an exception if index is invalid
        }
        return wordArray[index];//Return the word at the specified index
    }
    catch (const exception& e)//Catch any exceptions and print the error message
    {
        cout << "Error: " << e.what() << endl;
        throw;
    }
}

//Finds and prints all words that start with a specific letter corresponding to the index in the tree
void FileReader::findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree) {
    //Check if the provided index (letter) is valid (A-Z)
    if (index < 'A' || index > 'Z') 
    {
        cout << "Invalid index. Please enter a letter between 'A' and 'Z'." << endl;
        return;
    }

    cout << "Words starting with '" << index << "':\n";

    //Traverse the tree and print words starting with the given letter
    tree.traverseInOrder([index](BSTNode<Pair<string, char>>* node) 
        {
        if (node->getItem().getSecond() == index) 
        {  //If the first letter matches the input letter
            cout << node->getItem().getFirst() << endl;//Print the word
        }
        });
}
