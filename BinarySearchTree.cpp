#include <iostream>
#include "BST.h"

using namespace std;

int main(){
BSTNode* root = NULL; // set the tree as empty
root = Insert(root,15);
root = Insert(root,25);
root = Insert(root,35);
int number;
cout<<"Enter number to be searched\n";
cin>>number;
if(Search(root,number) == true) cout<<"Found\n";
else cout<<"Not Found\n";
}




