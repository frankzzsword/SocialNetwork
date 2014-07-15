//
//  main.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "person.cpp"
using namespace std;

int main(int argc, const char * argv[]) {

    person Varun("Varun", "me" ,'M', 23, "Sunnyvale", "De Anza");
    person Ted("Ted","you", 'M', 20, "San Francisco", "Berkeley");
    person Matt("Matt","them", 'M', 22, "Armenia", "Berkeley");
    
    person personArray[] = {Varun, Ted, Matt};
    
    while(true) {
    string name;
    string password;
    cout << "Username: ";
    getline(cin, name);
    cout << "Password: ";
    getline(cin, password);
        bool found = false;
    
    for( int i = 0; i < 3; i++) {
        if(personArray[i].getName() == name && personArray[i].getPassword() == password) {
            found = true;
            cout << string(50, '\n');
            cout << "___________"<< personArray[i].getName() << " Profile ___________" << endl;;
            cout << "Choose an option from below" << endl;
            cout << "1. Add a friend" << endl << "2. Write a new Status Message" << endl << "3. Send a message" << endl;
            int option;
            string friendName;
            string status;
            cin >> option;
             cout << string(50, '\n');
            switch(option) {
                case 1 : cout << "Which friend would you like to add" << endl;
                    cin >> friendName;
                    for(int d = 0; d < 3; d++) {
                        if (friendName == personArray[d].getName())
                             personArray[i].addFriend(personArray[d]);
                    }
                    break;
                    
                case 2 : cout << "What's on your mind?" << endl;
                    cin>> status;
                    personArray[i].addStatus(status);
                    break;
                case 3 : cout << "Which friend would you like to send a message" << endl;
                            getline(cin, friendName);
                    break;
                default:
                    cout << "select the right option";
                    
            }
        }
    }
        if(found == false) {
                cout << "incorrect username or password" << endl;

        }
    }
    
    
}
