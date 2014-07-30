#include <iostream>
#include <cstdlib>
#include <string>
#include "person.h"
using namespace std;


#ifndef HASHING_H
#define HASHING_H

class hashing
{
private:
    int tableSize;
    int numberofentries;
	int largestbucket;
	int numberofcollisions;

    struct item
    {
        person *hashedPerson ;
        item* next;
        item() { next = NULL; hashedPerson = NULL; };
    };
    
    item **HashTable;
    
    
public:
    hashing() { tableSize = 0; }
    hashing(int size);
    int Hash(string key);
    void addObject(person &personObj);
    int NumberOfItemsInIndex(int index); //Count the number of people in one bucket
    void PrintTable();//Print the information in each bucket, and tell us how many people in that bucket
    void removeObject(person &personObj); // remove the object from hash table
    void getPrime(int &num);
    
    void deleteentry(){numberofentries--;}//added
    double getLoadingfactor(){return (double)numberofentries/(double)tableSize;}
    int getNumberofentries(){return numberofentries;}
    int getTablesize(){ return tableSize;}
    void reHash();
    //person getHashtable(int i){return **HashTable;}
    
};

#endif
