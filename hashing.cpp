#include <iostream>
#include <cstdlib>
#include <string>
#include "hashing.h"
using namespace std;

//Default constructor
hashing::hashing(int size)
{
    size = size *2;
    getPrime(size);
    tableSize = size;
    HashTable = new item*[tableSize];
	for(int i=0; i<tableSize; i++){
		HashTable[i] = NULL;
	}
}

/**************************** Hash ***************************************/
int hashing::Hash(string key)
{
    int hash = 0;
    int index;
    
    index = (int)key.length();
    
    for(int i = 0; i < key.length(); i++ )
    {
        hash = hash + (int)key[i];
        
    }
    
    index = hash % tableSize;
	// DEBUG
	/*cout << endl;
	cout << "[tableSize] : " << tableSize << endl;
	cout << "[hash] : " << hash << endl;
	cout << "[NAME] : " << key << endl;
	cout << "[INDEX] : " << index << endl;*/

    return index;
    
}

/**************************** addObject **********************************/
void hashing::addObject(person &personObj)
{
    
    int index = Hash(personObj.getName());
    
	cout << personObj.getName() << ": [" << index << "]\n" ;

    if(HashTable[index] == NULL)
    {
        HashTable[index] = new item;
        HashTable[index]->hashedPerson = &personObj;
        HashTable[index]->next =0;
		cout << personObj.getName() << " is added!\n";
    }
    
    else
    {   
		item* Ptr = new item;
		Ptr->hashedPerson = HashTable[index]->hashedPerson;
		Ptr->next = HashTable[index]->next;
		HashTable[index]->hashedPerson = &personObj;
		HashTable[index]->next = Ptr;
		cout << personObj.getName() << " is added!" << endl;
		
	}

	//cout << "People in this index[" << Hash(personObj.getName()) << "] :" << hashing::NumberOfItemsInIndex(Hash(personObj.getName())) << endl;
	
    
}

/**************************** NumberOfItemsInIndex **********************************/
//get the number of people in a given bucket
int hashing::NumberOfItemsInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index] ==  NULL)
    {
        return count;
    }
    else
    {
        item* Ptr = HashTable[index];
        while(Ptr != 0)
        {
            count++;
            Ptr = Ptr->next; 
        }
    }
    return count;
}

/************************ PrintTable *****************************/
//Print information in hash table
void hashing::PrintTable()
{
    cout << "****** PRINTING HASH TABLE *******" << endl;
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        if(HashTable[i] != NULL)
        {
            number = NumberOfItemsInIndex(i);
            cout << "Index = " << i <<endl;
            cout << "There are " << number << " people in this bucket.\n";
            item* Ptr = HashTable[i];
            while( Ptr != NULL)
            {
                cout << Ptr->hashedPerson << endl;
                Ptr = Ptr->next;
            }
            
        }
        
    }
    
}

/************************** removeObject ****************************/
// remove the object from hash table
void hashing::removeObject(person &personObj) 
{
    int index = Hash(personObj.getName());
    
    item* delPtr;
    item* p1;
    item* p2;
    
    //case 0: bucket is empty
    if(HashTable[index] == NULL)
        cout << "Person not found in the hash table!\n";
    
    //case 1: only 1 item contained in bucket and that item has matching name
    else if( HashTable[index]->hashedPerson == &personObj && HashTable[index]->next == 0)
    {
        HashTable[index] = NULL;
        cout << personObj.getName() << " is removed from the hash table!\n";
    }
    
    
    //case 2: match is located in the first item in the bucket but there are more items in the bucket
    else if(HashTable[index]->hashedPerson == &personObj)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;
        delPtr = 0;
        cout << personObj.getName() << " is removed from the hash table!\n";
    }
    //case 3: bucket contains items but first item is not a match
    else
    {
        p1 = HashTable[index]->next;
        p2 = HashTable[index];
        
        while(p1 != 0 && p1->hashedPerson != &personObj)
        {
            p2 = p1;
            p1 = p1->next;
        }
        //case 3.1 - no match
        if(p1 == 0)
        {
            cout << "Person not found in the hash table!\n";
        }
        //case 3.2 - match is found
        else
        {
            delPtr = p1;
            p1 = p1->next;
            p2->next = p1;
            delete delPtr;
            delPtr = 0;
            cout << personObj.getName() << " is removed from the hash table!\n";
        }
    }
}

/**************************Get Prime**************************/
void hashing::getPrime(int &num) {
    int i, j;
    for ( i = num; i < num+40; ++i)
    {
        for ( j = 2; j <= i/2; j++ )
        {
            if ( ! ( i % j ) ) break;
        }
        
        if ( j > i / 2 )
        {
            num = i;
            break;
        }
    }
}
