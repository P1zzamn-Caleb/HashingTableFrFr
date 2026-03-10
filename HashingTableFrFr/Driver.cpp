#include "HashingTable.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	HashingTable<string> names;

	cout << names.hashFunction(3) << endl;
	//very true cout function to test the hashFunction - Caleb
	cout << names.hashFunction(10) << endl;

}


