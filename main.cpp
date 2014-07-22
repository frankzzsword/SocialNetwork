//
//  main.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "person.h"
#include "inputoutput.cpp"
#include "hashing.h"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"


using namespace std;

int main(int argc, const char * argv[]) {

    
    /*
     create object of inputout.
     */
    inputoutput menu;
    hashing hashfunc;
    
    menu.readFile("names.txt");
    
    for(int i = 0; i < 10; i++) {
        hashfunc.addObject(menu.personArray[i]);
    }
    
    hashfunc.PrintTable();
  
        BinarySearchTree<person> tree;
        for(int i = 0; i < 12; i++) {
            tree.insert(menu.personArray[i]);
        }
    
        cout << " Binary Tree " << endl;
    tree.print_inOrder();
    
    
    
    int input = 0;
    while(input != 2) {
        string name;
        string password;
        cout << "Username: ";
        getline(cin, name);
        cout << "Password: ";
        cin>>password;
        
        if(name != "admin")
            menu.userMenu(menu.personArray, name, password);
        else
            cout << "admin menu" << endl;
        }
    
    
    
}
