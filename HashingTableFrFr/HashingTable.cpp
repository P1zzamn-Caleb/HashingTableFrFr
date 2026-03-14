//*********************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: March 5, 2026
// Name: CS 355 HashingTable Group Assignment
// Description: This file contains the implementation of
// the HashingTable class, including dynamic memory management
// and all table operations.
//*********************************************************************************
#include "HashingTable.h";

//*********************************************************************************
// Author: Caleb Ellis, Tori Dean (edited)
// HashingTable
// Purpose: Initializes the hash table, allocates memory for its arrays, and marks
// all slots as empty.
// Incoming: none (as of right now)
// Outgoing: Allocates memory for the Hashing table and a corresponding bool array
// for whether that location is empty of full.
// Return: none
//********************************************************************************
HashingTable::HashingTable():capacity(MAP_SIZE), count(0), table(nullptr), empty(nullptr)
{
	table = new int[capacity];
	empty = new bool[capacity];

	for (int i = 0; i < capacity; i++) {
		empty[i] = true;
	}
}
// we can rewrite this function to take an int parameter for the user's size of choice

//********************************************************************************
// Author: Tori Dean
// Name: Insert
// Purpose: Adds a key to the hash table. COmputes the hash index and uses linear
// probing to find an empty slot if a collision occurs.
// Incoming: key (int) - the value to insert
// Outgoing: Updates the hash table and the corresponding empty flags array
// Return: bool - true if it is inserted successfully, false if table is full
//********************************************************************************
bool HashingTable::Insert(int key) {
	int hVal = HashingTable::hashFunction(key);
	for (int i = 0; i < capacity; i++) {
		int nextVal = (hVal+i) % capacity;
		if (empty[nextVal]) {
			table[nextVal] = key;
			empty[nextVal] = false;
			count++;
			return true;
		}
		return false;
	}

}

//********************************************************************************
// Author: Caleb Ellis
// Name: hashFunction
// Purpose: Returns a hash value by modding an integer by the MAP_SIZE
// Incoming: key (int)
// Outgoing: key % MAP_SIZE (int - hash value)
// Return: key % MAP_SIZE (int - hash value)
//********************************************************************************
int HashingTable::hashFunction(int key)
{
	return (key % MAP_SIZE);
}
// should update for user's input size

//********************************************************************************
// Author: Caleb Ellis
// Name: Print
// Purpose: Print data with there keys
// Incoming: nothing
// Outgoing: the data along with their keys
// Return: none
//********************************************************************************
void HashingTable::Print()const
{
	for (int i = 0; i < capacity; i++)
	{
		cout << i << ": ";
		if (!empty[i]) {
			cout << table[i];
		}
		cout << endl;
	}
}

//********************************************************************************
// Author: Tori Dean
// Name: loadFactor
// Purpose: Prints the ratio of buckets with data to total buckets
// Incoming: None
// Outgoing: Ratio of filled buckets to total buckets
// Return: None
//********************************************************************************
void HashingTable::loadFactor(string& ratio) {
	ratio = count + ":" + capacity;
}

//********************************************************************************
// Author: Tori Dean
// Name: ~HashingTable (Destructor)
// Purpose: Deallocates all dynamically allocated memory for the table.
// Incoming: None
// Outgoing: Frees memory
// Return: None
//********************************************************************************
HashingTable::~HashingTable() {
	delete[] table;
	delete[] empty;
}