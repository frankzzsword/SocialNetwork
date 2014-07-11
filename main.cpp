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

int main(int argc, const char * argv[]) {
    person Varun("Varun", 'M', 23, "Sunnyvale", "De Anza College");
    person Danny("Danny", 'M', 21, "Cupertino", "De Anza College");
    person Martin("Martin", 'M', 19, "San Francisco", "San Francisco State");
    Varun.addFriend(Danny);
    Varun.addFriend(Martin);
    Varun.printFriends();
    std::cout << std::endl;
    Danny.printFriends();
    return 0;
}
