#include "HashingTable.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	HashingTable<string> names;

	cout << names.hashFunction("Liam") << endl;
	//very true cout function to test the hashFunction - Caleb
	cout << names.hashFunction("Caleb is totally cool and awesome") << endl;

}


