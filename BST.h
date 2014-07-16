#include <iostream>
using namespace std;


struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
};

/**********************************************************GetNewNode****************************************************/
BSTNode* GetNewNode(int data){
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

/**********************************************************Insert*******************************************************/
BSTNode* Insert(BSTNode* root, int data){
if(root == NULL) {
	root = GetNewNode(data);
}
else if(data <= root->data){
	root->left = Insert (root->left,data);
}
else {
	root->right = Insert(root->right,data);
}
return root;
}

/**********************************************************Search*******************************************************/
bool Search(BSTNode* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return Search(root->left,data);
	else return Search(root->right, data);
}
