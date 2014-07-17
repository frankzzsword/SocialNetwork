//
//  inputoutput.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/15/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include "person.cpp"

using namespace std;

class inputoutput {

public:
void userMenu(person personArray[], string name, string password) {
    
   
        bool found = false;
        bool options = true;
        
        for( int i = 0; i < 3; i++) {
            if(personArray[i].getName() == name && personArray[i].getPassword() == password) {
                found = true;
                while(options == true) {
                    cout << "-------------"<< personArray[i].getName() << " Profile --------------" << endl;;
                    cout << "Choose an option from below" << endl;
                    cout << "1. Add a friend" << endl << "2. Write a new Status Message" << endl << "3. Send a message" << endl << "4. Show your friends" << endl << "5. Show your status messages" << endl << "6. Show your messages " << endl << "7. Logout" << endl;
                    int option;
                    string friendName;
                    string message;
                    string pressKey;
                    string status = " ";
                    cin >> option;
                    switch(option) {
                        case 1 : cout << "Which friend would you like to add" << endl;
                            cin >> friendName;
                            for(int d = 0; d < 3; d++) {
                                if (friendName == personArray[d].getName())
                                    personArray[i].addFriend(personArray[d]);
                            }
                            break;
                            
                        case 2 : cout << "What's on your mind?" << endl;
                            cin.ignore();
                            getline(cin, status);
                            cout << " " << endl;
                            personArray[i].addStatus(status);
                            break;
                        case 3 :
                            cout << "Which friend would you like to send a message" << endl;
                            cin.ignore();
                            getline(cin, friendName);
                            cout << "What message would you like to send : " << endl;
                            getline(cin, message);
                            for(int d = 0; d < 3; d++) {
                                if (friendName == personArray[d].getName())
                                    personArray[i].sendMessage(personArray[d], message);
                            }
                            break;
                        case 4 :
                            personArray[i].printFriends();
                            break;
                            
                        case 5 :
                            personArray[i].printStatus();
                            break;
                        case 6 :
                            personArray[i].printMessages();
                            
                            break;
                        case 7 :
                            options = false;
                            break;
                        default:
                            cout << "select the right option";
                            
                    }
                    cout <<endl << "Press z to continue : ";
                    cin>> pressKey;
                    
                }
            }
        }
    if(options == false){
            cout << "You've been logged out." << endl;
        return;
    }
        if(found == false) {
            cout << "incorrect username or password" << endl;
        }
    }
    
    void adminMenu() {
        
    }
    
    
    
};
