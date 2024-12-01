#pragma once
#include "BSTNode.h"
#include "Pair.h"
#include <vector>
#include <iostream>
#include <stack> 
#include <functional>

using namespace std;

template <class T>
class BinaryTree {
    void addItemToArray(BSTNode<T>* node, int& pos, T* arr);//adds items to an array recursively

public:
    BSTNode<T>* root;
    BinaryTree();//Constructor
    BinaryTree(const BinaryTree<T>& other);//Copy constructor
    BinaryTree<T>& operator=(const BinaryTree<T>& other);//Assignment operator
    void add(const T& item);//Add method works with pair
    bool remove(const T& item);//Remove method works with pair
    void clear();//clears entire tree
    int count();//counts the number of nodes in the tree
    T& get(const T& item);//Gets item from tree

    void printInOrder();//prints item in order
    void printInOrder(BSTNode<T>* node);
    void printPreOrder();//prints items in pre order
    void printPreOrder(BSTNode<T>* node);
    void printPostOrder();//prints items in post order
    void printPostOrder(BSTNode<T>* node);
    T* toArray();
    ~BinaryTree();//Destructor
};

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
    root = nullptr;
    if (other.root != nullptr)
        root = new BSTNode<T>(*other.root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
    if (this == &other)
        return *this;
    if (other.root != nullptr)
        root = new BSTNode<T>(*other.root);
    else
        root = nullptr;
    return *this;
}

template <class T>
void BinaryTree<T>::add(const T& item) {
    if (root == nullptr) {//if the tree is empty
        root = new BSTNode<T>(item);//create a new root
    }
    else {
        root->add(item);//we make it recursive so it keeps adding items to the correct node
    }
}

template <class T>
int BinaryTree<T>::count() {
    if (root == nullptr)
        return 0; //if the tree is empty, return 0
    return root->count();//if it's not empty, return the node count
}

template <class T>
bool BinaryTree<T>::remove(const T& item) {
    BSTNode<T>* toBeRemoved = root;//Start with root
    BSTNode<T>* parent = nullptr;//Parent of the node to be removed
    bool found = false;

    //Search for the node to remove
    while (!found && toBeRemoved != nullptr) {
        if (toBeRemoved->getItem() == item) {
            found = true;
        }
        else {
            parent = toBeRemoved;
            if (toBeRemoved->getItem() > item) {
                toBeRemoved = toBeRemoved->getLeft();
            }
            else {
                toBeRemoved = toBeRemoved->getRight();
            }
        }
    }

    if (!found)
        return false;//If Item not found, return false

    //If the node has 1 or 0 children, we replace it with its child
    if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr) {
        BSTNode<T>* newChild;
        if (toBeRemoved->getLeft() == nullptr) {
            newChild = toBeRemoved->getRight();
        }
        else {
            newChild = toBeRemoved->getLeft();
        }
        if (parent == nullptr) {
            root = newChild;
        }
        else if (parent->getLeft() == toBeRemoved) {
            parent->setLeft(newChild);
        }
        else {
            parent->setRight(newChild);
        }
        return true;
    }

    //If the node has two children, we find the smallest in the right subtree
    BSTNode<T>* smallestParent = toBeRemoved;
    BSTNode<T>* smallest = toBeRemoved->getRight();
    while (smallest->getLeft() != nullptr) {
        smallestParent = smallest;
        smallest = smallest->getLeft();
    }
    toBeRemoved->setItem(smallest->getItem());
    if (smallestParent == toBeRemoved) {
        smallestParent->setRight(smallest->getRight());
    }
    else {
        smallestParent->setLeft(smallest->getRight());
    }

    return true;
}

template <class T>
T& BinaryTree<T>::get(const T& item) {
    bool found = false;
    BSTNode<T>* current = root;

    while (!found) {
        if (current == nullptr)
            break;
        if (current->getItem() == item)
            return current->getItem();
        else if (current->getItem() > item)
            current = current->getLeft();
        else
            current = current->getRight();
    }

    throw logic_error("Item not found");//if not found we throw a logic error
}

template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int& pos, T* arr) {
    if (node != nullptr) {
        addItemToArray(node->getLeft(), pos, arr);
        arr[pos] = node->getItem();
        pos++;
        addItemToArray(node->getRight(), pos, arr);
    }
}

template <class T>
T* BinaryTree<T>::toArray() {
    T* arr = new T[root->count()];
    int pos = 0;
    addItemToArray(root, pos, arr);
    return arr;
}

template <class T>
void BinaryTree<T>::clear() {
    //Delete the current root node
    delete root;
    root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
    }
}

template <class T>
void BinaryTree<T>::printInOrder() {
    this->printInOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printInOrder(BSTNode<T>* node) {
    if (node != nullptr) {
        printInOrder(node->getLeft());
        cout << node->getItem() << " ";//Print the item using overloaded <<
        printInOrder(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::printPreOrder() {
    this->printPreOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPreOrder(BSTNode<T>* node) {
    if (node != nullptr) {
        cout << node->getItem() << " ";//Print the item using overloaded <<
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::printPostOrder() {
    this->printPostOrder(root);
    cout << endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(BSTNode<T>* node) {
    if (node != nullptr) {
        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getItem() << " ";//Print the item using overloaded <<
    }
}

