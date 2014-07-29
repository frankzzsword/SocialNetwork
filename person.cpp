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
    string gender;
    int age;
    string city;
    string college;
    person *relationship;
    vector<person*> friends;
    vector< string> status;
    //string is name of the friend and the vectors are for the messages
    map<string, vector<string> > text;
    bool deactivate;
    bool admin;
    person *next;
    
public:
    person();
    person ( string name, string password, string gender, int age,  string city,  string college);
    //SETTER METHODS
    void  setName( string item);
    void  setPassword(string password);
    void  setGender(string gender);
    void  setAge(int age);
    void  setCity(string city);
    void  setCollege( string college);
    void  setRelationship( person *lover);
    void  setStatus( string newStatus);
    void  deactivateAccount( bool deactivate);
    void  addFriend(person &friendName);
    void deleteFriend(person &friendName);
    void  receiveMessage(person&friendName ,string message);
    void  sendMessage(person &friendName,  string message);
    //GETTER METHODS
    string getName() const;
    string getPassword() const;
    string getPwd() const;
    string  getGender() const;
    int  getAge() const;
    string  getCity() const;
    string  getCollege() const;
    string getRelationship() const;
    bool getStatus() const;
    string getDate();
    vector<person *>  getFriends() const;


    
    //PRINT METHODS
    void  printFriends() const;
    void  printStatus() const;
    void  printMessages() const;
    
    
    //Overloaded Functions for Binary Search Tree
    bool operator < (const person &otherObject)
    {
        return name < otherObject.getName();
    }

    bool operator > (const person &otherObject)
    {
        return name > otherObject.getName();
    }

    
    bool operator == (const person &otherObject) {
        
        return this->name == otherObject.getName();
    }
    
    bool operator != (const person &otherObject) {
        
        return name != otherObject.getName();
    }
    
    
    friend ostream &operator<<( ostream &output,  const person &D )
    {
        output <<" ****************************************************** "<< endl
        << "* " <<  setw(15) << "Name: "<< D.getName() << endl
        << "* " <<  setw(15) << "Gender: " << D.getGender() <<endl
        << "* " <<  setw(15) << "Age: " << D.getAge() <<endl
        << "* " <<  setw(15) << "City: " << D.getCity()<<endl
        << "* " <<  setw(15) << "College: " << D.getCollege()<<endl <<" ****************************************************** "<< endl;
        
        
        return output;
    }
};

#endif
