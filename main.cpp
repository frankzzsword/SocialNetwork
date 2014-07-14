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

    person Varun("Varun", 'M', 23, "Sunnyvale", "De Anza");
    person Ted("Ted", 'M', 20, "San Francisco", "Berkeley");
    person Matt("Matt", 'M', 22, "Armenia", "Berkeley");
    
    
    Varun.addFriend(Ted);
    Varun.addStatus("What the fuck");
    Varun.addStatus("This is bulshit");
    Matt.addFriend(Varun);
    Varun.printFriends();
    Matt.printFriends();
    
    return 0;
}
