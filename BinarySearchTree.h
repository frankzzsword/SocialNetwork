#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include <iostream>
#include "person.h"

using namespace std;

template <class itemType>
class BinarySearchTree
{
private:
    struct node
    {
        person *data;
        node* left;
        node* right;
    };
    node* root;
    
public:
    BinarySearchTree() {root = NULL;}
    bool isEmpty() const {return root == NULL;} //checks if BST is empty
    void insert(itemType &data); //insert an item into the BST
    void remove(itemType data); //removes an item from the BST
    void inOrder(node*); //calculates the in-order traversal
    void print_inOrder(); //prints the in-order traversal
    itemType* _search(node* ,itemType &d);
    itemType* search(itemType &d);
    
};
#endif
