//
//  inputoutput.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/15/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include "person.h"
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

using namespace std;

class inputoutput {
    
public:
    person personArray[100];
    int count;
    inputoutput() {
        count = 0;
    }
    void readFile(string textname)  //dynamically allocate memory and storing each product line into the dynamic memory array
    {
        string  name;
        string password;
        string gender;
        string age;
        string city;
        string college;
        string profilePicture;
        string wasteSpace;
        
        
        ifstream infile;
        infile.open(textname);
        while(!infile.eof())
        {
            getline(infile, name);
            getline(infile, password);
            getline(infile, gender);
            getline(infile, age);
            getline(infile, city);
            getline(infile, college);
            getline(infile, profilePicture);
            getline(infile, wasteSpace);
            int Age = atoi(age.c_str());
            
            person tempPerson(name, password, gender, Age, city, college);
            personArray[count] = tempPerson;
            count++;
            
            
        }
    }
    
    int countLines() const{
        return count;
    }
    
    void userMenu(person *personArray, string name, string password) {
        
        
        bool found = false;
        bool options = true;
        
        for( int i = 0; i < 12; i++) {
            
            //*******IMPORTANT... CHANGE THIS TO SEARCH FROM BST......*********//
            
            if(personArray[i].getName() == name && personArray[i].getPwd() == password) {
                found = true;
                int status;
                if(personArray[i].getStatus() != false)
                {
                    cout << "Your account is not active" << endl;
                    cout << "Please reactivate your account in order to access it" <<endl;
                    cout << "Press [1] to Reactivate or [2] to Exit" <<endl;
                    cin >> status;
                    if (status == 1)
                        personArray[i].deactivateAccount(false);
                    else
                        return;
                }
                while(options == true) {
                    cout << "-------------"<< personArray[i].getName() << " Profile --------------" << endl;;
                    cout << "Choose an option from below" << endl;
                    cout << "1. Add a friend" << endl
                    << "2. Write a new Status Message" << endl
                    << "3. Send a message" << endl
                    << "4. Show your friends" << endl
                    << "5. Show your status messages" <<endl
                    << "6. Show your messages " << endl
                    << "7. Account Settings" << endl
                    << "8. Logout"  << "[Choose Your Option] : " ;
                    
                    int option;
                    string friendName;
                    string message;
                    string pressKey;
                    bool friendFound = false;
                    string status = " ";
                    cin >> option;
                    switch(option) {
                        case 1 : cout << "Which friend would you like to add" << endl;
                            cin.ignore();
                            getline(cin, friendName);
                            for(int d = 0; d < 3; d++) {
                                if (friendName == personArray[d].getName()) {
                                    personArray[i].addFriend(personArray[d]);
                                    friendFound = true;
                                }
                            }
                            if(friendFound == false) cout << "Person does not exist in the database";
                            break;
                            
                        case 2 : cout << "What's on your mind?" << endl;
                            cin.ignore();
                            getline(cin, status);
                            cout << " " << endl;
                            personArray[i].setStatus(status);
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
                        case 7:
                            userAdminMenu(personArray[i]);
                            break;
                        case 8 :
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
    
    void userAdminMenu(person &personName) {
        bool options = true;
        while( options == true ) {
            int option;
            string temp;
            cout << "-------------"<< personName.getName() << " Settings --------------" << endl;;
            cout << "Choose an option from below" << endl;
            cout << "1. Change Password" << endl
            << "2. Change City " << endl
            << "3. Change University" << endl
            << "4. Delete a Friend" << endl
            << "5. Change Relationship status" <<endl
            << "6. Deactivate Profile " << endl
            << "7. Back to your Profile" << endl
            <<"[Choose Your Option] : ";
            cin >> option;
            switch(option) {
                case 1 :
                    cout << "New Password : ";
                    cin>>temp;
                    personName.setPassword(temp);
                    cout << "Your Password has been changed";
                    break;
                case 2 :
                    cout << "New City : ";
                    cin>>temp;
                    personName.setCity(temp);
                    cout << "Your City has been changed";
                    break;
                case 3 :
                    cout << "New University : ";
                    cin>>temp;
                    personName.setCollege(temp);
                    cout << "\nYour University has been changed";
                    break;
                case 4:
                    cout << "Enter the name of the friend you want to Delete : ";
                    cin.ignore();
                    getline(cin, temp);//find through binary search tree or hash
                    break;
                case 5 :
                    cout << "Who are you in relationship with (write name or type 'none') : " << endl;
                    //personName.setRelationship() //find through binary search tree or hash
                    break;
                case 6 :
                    cout << "Are you sure you want to deactivate your account?" <<endl
                    <<"Choose [1] for Yes \n [2] for No  : ";
                    cin >> temp;
                    if (temp == "1"){
                        personName.deactivateAccount(true);
                        cout <<"Your account has been deactivated, however you can still access your account until you logout";
                    }
                    else {
                        cout << "Your account has not been deactivated" << endl;
                    }
                    break;
                case 7:
                    options = false;
                    break;
                default:
                    cout << "please select the right option";
                    
            }
        }
        
        
    }
    
    
    void adminMenu(inputoutput &obj, string password) {
        if (password != "vno")
        {
            cout << "incorrect username or password";
            return;
        }
        
        bool options = true;
        while(options == true) {
            cout <<  "-------------------- ADMINISTRATOR  --------------" << endl;;
            cout << "Choose an option from below" << endl;
            cout << "1. Create a new Profle" <<endl
            << "2. Delete a Person" << endl
            << "3. Search a person by Name" << endl
            << "4. Print the Hash Table" << endl
            << "5. Print the Binary Tree" << endl
            << "6. Print Indented Tree" <<endl
            << "7. Write to File" << endl
            << "8. Usage Statistics" << endl
            << "9. Logout" << endl
            << "[Choose Your Option] : " ;
            int option;
            cin >> option;
            
            switch(option) {
                case 1 :
                    
                    break;
                case 2 :
                    
                    break;
                    
                case 3 :
                    
                    break;
                    
                case 4 :
                    break;
                    
                case 5 :
                    //  tree.print_inOrder();
                    break;
                    
                case 6:
                    
                    break;
                    
                case 7 :
                    
                    break;
                    
                case 8 :
                    
                    break;
                    
                case 9 :
                    options = false;
                    break;
                default :
                    cout << "Please enter the correct choice:" ;
            }
            
        }
        if(options == false) {
            cout << "You have been logged out" <<endl;
            return;
        }
    }
};
