#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int count();
void *reRead(int i);

int main()
{
	int i = count();
	reRead(i);
	return 0;
}

int count()  //count the lines and read in each line as a string
{
	string temp;
	ifstream infile;
	infile.open("names.txt");
	if (!infile)
	{
		cout << "Error opening file\n";
		return false;
	}
	int i = 0;
	while( !infile.eof() )
	{
		getline(infile, temp);
		i++;
	}
	infile.close();
	cout << "Numbers of line: " << i << endl;
	return i;
}

void *reRead(int i)  //dynamically allocate memory and storing each product line into the dynamic memory array
{
	string *ptr = new string [i];
	ifstream infile;
	infile.open("names.txt");
	for (int j=0; j < i; j++)
	{
		getline(infile, *(ptr+j) );
		//infile.ignore();
	}
	infile.close();
	for (int z = 0; z < i; z++)
	{
		cout << *(ptr+z) << endl;
	}
	cout << endl;
	return ptr;
}
