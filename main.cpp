#include <iostream>
#include "BinaryTree.h" 

using namespace std;

int main()
{
    //Instance of binary tree for ints
    BinaryTree<int> myTree;
    
    //test data
    int data1 = 10;
    int data2 = 20;
    int data3 = 5;

    //adding test data to the tree
    myTree.add(data1);
    myTree.add(data2);
    myTree.add(data3);

    //printing eveyrthing out
    cout << "Data added to the tree successfully!" << endl;

    cout << "In-Order Traversal:" << endl;
    myTree.printInOrder();

    cout << "Pre-Order Traversal:" << endl;
    myTree.printPreOrder();

    cout << "Post-Order Traversal:" << endl;
    myTree.printPostOrder();

    return 0;
}
