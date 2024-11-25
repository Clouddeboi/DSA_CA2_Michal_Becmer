#include <iostream>
#include "BinaryTree.h" 
#include "RPGCharacter.h"

using namespace std;

/*
    Project Idea:
    I will create RPG characters with 6 fields those being:
    ID
    Name
    Element
    HP
    Attack
    Defense

    I will sort all the characters by name alphabeitaclly
*/

int main()
{
    //Sample RPG characters for testing
    RPGCharacter character1(1, "Warrior", "Fire", 100, 20, 10);
    RPGCharacter character2(2, "Mage", "Water", 80, 15, 8);
    RPGCharacter character3(3, "Archer", "Air", 90, 18, 12);

    //Instance of Binary tree for my RPG Characters
    BinaryTree<RPGCharacter> myTree;

    //adding characters to the tree
    myTree.add(character1);
    myTree.add(character2);
    myTree.add(character3);

    //printing eveyrthing out
    cout << "Data added to the tree successfully!\n" << endl;

    //Print the characters in order (sorted by name)
    cout << "In-Order Traversal (Sorted by Name):" << endl;
    myTree.printInOrder();

    //Print the characters in pre-order (sorted by name)
    cout << "Pre-Order Traversal (Names):" << endl;
    myTree.printPreOrder();

    //Print the characters in post-order (sorted by name)
    cout << "Post-Order Traversal (Names):" << endl;
    myTree.printPostOrder();

    return 0;
}
