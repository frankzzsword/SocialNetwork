//
//  main.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "inputoutput.cpp"
using namespace std;

int main(int argc, const char * argv[]) {

    
    inputoutput menu;

    person Varun("Varun", "me" ,'M', 23, "Sunnyvale", "De Anza");
    person Ted("Ted","you", 'M', 20, "San Francisco", "Berkeley");
    person Matt("Matt","them", 'M', 22, "Armenia", "Berkeley");
    person Danny("Danny" , "no", 'M', 22, "Armenia", "Berkeley");
    
    person personArray[] = {Varun, Ted, Matt};
    int input = 0;
    
    while(input != 2) {
        string name;
        string password;
        cout << "Username: ";
        cin>>name;
        cout << "Password: ";
        cin>>password;
        
        if(name != "admin")
            menu.userMenu(personArray, name, password);
        else
            cout << "admin menu" << endl;
        }
    
    
    
}
