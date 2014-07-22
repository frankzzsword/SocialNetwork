#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "person.h"

using namespace std;

class READ
{
	person personArray[100];
	int count;

public:
	void reRead(string textname)  //dynamically allocate memory and storing each product line into the dynamic memory array
	{
		count = 0;
		string  Name;
		string gender;
		string age;
		string address;
		string school;

		ifstream infile;
		infile.open(textname);
		while(!infile.eof())
		{
			getline(infile, Name);
			getline(infile, gender);
			getline(infile, age);
			getline(infile, address);
			getline(infile, school);
			int Age = stoi(age);


			person tempPerson(Name, "none", gender, Age, address, school);
			personArray[count] = tempPerson;
	
			cout<< personArray[count].getName()  << " " <<  personArray[count].getGender() << " " <<  personArray[count].getAge() << " " <<  personArray[count].getCity() << " " <<  personArray[count].getCollege() << endl ;

		}
		infile.close();
	}
};

int main()
{
	READ r;
	r.reRead("names.txt");
	return 0;
}
