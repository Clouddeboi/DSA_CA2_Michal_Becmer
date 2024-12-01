#include <iostream>
#include "BinaryTree.h"
#include "Pair.h"
#include "FileReader.h"
#include "TreeMap.h"
#include "RPGCharacter.h"

using namespace std;

//Function to print the menu options
void printMenu() {
    cout << "\nMENU";
    cout << "\nStage 2\n";
    cout << "-----------------------------------------------\n";
    cout << "1. Load words from file and populate the tree\n";
    cout << "2. Print In-order Traversal (BinaryTree)\n";
    cout << "3. Print Pre-order Traversal (BinaryTree)\n";
    cout << "4. Print Post-order Traversal (BinaryTree)\n";
    cout << "5. Check size of the tree\n";
    cout << "6. Clear the tree\n";
    cout << "7. Find words by index (first letter)\n";
    cout << "\nStage 4\n";
    cout << "-----------------------------------------------\n";
    cout << "8. Load RPG characters into TreeMap\n";
    cout << "9. In-order Traversal (TreeMap)\n";
    cout << "10. Print all RPG characters\n";
    cout << "11. Clear RPG characters from treemap\n";
    cout << "12. Print characters in order\n";
    cout << "99. Exit\n";
}

int main() {
    BinaryTree<Pair<string, char>> tree;//Create a BinaryTree for storing words and their first letters

    TreeMap<string, vector<RPGCharacter>> treeMap;//Create a TreeMap for storing RPGCharacter by key

    FileReader fileReader;//FileReader object to load words from file

    bool treeLoaded = false;//Flag to check if words are loaded into the tree
    bool charactersLoaded = false;//Flag to check if characters are loaded into the TreeMap

    int choice;
    string filename = "RandomWords.txt";//The file containing words
    string characterFile = "Random_Character_Data.csv";//File containing RPG characters

    while (true) {
        printMenu();//Display the menu
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            //Load words from file into the tree (BST)
            fileReader.loadWordsToTree(filename, tree);
            treeLoaded = true;
            cout << "Words loaded successfully into the tree.\n";
            break;
        case 2:
            if (treeLoaded) 
            {
                cout << "In-order Traversal:\n";
                tree.printInOrder();//Print the tree in-order (sorted by first letter)
            }
            else 
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        case 3:
            if (treeLoaded) 
            {
                cout << "Pre-order Traversal:\n";
                tree.printPreOrder();//Print the tree in pre-order
            }
            else 
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        case 4:
            if (treeLoaded) 
            {
                cout << "Post-order Traversal:\n";
                tree.printPostOrder();//Print the tree in post-order
            }
            else 
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        case 5:
            if (treeLoaded) 
            {
                cout << "Size of the tree: " << tree.count() << endl;//Print the size of the tree
            }
            else 
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        case 6:
            //Clear the tree
            tree.clear();
            cout << "Tree cleared.\n";
            treeLoaded = false;//Reset the flag
            break;
        case 7:
            if (treeLoaded) 
            {
                char index;
                cout << "Enter a letter (A-Z) to find words starting with that letter: ";
                cin >> index;
                index = toupper(index);//Ensure the letter is uppercase
                fileReader.findWordsByIndex(index, tree);//Find and display words starting with the specified letter
            }
            else 
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        case 8: {
            //Load characters from a CSV file into the TreeMap, using "element" or "character_class" as the key
            string keyField;
            cout << "Enter key field for characters (element/character_class): ";
            cin >> keyField;//Allow user to choose key field
            fileReader.loadCharactersToTree(characterFile, treeMap, keyField);
            charactersLoaded = true;
            cout << "Characters loaded successfully into the TreeMap.\n";
            cout << "TreeMap size: " << treeMap.size() << endl;
            break;
        }
        case 9: {
            //Traverse the TreeMap in order
            if (charactersLoaded)
            {
                cout << "In-order Traversal of TreeMap:\n";
                treeMap.traverseInOrder([](BSTNode<Pair<string, vector<RPGCharacter>>>* node) {
                    //For each node in TreeMap, print the key (string) and the size of the vector of RPGCharacters
                    cout << "Key: " << node->getItem().getFirst() << ", Size: "
                        << node->getItem().getSecond().size() << endl;
                    });
            }
            else
            {
                cout << "TreeMap is empty. Load characters first.\n";
            }
            break;
        }
        case 10: {
            //Print all RPG characters
            if (charactersLoaded) {
                cout << "Printing all RPG characters:\n";
                treeMap.traverseInOrder([](BSTNode<Pair<string, vector<RPGCharacter>>>* node) {
                    //For each entry, print the key (element/character_class) and all RPG characters associated with that key
                    cout << "Key: " << node->getItem().getFirst() << "\nCharacters:\n";
                    const vector<RPGCharacter>& characters = node->getItem().getSecond();

                    printf("%-5s %-15s %-10s %-15s %-5s %-10s\n",
                        "ID", "Name", "Element", "Class", "Level", "Legendary");//Headings

                    for (const RPGCharacter& character : characters) 
                    {
                        character.display();//Call the display method to print each character's details
                    }
                    cout << endl;
                    });
            }
            else 
            {
                cout << "No characters loaded. Load characters first.\n";
            }
            break;
        }
        case 11: {
            //Clear the tree
            treeMap.clear();
            cout << "RPG Character Tree cleared.\n";
            charactersLoaded = false;//Reset the flag
            break;
        }
        case 99:
            cout << "Exiting program.\n";
            return 0;//Exit the program
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
