#include "HashingTable.h"
#include <iostream>
#include <string>
using namespace std;

int hashFunction(string key);

int main()
{

}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Returns a key by modding an integer by the MAP_SIZE
// Incoming: key (int)
// Outgoing: key % MAP_SIZE
// Return: key % MAP_SIZE
//********************************************************************************
int hashFunction(string key)
{
	// This should work for now, until we have an insert or a search 
	// I chose to just use the length of the string as our hash function
	// Please email me if y'all need any help, or if theres anything more 
	// I should do
	// - Caleb

	return ((strlen(key)) % MAP_SIZE);
}
