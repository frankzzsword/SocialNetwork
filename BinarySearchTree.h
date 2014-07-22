#include <iostream>

using namespace std;

template <class itemType>
class BinarySearchTree
{
private:
	struct node
	{
		itemType data;
		node* left;
		node* right;          
	};
		node* root;

public:
	BinarySearchTree() {root = NULL;}
	bool isEmpty() const {return root == NULL;} //checks if BST is empty
	void insert(itemType); //insert an item into the BST
	void remove(itemType); //removes an item from the BST
	void inOrder(node*); //calculates the in-order traversal
	void print_inOrder(); //prints the in-order traversal

};
