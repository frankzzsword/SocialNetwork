//
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


class person {
private:
    std::string name;
    char gender;
    int age;
    std::string city;
    std::string college;
    std::vector<person> status;
    std::vector<person> friends;
    std::vector<person> messages;


    
    //wall status
    //vector of person (for friends)
    //string Vector :  Message Array (just thought of this.. so a user can send a message    to another user, so when we add /// another person object.. it will add this object in their    friends array as  well.
    
public:
    person(std::string name, char gender, int age, std::string city, std::string college){
        this->name = name;
        this->age = age;
        this->city = city;
        this->college = college;
    }
    void setName(std::string item) {
        this->name = name;
    }
    void setGender(char gender) {
        this->gender = gender;
    }
    void setAge(int age) {
        this->age = age;
    }
    void addCity(int city) {
        this->city = city;
    }
    void addCollege(std::string college) {
        this->college = college;
    }
    void addFriend(person &friendName) {
        // NOTE : check if already exists
        friends.push_back(friendName);
        friendName.friends.push_back(*this);
    }
    std::string getName() const {
        return name;
    }
    char getGender() const {
        return gender;
    }
    int getAge() const {
        return age;
    }
    std::string getCity() const {
        return city;
    }
    std::string getCollege() const {
        return college;
    }

    void printFriends() const {
        std::cout << "Friends of " << name << std::endl;
        for (int i=0; i<friends.size();i++){
            std::cout << friends[i].name << std::endl;
        }

    };
};


