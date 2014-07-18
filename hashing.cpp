#include <iostream>
#include <cstdlib>
#include <string>
#include "hashing.h"
using namespace std;

//Default constructor
hashing::hashing()
{
	for(int i=0; i< tableSize; i++)
	{
	    HashTable[i] = new item;
		HashTable[i]->hashedPerson.setName("empty");
		HashTable[i]->hashedPerson.setGender('N');
	    HashTable[i]->hashedPerson.setAge(0);
		HashTable[i]->hashedPerson.addCity("empty");
		HashTable[i]->hashedPerson.addCollege("empty");
		HashTable[i]->next = 0;
	}


}

/**************************** Hash ***************************************/
int hashing::Hash(string key)
{
	int hash = 0;
	int index;

	index = key.length();

	for(int i = 0; i < key.length(); i++ )
	{
		hash = hash + (int)key[i];
		 
	}

	index = hash % tableSize;
	cout << index;
	system("pause");
	return index;

}

/**************************** addObject **********************************/
void hashing::addObject(person &personObj)
{
	
	
	int index = Hash(personObj.getName());

	if(HashTable[index]->hashedPerson.getName() == "empty")
	{
		HashTable[index]->hashedPerson.setName(personObj.getName());
		HashTable[index]->hashedPerson.setGender(personObj.getGender());
		HashTable[index]->hashedPerson.setAge(personObj.getAge());
		HashTable[index]->hashedPerson.addCity(personObj.getCity());
		HashTable[index]->hashedPerson.addCollege(personObj.getCollege());
	}

	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->hashedPerson.setName(personObj.getName());
		n->hashedPerson.setGender(personObj.getGender());
		n->hashedPerson.setAge(personObj.getAge());
		n->hashedPerson.addCity(personObj.getCity());
		n->hashedPerson.addCollege(personObj.getCollege());
		n->next = 0;

		while(Ptr->next != 0)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

/**************************** NumberOfItemsInIndex **********************************/
//get the number of people in a given bucket
int hashing::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if(HashTable[index]->hashedPerson.getName() == "empty")
	{
		return count;
	}
	else
	{
		count++;
        item* Ptr = HashTable[index];
		while(Ptr->next != 0)
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
	int number;
	for(int i = 0; i < tableSize; i++)
	{
		 if(HashTable[i]->hashedPerson.getName() != "empty")
		 {
			number = NumberOfItemsInIndex(i);
			cout << "----------------------------------" << endl;
			cout << "Index = " << i <<endl;
			cout << "There are " << number << " people in this bucket.\n";
			item* Ptr = HashTable[i];
			//while( Ptr->next != 0)
			
				cout << Ptr->hashedPerson.getName() << endl;
				cout << Ptr->hashedPerson.getGender() << endl;
				cout << Ptr->hashedPerson.getAge() << endl;
				cout << Ptr->hashedPerson.getCity() << endl;
				cout << Ptr->hashedPerson.getCollege() << endl;
				cout << "--------------------------\n";
				Ptr = Ptr->next;
			
			
		 }

	}

}

/************************** removeObject *****************************/
void hashing::removeObject(person &personObj) // remove the object from hash table
{
	int index = Hash(personObj.getName());

	item* delPtr;
	item* p1;
	item* p2;

	//case 0: bucket is empty
	if(HashTable[index]->hashedPerson.getName() == "empty")
		cout << "Person not found in the hash table!\n";

	//case 1: only 1 item contained in bucket and that item has matching name 
	else if( HashTable[index]->hashedPerson.getName() == personObj.getName() && HashTable[index]->next == 0)
	{
		HashTable[index]->hashedPerson.setName("empty");
		HashTable[index]->hashedPerson.setGender('N');
	    HashTable[index]->hashedPerson.setAge(0);
		HashTable[index]->hashedPerson.addCity("empty");
		HashTable[index]->hashedPerson.addCollege("empty");
		cout << personObj.getName() << " is removed from the hash table!\n";
	}
	

	//case 2: match is located in the first item in the bucket but there are more items in the bucket
	else if(HashTable[index]->hashedPerson.getName() == personObj.getName())
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

		while(p1 != 0 && p1->hashedPerson.getName() != personObj.getName())
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