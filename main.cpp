#include <iostream>
#include "BinaryTree.h"
#include "Pair.h"

using namespace std;

int main() {
    BinaryTree<Pair<int, string>> tree;

    //objects for testing
    Pair<int, string> p1(1, "One");
    Pair<int, string> p2(2, "Two");
    Pair<int, string> p3(3, "Three");
    Pair<int, string> p4(4, "Four");

    //Add pairs to the binary tree
    tree.add(p1);
    tree.add(p2);
    tree.add(p3);

    //Print in-order traversal
    cout << "In-order Traversal:" << endl;
    tree.printInOrder();
    cout << endl;

    //Print pre-order traversal
    cout << "Pre-order Traversal:" << endl;
    tree.printPreOrder();
    cout << endl;

    //Print post-order traversal
    cout << "Post-order Traversal:" << endl;
    tree.printPostOrder();
    cout << endl;

    //Check the size of the tree
    cout << "Size of the tree: " << tree.count() << endl;

    //Retrieve a specific pair using its key
    try {
        Pair<int, string>& found = tree.get(p2);  //Get Pair with key 2
        cout << "Retrieved Pair: " << found << endl;
    }
    catch (logic_error& e) {
        cout << e.what() << endl;
    }

    //Remove 2 from the tree
    tree.remove(p2);
    cout << "In-order Traversal after removal:" << endl;
    tree.printInOrder();
    cout << endl;


    //Adding element
    tree.add(p4);

    //Print in-order traversal after adding a new element
    cout << "In-order Traversal after adding (4, Four):" << endl;
    tree.printInOrder();
    cout << endl;

    //Clear the tree
    cout << "Clearing the tree..." << endl;
    tree.clear();

    //Check the size after clearing
    cout << "Size of the tree after clearing: " << tree.count() << endl;

    //Try printing after clearing
    cout << "In-order Traversal after clearing:" << endl;
    tree.printInOrder();

    return 0;
}
