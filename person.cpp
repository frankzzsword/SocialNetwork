//  person.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
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
     vector< string> messages;
public:
  
 person ( string name, string password, char gender, int age,  string city,  string college){
    this->name = name;
    this->password = password;
    this->age = age;
    this->city = city;
    this->college = college;
};

void setName( string item) {
    this->name = name;
}
void  setGender(char gender) {
    this->gender = gender;
}
void  setAge(int age) {
    this->age = age;
}
void  addCity(int city) {
    this->city = city;
}
void  addCollege( string college) {
    this->college = college;
}

void  addStatus( string newStatus) {
    string timeNow  = getDate()+newStatus;
    status.push_back(timeNow + "\n");
}


void  receiveMessage( string message) {
    messages.push_back(message);
}


void  sendMessage(person &friendName,  string message) {
      string messageName = this->name + "\n" + message;
      friendName.receiveMessage(getDate() +messageName+ " \n");
}
void  addFriend(person &friendName) {
    // NOTE : check if already exists or if it is the same person
    
    if (&friendName == this)
    {
         cout << "You cannot add yourself." <<  endl;
        return;
    }
    for (int i = 0; i < friends.size(); i++ ) {
        if (friends[i].name == friendName.name) {
             cout << "You cannot add the same friend twice." <<  endl;
            return  ;
        }
    }
    friends.push_back(friendName);
    friendName.friends.push_back(*this);
     cout << name << " and " << friendName.name << " are now friend " <<  endl;
}
 string getName() const {
    return name;
}
    string getPassword() const {
        return password;
    }

char  getGender() const {
    return gender;
}
int  getAge() const {
    return age;
    
}
 string  getCity() const {
    return city;
}
 string  getCollege() const {
    return college;
}

void  printFriends() const {
    if( friends.size() == 0 ) {
         cout << name << " has no friends." <<  endl;
    }
    else
    {
         cout << "Friends of " << name <<  endl;
        for (int i=0; i<friends.size();i++){
             cout << friends[i].name <<  endl;
        }
    }
    
};


void  printStatus() const {
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

void  printMessages() {
    if( messages.size() == 0 ) {
         cout << name << " no messages so far." <<  endl;
    }
    else
    {
        cout << "Private Messages of " << name  <<  endl << "----------------------------------------------" << endl;
        for (int i=0; i<messages.size();i++){
             cout << messages[i] <<  endl;
        }
    }
};
    
    string getDate() {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        
        int day = aTime->tm_mday;
        int month = aTime->tm_mon ; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
        int year = aTime->tm_year + 1900; // Year is # years since 1900
        string months[] = {"January", "February", "March", "April",
            "May", "June", "July", "August", "September", "October",
            "November", "December"};
        string fullDate = to_string(day)+ " " + months[month] +" " +to_string(year) + "\n";
        return fullDate;
    }

};
