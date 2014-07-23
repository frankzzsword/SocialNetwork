
#ifndef HASHING_H
#define HASHING_H


#include <iostream>
#include <cstdlib>
#include <string>
#include "person.h"
using namespace std;


class hashing
{
private:
    int tableSize;
    struct item
    {
        person hashedPerson ;
        item* next;
        item() {};
    };
    item **HashTable;
    
public:
    
    hashing() { tableSize = 0; };
    hashing(int size);
    int Hash(string key);
    void addObject(person &personObj);
    int NumberOfItemsInIndex(int index); //Count the number of people in one bucket
    void PrintTable();//Print the information in each bucket, and tell us how many people in that bucket
    void removeObject(person &personObj); // remove the object from hash table
    void getPrime(int &num);
};

#endif
