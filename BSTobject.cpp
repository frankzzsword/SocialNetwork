#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <map>
using namespace std;

class person {
private:
    string name;
    string password;
    char gender;
    int age;
     string city;
     string college;
     vector<person> friends;
     vector< string> status;
// vector< string> messages;
     map<string, vector<string>> text;

public:
  
 person ( string name, string password, char gender, int age, string city, string college){
    this->name = name;
    this->password = password;
    this->age = age;
    this->city = city;
    this->college = college;
 }
 person::person()
 {
 }
 string getName()
 {
	 return name;
 }
};


struct BstNode 
{
		person object;
		BstNode* left;
		BstNode* right;

BstNode::BstNode()
{

}
};
BstNode* GetNewNode(person x)
{
	BstNode* newNode = new BstNode();
	newNode->object = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* current, person x)
{
	if(current == NULL)
		current = GetNewNode(x);
	return current;
}


void print_binary_tree(BstNode* current) {
	if (current == NULL) {  }
	if (current->left != NULL) { print_binary_tree (current->left); }
	cout << current->object->name << endl;
	if (current->right != NULL) { print_binary_tree (current->right); }
}

print_binary_tree(BstNode* current) {
	if (current == NULL) {  }
	print_binary_tree (current->left);
		print_binary_tree (current->left); }
             cout number
		}
		cout << current->object->name << endl;
		print_binary_tree (current->right)
			cout integer
		}
	}
	cout number






int main()
{
	BstNode* current;
	current = NULL;

	person Varun("Varun", "me" ,'M', 23, "Sunnyvale", "De Anza");
    person Ted("Ted","you", 'M', 20, "San Francisco", "Berkeley");
    person Matt("Matt","them", 'M', 22, "Armenia", "Berkeley");
    person Danny("Danny" , "no", 'M', 22, "Armenia", "Berkeley");
	
	current = Insert(current,Varun);
	current = Insert(current,Ted);
	current = Insert(current,Matt);

	cout<<current->object.getName()<<endl;
	//cout<<current->left->object.getName();
	int i=0;
	cin >> i; 


}
