/*************************************************Binary Search Tree******************************************************/

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


template <class itemType>
void BinarySearchTree<itemType>::insert(itemType &d)
{
    node* n = new node;
    node* parent = NULL;
    n->data = &d;
    n->left = n->right = NULL;
    
    //if BST is empty, assign a new node as root
    if(isEmpty()) root = n;
    else
    {
        node* current = root;
        while(current)
        {
            parent = current;
            //if data in new node is greater than data in current node, assign data on right of current node as current
            if(n->data > current->data)
            {
                current = current->right;
            }
            
            else
            {
                //otherwise, assign data on left of current node as current
                current = current->left;
            }
        }
        
        //if data in new node is less than data in parent node, assign new node as left of parent
        if(n->data < parent->data)
        {
            parent->left = n;
        }
        
        //otherwise assign new node as right of parent (if it is not less than, than it is greater than or equal to)
        else
        {
            parent->right = n;
        }
    }
}

template <class itemType>
void BinarySearchTree<itemType>::remove(itemType d)
{
    node* current = root;
    node* parent;
    bool found = 0;
    
    if(isEmpty())
    {
        cout<<"BST is empty"<<endl;
        return;
    }
    
    
    while(current != NULL)
    {
        if(current->data == d)
        {
            found = 1;
            break;
        }
        else
        {
            parent = current;
            
            if(d>current->data)
            {
                current = current->right;
            }
            
            else
            {
                current = current->left;
            }
        }
    }
    if(!found)
    {
        cout<<"data is not found"<<endl;
        return;
    }
    
    //Node with no children (leaf node, both sides are null)
    if(current->left == NULL && current->right == NULL)
    {
        if(parent->left == current)
        {
            parent->left = NULL;
        }
        
        else
        {
            parent->right = NULL;
        }
        
        delete current;
        return;
    }
    
    //Node with a single child (one of the sides of a node is null and the other is not)
    if((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL))
    {
        if(current->left == NULL && current->right != NULL)
        {
            if(parent->left == current)
            {
                parent->left = current->right;
                delete current;
            }
            else
            {
                parent->right = current->right;
                delete current;
            }
        }
        else
        {
            if(parent->left == current)
            {
                parent->left = current->left;
                delete current;
            }
            else
            {
                parent->right = current->left;
                delete current;
            }
        }
        return;
    }
    
    //Node with 2 children (both sides are not equal to null)
    if (current->left != NULL && current->right != NULL)
    {
        node* checker;
        checker = current->right;
        if((checker->left == NULL) && (checker->right == NULL))
        {
            current = checker;
            delete checker;
            current->right = NULL;
        }
        else
        {
            if((current->right)->left != NULL)
            {
                node* leftCurrent;
                node* leftCurrentPred;
                leftCurrentPred = current->right;
                leftCurrent = (current->right)->left;
                while(leftCurrent->left != NULL)
                {
                    leftCurrentPred = leftCurrent;
                    leftCurrent = leftCurrent->left;
                }
                current->data = leftCurrent->data;
                delete leftCurrent;
                leftCurrentPred->left = NULL;
            }
            else
            {
                node* input1;
                input1 = current->right;
                current->data = input1->data;
                current->right = input1->right;
                delete input1;
            }
        }
        return;
    }
}

template <class itemType>
void BinarySearchTree<itemType>::print_inOrder()
{
     cout << "****** PRINTING BINARY SEARCH TREE *******" << endl;
    inOrder(root);
}

template <class itemType>
void BinarySearchTree<itemType>::inOrder(node* i)
{
    if(i != NULL)
    {
        if(i->left)
        {
            inOrder(i->left);
        }
        cout<< *i->data;
        
        if(i->right)
        {
            inOrder(i->right);
        }
    }
    else return;
}
