//
//  list.h
//  socialNetwork
//
//  Created by Varun Mishra on 7/30/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//
#include "BinarySearchTree.h"
#include "hashing.h"
#include "person.h"

template <class itemType>
class LinkedList {
private:
    struct ListNode {
        itemType data;
        ListNode *next;
    };
    ListNode *root;
    
public:
    LinkedList() {root = NULL;};
    void append(int a) {
        ListNode *n = new ListNode;
        n->data = a;
        n->next = NULL;
        
        ListNode *nodePtr;
        if(root == NULL) {
            root = n;
        }
        else {
            nodePtr = root;
            while(nodePtr->next != NULL) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = n;
        }
    }
    void insert(itemType data) {
        ListNode *n = new ListNode;
        n->data = data;
        ListNode *nodePtr; ListNode *prev;
        if(root == NULL) {
            root = n;
            n->next = NULL;
        }
        else {
            nodePtr = root;
            prev = NULL;
            while(nodePtr!= NULL && n->data > nodePtr->data) {
                
                prev = nodePtr;
                nodePtr = nodePtr->next;
            }
            if (prev == NULL) {
                root  = n;
                n->next = nodePtr;
            }
            else {
                prev->next = n;
                n->next  = nodePtr;
            }
            
        }
    }
    
void display() {
        ListNode *nodePtr;
        nodePtr = root;
        while (nodePtr != 0) {
            cout << nodePtr->data <<endl;
            nodePtr = nodePtr->next;
        }
    }
    
    
itemType& search(itemType name) {
        ListNode *nodePtr;
        nodePtr = root;
        while (nodePtr->data != name) {
            nodePtr = nodePtr->next;
        }
    return nodePtr->data;
    }

    
    ~LinkedList()
    {
        ListNode *nodePtr;   // To traverse the list
        ListNode *nextNode;  // To point to the next node
        
        // Position nodePtr at the head of the list.
        nodePtr = root;
        
        // While nodePtr is not at the end of the list...
        while (nodePtr != NULL)
        {
            // Save a pointer to the next node.
            nextNode = nodePtr->next;
            
            // Delete the current node.
            delete nodePtr;
            
            // Position nodePtr at the next node.
            nodePtr = nextNode;
        }
    }
    
    void deleteNode(itemType searchValue)
    {
        ListNode *nodePtr;       // To traverse the list
        ListNode *previousNode;  // To point to the previous node
        
        // If the list is empty, do nothing.
        if (!root)
            return;
        
        // Determine if the first node is the one.
        if (root->data == searchValue)
        {
            nodePtr = root->next;
            delete root;
            root = nodePtr;
        }
        else
        {
            // Initialize nodePtr to head of list
            nodePtr = root;
            
            // Skip all nodes whose value member is
            // not equal to num.
            while (nodePtr != NULL && nodePtr->data != searchValue)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            
            // If nodePtr is not at the end of the list,
            // link the previous node to the node after
            // nodePtr, then delete nodePtr.
            if (nodePtr)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }
    
    void addToBst(BinarySearchTree<itemType> &obj)
    {
        ListNode *nodePtr;
        nodePtr = root;
        while (nodePtr != 0) {
            obj.insert(nodePtr->data);
            nodePtr = nodePtr->next;
        }

    }
    
    void addtoHash(hashing &obj)
    {
        ListNode *nodePtr;
        nodePtr = root;
        while(nodePtr != 0) {
            obj.addObject(nodePtr->data);
            nodePtr = nodePtr->next;
        }
        
    }
    
    void addToFile(ofstream &obj) {
        person temp;
        ListNode *nodePtr;
        nodePtr = root;
        while(nodePtr != 0) {
            temp =  nodePtr->data;
            obj << temp.getName() << endl;
            obj << temp.getPwd() << endl;
            obj << temp.getGender() << endl;
            obj << temp.getAge() << endl;
            obj << temp. getCity() <<endl;
            if(nodePtr->next == NULL) {
                obj << temp.getCollege();

            }
            else {
                 obj << temp.getCollege() << endl << endl;
            }
            nodePtr = nodePtr->next;
        }

    }
};
