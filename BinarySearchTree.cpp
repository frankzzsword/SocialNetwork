/*************************************************Binary Search Tree******************************************************/

#include <iostream>
#include "BinarySearchTree.h"
#include "person.h"
using namespace std;


template <class itemType>
void BinarySearchTree<itemType>::insert(itemType d)
{
	node* n = new node;
	node* parent = NULL;
	n->data = d;
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
	inOrder(root);
}

template <class itemType>
void BinarySearchTree<itemType>::inOrder(node* i)
{
	if(i != NULL)
	{
		cout<<i->data;
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

int main()
{
	BinarySearchTree<person> B1;
	person Varun("Varun", "me" ,'M', 23, "Sunnyvale", "De Anza");
    person Ted("Ted","you", 'M', 20, "San Francisco", "Berkeley");
    person Matt("Matt","them", 'M', 22, "Armenia", "Berkeley");
    person Danny("Danny" , "no", 'M', 22, "Armenia", "Berkeley");
	person Zhao("Zhao", "me" ,'M', 23, "Sunnyvale", "De Anza");
    
	person personArray[] = {Matt, Zhao, Varun, Danny, Ted};

	for(int i = 0; i < 5; i++) {
		B1.insert(personArray[i]);
	}

	B1.print_inOrder();
	int a;
	cin >> a;

	/*int optionNumber,input1,input2;
	while(1)
	{
		cout<<endl<<"Enter option number:"<<endl;
		cout<<"1: Insertion"<<endl;
		cout<<"2: In-Order Traversal"<<endl;
		cout<<"3: Deletion"<<endl;
		cout<<"4: Exit"<<endl;
		cin>>optionNumber;

		switch(optionNumber)
		{
		case 1 : cout<<"Input number to insert: "<<endl;
			cin>>input1;
			B1.insert(input1);
			break;
		case 2 : cout<<endl;
			cout<<"Here is the in-order traversal: "<<endl;
			B1.print_inOrder();
			break;
		case 3 : cout<<"Input number to delete: "<<endl;
			cin>>input2;
			B1.remove(input2);
			break;
		case 4 : */
			return 0;

	
}
