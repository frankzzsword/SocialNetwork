//  person.cpp
//  socialNetwork
//
//  Created by Varun Mishra on 7/10/14.
//  Copyright (c) 2014 Varun Mishra. All rights reserved.
//
#include "person.h"

using namespace std;
person::person ( )
   name = " ";
   password = " ";
   age = 0;
   city = " ";
   college = " ";
};



person::person ( string name, string password, char gender, int age,  string city,  string college){
    this->name = name;
    this->password = password;
    this->age = age;
    this->city = city;
    this->college = college;
};

void person::setName( string item) {
    this->name = name;
}
void  person::setGender(char gender) {
    this->gender = gender;
}
void  person::setAge(int age) {
    this->age = age;
}
void  person::setCity(int city) {
    this->city = city;
}
void  person::setCollege( string college) {
    this->college = college;
}

void  person::setStatus( string newStatus) {
    string timeNow  = getDate()+newStatus;
    status.push_back(timeNow + "\n");
}


//void  receiveMessage( string message) {
//    messages.push_back(message);
//}


//void  sendMessage(person &friendName,  string message) {
//      string messageName = this->name + "\n" + message;
//      friendName.receiveMessage(getDate() +messageName+ " \n");
//}

void  person::receiveMessage(person&friendName ,string message) {
    friendName.text[this->name].push_back(message);
};
    
    
void  person::sendMessage(person &friendName,  string message) {
    string messageName = this->name + "  " + getDate() + message + "\n";
    string firstName = friendName.getName();
    text[firstName].push_back(messageName);
    friendName.receiveMessage(friendName, messageName);
};
    
    
    
    
void  person::setFriend(person &friendName) {
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
 string person::getName() const {
    return name;
}
    string person::getPassword() const {
        return password;
    }

char  person::getGender() const {
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

void  person::printFriends() const {
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
//        for(auto mapIt = begin(text); mapIt != end(text); ++mapIt)
//        {
//            std::cout << mapIt->first << " : ";
//            
//            for(auto c : mapIt->second)
//            {
//                std::cout << c << " ";
//            }
//            
//            std::cout << std::endl;
//        }
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
        string fullDate = to_string(day)+ " " + months[month] +" " +to_string(year) + "\n";
        return fullDate;
    }
