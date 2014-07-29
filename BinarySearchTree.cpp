/*************************************************Binary Search Tree******************************************************/

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;



template <class itemType>
typename BinarySearchTree<itemType>::node* BinarySearchTree<itemType>::_insert(node*& i, itemType &d){
    if(i == NULL)  // (1) If we are at the end of the tree place the value
    {
        node* n = new node;
        n->data = &d;
        n->left = n->right = NULL;
        i = n;
    }
    else if(d < *i->data){  //(2) otherwise go left if smaller
        _insert(i->left, d);
        if(Height(i->left) - Height(i->right) == 2){
            if(d < *i->left->data)
                rotateLeftOnce(i);
            else
                rotateLeftTwice(i);
        }
    }
    else if(d > *i->data){ // (3) otherwise go right if bigger
        _insert(i->right, d);
        if(Height(i->right) - Height(i->left) == 2){
            if(d > *i->right->data)
                rotateRightOnce(i);
            else
                rotateRightTwice(i);
        }
    }
    return i;
}


template <class itemType>
void BinarySearchTree<itemType>::insert(itemType &data){
 
    _insert(root, data);
}

template <class itemType>
void BinarySearchTree<itemType>::remove(itemType &d)
{
    node* current = root;
    node* parent = nullptr;
    bool found = 0;
    
    if(isEmpty())
    {
        cout<<"BST is empty"<<endl;
        return;
    }
    
    
    while(current != NULL)
    {
        if(*current->data == d)
        {
            found = true;
            break;
        }
        else
        {
            parent = current;
            
            if(*current->data < d)
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
                *current->data = *leftCurrent->data;
                delete leftCurrent;
                leftCurrentPred->left = NULL;
            }
            else
            {
                node* input1;
                input1 = current->right;
                *current->data = *input1->data;
                current->right = input1->right;
                delete input1;
            }
        }
        return;
    }
}
//template<class itemType>
//typename BinarySearchTree<itemType>::node* BinarySearchTree<itemType>::_remove(node* root, itemType &elem) {
//    node* save;
//    if(root == NULL) {
//        printf("Element not in the tree !\n");
//        return 0 ;
//    }
//    if(*root->data == elem) {
//        if(root->right == NULL && root->left == NULL) {                  // no child
//            free(root);
//            return NULL;
//        }
//        else if(root->right == NULL || root->left == NULL) {             // one child
//            if(root->right == NULL) {
//                save = root->right;
//                free(root);
//                return save;
//            }
//            else {
//                save = root->right;
//                free(root);
//                return save;
//            }
//        }
//        else {                                                             // two children
//            save = findPred(root->right);
//            root->data = save->data;
//            root->right = _remove(root->left, *root->data);
//            return root;
//        }
//    }
//    else if(*root->data < elem) {
//        root->right = _remove(root->right, elem);
//    }
//    else if(*root->data > elem) {
//        root->left = _remove(root->left, elem);
//    }
//    return root;
//}
//
//template <class itemType>
//typename BinarySearchTree<itemType>::node* BinarySearchTree<itemType>::findPred(node* root) {
//    static node* pred;
//    if(root == NULL) {
//        return pred;
//    }
//    else {
//        pred = root;
//        return findPred(root->right);
//    }
//}

//
//
//template <class itemType>
//void BinarySearchTree<itemType>::remove(itemType &data){
//    
//    _remove(root, data);
//}
//

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
        cout<< *i->data << endl;

        if(i->left)
        {
            inOrder(i->left);
        }

        if(i->right)
        {
            inOrder(i->right);
        }

    }
    else return;
}

template <class itemType>
void BinarySearchTree<itemType>::printIndent()
{
    cout << "****** PRINTING BINARY SEARCH TREE *******" << endl;
    indented( root, 0 );
}

template <class itemType>
void BinarySearchTree<itemType>::indented ( node* tp, int spaces )
{
    int i;
    if( tp != NULL )
    {
        indented( tp->right, spaces + 13 );
        for( i = 0; i < spaces; i++ )
            cout <<' ';
        person *ptr = tp->data;
        cout << ptr->getName() << endl;
        indented( tp->left, spaces + 13);
    }
}


//  Somewhere else in the program...:

template <class itemType>
itemType* BinarySearchTree<itemType>::_search(node* i ,itemType const &key) {
    
    
   	if(i == NULL) return NULL;
    
    if(*i->data == key) return i->data;
    else {
        if(*i->data < key)
            return _search(i->right, key) ;
        else
            return _search(i->left, key);
    }
    
}
template <class itemType>
itemType* BinarySearchTree<itemType>::search(itemType const &key) {
    return _search(root, key);
}


template <class itemType>
int BinarySearchTree<itemType>::Height(node* node){
    int  left , right;
    if(node==NULL){
        return false;
        }
    
    left = Height(node->left);
    right = Height(node->right);
    if(left > right)
        return left+1;
    else
        return right+1;
}

template <class itemType>
void BinarySearchTree<itemType>::rotateLeftOnce(node*& i){
    node *otherNode;
    otherNode = i->left;
    i->left = otherNode->right;
    otherNode->right = i;
    i = otherNode;
}

template <class itemType>
void BinarySearchTree<itemType>::rotateLeftTwice(node*& i){

    rotateRightOnce(i->left);
    rotateLeftOnce(i);
}

template <class itemType>
void BinarySearchTree<itemType>::rotateRightOnce(node*& i){
    node * otherNode;
    otherNode = i->right;
    i->right = otherNode->left;
    otherNode->left = i;
    i = otherNode;
}

template <class itemType>
void BinarySearchTree<itemType>::rotateRightTwice(node*& i){
    rotateLeftOnce(i->right);
    rotateRightOnce(i);
}

