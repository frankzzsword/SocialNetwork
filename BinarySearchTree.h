#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include <iostream>
#include "person.h"

using namespace std;

template <class itemType>
class BinarySearchTree
{
    
    struct node {
    itemType *data;
    node* left;
    node* right;
    };
    node *root;
        
  public:
    BinarySearchTree() {root = NULL;}

    bool isEmpty() const {return root == NULL;} //checks if BST is empty
    typename BinarySearchTree<itemType>::node* _insert(node*&, itemType &);
    void insert(itemType &);
    void remove(itemType &data); //removes an item from the BST
//    typename BinarySearchTree<itemType>::node* _remove(node*,itemType &data); //removes an item from the BST
//    typename BinarySearchTree<itemType>::node* findPred(node* root);
    void inOrder(node*); //calculates the in-order traversal
    void print_inOrder(); //prints the in-order traversal
    void printIndent();
    void indented(node* p, int indent );
    itemType* _search(node*   ,itemType const &d);
    itemType* search(itemType const &d);
    int Height(node*);
    void rotateLeftOnce(node*&);
    void rotateLeftTwice(node*&);
    void rotateRightOnce(node*&);
    void rotateRightTwice(node*&);
    
};
#endif
