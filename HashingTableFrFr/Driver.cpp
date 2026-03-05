#include "HashingTable.h"
#include <iostream>
using namespace std;

int hashFunction(int key);

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
int hashFunction(int key)
{
	// This should work for now, until we have an insert or a search 
	// although we may have to static_cast it if the user inputs a string
	// Also send me an email when we have an insert function or if yall need help 
	// or if yall have something yall would like me to do
	// - Caleb
	return key % MAP_SIZE;
}
