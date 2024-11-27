#include <iostream>
#include "BinaryTree.h"
#include "Pair.h"
#include "FileReader.h"

using namespace std;

//Function to print the menu options
void printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Load words from file and populate the tree\n";
    cout << "2. Print In-order Traversal\n";
    cout << "3. Print Pre-order Traversal\n";
    cout << "4. Print Post-order Traversal\n";
    cout << "5. Check size of the tree\n";
    cout << "6. Clear the tree\n";
    cout << "7. Find words by index (first letter)\n";
    cout << "9. Exit\n";
}

int main() {
    BinaryTree<Pair<string, char>> tree;  //Create a BinaryTree for storing words and their first letters
    FileReader fileReader;  //FileReader object to load words from file
    bool treeLoaded = false;  //Flag to check if words are loaded into the tree

    int choice;
    string filename = "RandomWords.txt";  //The file containing words

    while (true)
    {
        printMenu();  //Display the menu
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            //Load words from file into the tree (BST)
            fileReader.loadWordsToTree(filename, tree);
            treeLoaded = true;
            cout << "Words loaded successfully into the tree.\n";
            break;
        }
        case 2:
        {
            if (treeLoaded)
            {
                cout << "In-order Traversal:\n";
                tree.printInOrder();  //Print the tree in-order (sorted by first letter)
            }
            else
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        }
        case 3:
        {
            if (treeLoaded)
            {
                cout << "Pre-order Traversal:\n";
                tree.printPreOrder();  //Print the tree in pre-order
            }
            else
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        }
        case 4:
        {
            if (treeLoaded)
            {
                cout << "Post-order Traversal:\n";
                tree.printPostOrder();  //Print the tree in post-order
            }
            else
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        }
        case 5:
        {
            if (treeLoaded)
            {
                cout << "Size of the tree: " << tree.count() << endl;  //Print the size of the tree
            }
            else
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        }
        case 6:
        {
            //Clear the tree
            tree.clear();
            cout << "Tree cleared.\n";
            treeLoaded = false;  //Reset the flag
            break;
        }
        case 7:
        {
            if (treeLoaded)
            {
                char index;
                cout << "Enter a letter (A-Z) to find words starting with that letter: ";
                cin >> index;
                index = toupper(index);  //Ensure the letter is uppercase
                fileReader.findWordsByIndex(index, tree);  //Find and display words starting with the specified letter
            }
            else
            {
                cout << "Tree is empty. Load words first.\n";
            }
            break;
        }
        case 9:
        {
            cout << "Exiting program.\n";
            return 0;  //Exit the program
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
