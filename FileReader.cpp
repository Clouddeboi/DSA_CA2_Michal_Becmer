#include "FileReader.h"

using namespace std;

void FileReader::loadWordsToTree(const string& filename, BinaryTree<Pair<string, char>>& tree) {
    ifstream file(filename);  //Open file to read words
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;  //Error if file can't be opened
        return;
    }

    string word;
    while (file >> word) {
        if (!word.empty()) {
            //Create a pair of the word and its first letter
            Pair<string, char> wordPair(word, toupper(word[0]));
            tree.add(wordPair);  //Add the pair to the tree
        }
    }

    file.close();  //Close the file after reading
}

void FileReader::findWordsByIndex(char index, BinaryTree<Pair<string, char>>& tree) {
    //Convert index to uppercase to match the keys in the tree
    index = toupper(index);

    //Function to check and print matching words
    auto callback = [&](BSTNode<Pair<string, char>>* node) {
        if (node != nullptr && node->getItem().getSecond() == index) {
            cout << node->getItem().getFirst() << endl;  //Print the word
        }
        };

    tree.traverseInOrder(callback);  //Traverse the tree in order
}
