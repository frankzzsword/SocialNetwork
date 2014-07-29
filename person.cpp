//  person.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//
#include "person.h"
#include <string>
#include <sstream>
#include <algorithm>



using namespace std;

// default constructor
person::person ( ) {
    name = " ";
    password = " ";
    gender = " ";
    age = 0;
    city = " ";
    college = " ";
    deactivate = false;
    admin = false;
};

// setter constructor
person::person ( string name, string password, string gender, int age,  string city,  string college){
    this->name = name;
    this->password = password;
    this->gender = gender;
    this->age = age;
    this->city = city;
    this->college = college;
    deactivate = false;
    admin = false;
    relationship = NULL;
};
void person::setName( string name) {
    this->name = name;
}
void person::setPassword( string password) {
    this->password = password;
}
void  person::setGender(string gender) {
    this->gender = gender;
}
void  person::setAge(int age) {
    this->age = age;
}
void  person::setCity(string city) {
    this->city = city;
}
void  person::setCollege( string college) {
    this->college = college;
}

void  person::setRelationship(person *lover){
    //if either one breaks up
    if (lover == NULL) {
        if(relationship == NULL) return;
        relationship->setStatus(relationship->getName() + " is now Single");
        relationship->relationship = NULL;
        relationship = NULL;
        setStatus(name + " is now " + getRelationship());
        return;
    }
    //Case 1, if both are single
    else if(this->relationship == NULL)
    { relationship = lover;
      lover->relationship = this;
      relationship->setStatus(name + " is now " + getRelationship());
    }
    //Case 2, if both are committed to each other
    else if(this->relationship != lover) {
        relationship->setStatus(relationship->getName() + " is now Single");
        relationship->relationship = NULL;
        relationship = lover;
        lover->setRelationship(this);
        relationship->setStatus(relationship->getName() + " is now " + getRelationship());
    }
    
    setStatus(name + " is now " + getRelationship());
}

void  person::setStatus(string newStatus) {
    string timeNow  = getDate()+newStatus;
    status.push_back(timeNow + "\n");
}

void  person::deactivateAccount( bool deactivate) {
    this->deactivate = deactivate;
}

void  person::receiveMessage(person&friendName ,string message) {
    friendName.text[this->name].push_back(message);
};


void  person::sendMessage(person &friendName,  string message) {
    bool found = false;
    if (&friendName == this)
    {
        cout << "You cannot send a message to yourself." <<  endl;
        return;
    }
    if (friends.size() == 0) {
        cout << "In order to send a message, you need to be friends with this person";
        return;
    }
    
    for (int i = 0; i < friends.size(); i++ ) {
        if (friends[i]->name == friendName.name) {
            found = true;
        }
        
    }
    if(found) {
        string messageName =  getDate() + "\n" + this->name + "  " + message + "\n";
        string firstName = friendName.getName();
        text[firstName].push_back(messageName);
        friendName.receiveMessage(friendName, messageName);
    }
    else
    {
        cout << "In order to send a message, you need to be friends with this person";
    }
    };




void  person::addFriend(person &friendName) {
    // NOTE : check if already exists or if it is the same person
    
    if (&friendName == this)
    {
        cout << "You cannot add yourself." <<  endl;
        return;
    }
    for (int i = 0; i < friends.size(); i++ ) {
        if (friends[i]->name == friendName.name) {
            cout << "You cannot add the same friend twice." <<  endl;
            return  ;
        }
    }
    friends.push_back(&friendName);
    friendName.friends.push_back(this);
    cout << name << " and " << friendName.name << " are now friend " <<  endl;
    setStatus(name + " and " + friendName.name + " are now friend ");
}

void  person::deleteFriend(person &friendName) {
    // NOTE : check if already exists or if it is the same person
    
    if (&friendName == this)
    {
        cout << "You cannot delete yourself." <<  endl;
        return;
    }
    for (int i = 0; i < friends.size(); i++ ) {
        if (friends[i]->name == friendName.name) {
            friends.erase(friends.begin() + i);
            friendName.deleteFriend(*this);
            return  ;
        }
    }
    cout << name << " and " << friendName.name << " are no longer friends." <<  endl;
}
string person::getName() const {
    return name;
}
string person::getPassword() const {
    int a = (int)password.length();
    
    string newPassword;
    for (int i = 0; i < a; i++) {
        newPassword += "*";
    }
    return newPassword;
}

string person::getPwd() const {
    return password;
}

string  person::getGender() const {
    return gender;
}
int  person::getAge() const {
    return age;
    
}
string person:: getCity() const {
    return city;
}
string  person::getCollege() const {
    return college;
}

bool  person::getStatus() const {
    return deactivate;
}


vector<person*>  person::getFriends() const {
    return friends;
}



string  person::getRelationship() const {
    if(relationship == NULL) {
        return "Single";
    }
    else
    {
        string relationStatus;
        relationStatus = " in a relationship with " + relationship->getName();
        return relationStatus;
    }
}

void  person::printFriends() const {
    if( friends.size() == 0 ) {
        cout << name << " has no friends." <<  endl;
    }
    else
    {
        cout << "Friends of " << name <<  endl;
        for (int i=0; i<friends.size();i++){
            cout << friends[i]->name <<  endl;
        }
    }
    
};


void  person::printStatus() const {
    if( status.size() == 0 ) {
        cout << name << " has no status dpdates." <<  endl;
    }
    else
    {
        cout << "Status updates of " << name <<  endl << "----------------------------------------------" << endl;
        for (int i=0; i<status.size();i++){
            cout << status[i] <<  endl;
        }
    }
    
};

void person:: printMessages() const {
    if( text.size() == 0 ) {
        cout << name << " no messages so far." <<  endl;
    }
    else
    {
        cout << "Private Messages of " << name  <<  endl << "----------------------------------------------" << endl;
        typedef map<string, vector<string>>::const_iterator MapIterator;
        for (MapIterator iter = text.begin(); iter != text.end(); iter++)
        {
            cout << iter->first << endl << endl;
            typedef vector<string>::const_iterator ListIterator;
            for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
                cout << " " << *list_iter << endl;
        }
    }
}


string person::getDate() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    
    int day = aTime->tm_mday;
    int month = aTime->tm_mon ; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900
    string months[] = {"January", "February", "March", "April",
        "May", "June", "July", "August", "September", "October",
        "November", "December"};
    string DAY;
    {
        stringstream ss;
        ss << day;
        DAY = ss.str();
    }
    string YEAR;
    {
        stringstream ss;
        ss << year;
        YEAR = ss.str();
    }
    string fullDate = DAY+ " " + months[month] +" " + YEAR + "\n";
    return fullDate;
}
