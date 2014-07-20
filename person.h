#ifndef PERSON
#define PERSON
//  person.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

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
    //name is the key for HASH and BST
    string name;

    string password;
    char gender;
    int age;
    string city;
    string college;
    vector<person> friends;
    vector< string> status;
    //string is name of the friend and the vectors are for the messages
    map<string, vector<string> > text;
    
public:
    person();
    person ( string name, string password, char gender, int age,  string city,  string college);
    //SETTER METHODS
    void setName( string item);
    void  setGender(char gender);
    void  setAge(int age);
    void  setCity(int city);
    void  setCollege( string college);
    void  setStatus( string newStatus);
    void  setFriend(person &friendName);
    void  receiveMessage(person&friendName ,string message);
    void  sendMessage(person &friendName,  string message);
    
    //GETTER METHODS
    string getName() const;
    string getPassword() const;
    char  getGender() const;
    int  getAge() const;
    string  getCity() const;
    string  getCollege() const;
    string getDate();

    //PRINT METHODS
    void  printFriends() const;
    void  printStatus() const;
    void  printMessages() const;
    
};

#endif
