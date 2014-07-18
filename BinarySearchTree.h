#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
	struct node
	{
		int data;
		node* left;
		node* right;          
	};
	node* root;

public:
	BinarySearchTree() {root = NULL;}
	bool isEmpty() const {return root == NULL;} //checks if BST is empty
	void insert(int); //insert an item into the BST
	void remove(int); //removes an item from the BST
	void inOrder(node*); //calculates the in-order traversal
	void print_inOrder(); //prints the in-order traversal
};
