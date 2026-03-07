#include "HashingTable.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	HashingTable<string> names;
	string name1 = "Liam";
	string name2 = "Caleb is very cool and awesome";
	string name3 = "Caleb";
	string name4 = "Hello";
	string name5 = "Hi";

	names.Insert(name1);
	names.Insert(name2);
	names.Insert(name3);
	names.Insert(name4);
	names.Insert(name5);
	names.Print();

	cout << names.Search(name1) << " " << name1 << endl;
	cout << names.Search("hi") << " hi" <<  endl;

	cout << names.Remove(name1) << endl;
	cout << names.Remove("he") << endl;
	names.Print();


}
