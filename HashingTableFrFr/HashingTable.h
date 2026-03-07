#ifndef _HASHING_TABLE_H
#define _HASHING_TABLE_H

// constructor
#include "LL.h"

const int MAP_SIZE = 7;

template <class T>
class HashingTable
{
	LL<T> data[MAP_SIZE]; //7 (MAP_SIZE) LL pointers that we can update to point to the first item in the LL - Caleb
public:
	HashingTable();
  	// insert 
	int hashFunction(T e)const;
	//hashing
	void Insert(T e);
	// remove
	bool Remove(T e);
	// print
	void Print()const;
	// find
	bool Search(T e);
};


//********************************************************************************
// Author: Caleb Ellis
// Purpose: Constructor
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************
template <class T>
HashingTable<T>::HashingTable()
{
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Print data with there keys
// Incoming: nothing
// Outgoing: the data along with their keys
// Return: none
//********************************************************************************
template <class T>
void HashingTable<T>::Print()const
{
	for (int i = 0;i < MAP_SIZE;i++)
	{
		cout << i << ": ";
		data[i].Print();
		cout << endl;
	}
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Removes something from the table
// Incoming: thing to remove
// Outgoing: 
// Return: true or false if it is removed
//********************************************************************************
template <class T>
bool HashingTable<T>::Remove(T e)
{
	int key = hashFunction(e);
	return data[key].Remove(e);
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Inset data at the hash key
// Incoming: key as an int and data (e) of type T
// Outgoing: updated data LL
// Return: none
//********************************************************************************
template <class T>
void HashingTable<T>::Insert(T e)
{
	int key = hashFunction(e);
	data[key].InsertAtFront(e);
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Search to see if an item exist
// Incoming: data (e) of type T
// Outgoing: updated data LL
// Return: true or false depending on if it is found or not
//********************************************************************************
template <class T>
bool HashingTable<T>::Search(T e)
{
	int key = hashFunction(e);

	return data[key].Search(e);
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Returns a key by modding an integer by the MAP_SIZE
// Incoming: e (type T)
// Outgoing: e % MAP_SIZE
// Return: e % MAP_SIZE
//********************************************************************************
template <class T>
int HashingTable<T>::hashFunction(T e)const
{
	// This should work for now, until we have an insert or a search 
	// I chose to just use the length of the string as our hash function
	// Please email me if y'all need any help, or if theres anything more 
	// I should do
	// - Caleb

	return ((e.length() % MAP_SIZE));
}

#endif
