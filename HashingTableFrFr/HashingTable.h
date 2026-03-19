//*************************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: March 5. 2026
// Name: CS 355 Hashingtable Group Assignment HashingTable.h
// Purpose: 
// Description: This file implements a hash table using separate chaining. The table 
//				stores elements in an array of linked lists (LL<T>), where each index 
//				acts as a hash key. Collisions are handled by inserting elements into 
//				the corresponding linked list.
//*************************************************************************************
#ifndef _HASHING_TABLE_H
#define _HASHING_TABLE_H
#include "LL.h"

const int MAP_SIZE = 7;

template <class T>
class HashingTable
{
//**************************
//PRIVATE DATA MEMBERS
//**************************
	int count;
	LL<T> data[MAP_SIZE]; //7 (MAP_SIZE) LL pointers that we can update to point to the first item in the LL - Caleb
public:
//********************************
// CONSTRUCTOR
//********************************
	HashingTable();
  	// insert 
	void Insert(T e);
	// remove
	bool Remove(T e);
	// print
	void Print()const;
	// hash
	int hashFunction(T e)const;
	// find
	bool Search(T e, int &loc);
	// load factor
	void loadFactor()const;
};

//********************************
// CONSTRUCTOR
//********************************
//********************************************************************************
// Author: Caleb Ellis
// Purpose: Constructor
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************
template <class T>
HashingTable<T>::HashingTable() : count(0)
{
}
//********************************
//INSERT FUNCTION
//********************************
//********************************************************************************
// Author: Chloe Byrd
// Purpose: Inserts an element into the hashing table
// Incoming: e (type T)
// Outgoing: Element is placed into the Linked List at the correct hash key
// Return: none
//********************************************************************************
template <class T>
void HashingTable<T>::Insert(T e)
{
	int key = hashFunction(e);
	data[key].InsertAtFront(e);
	count++;
}
//********************************
// REMOVE FUNCTION
//********************************
//********************************************************************************
// Author: Chloe Byrd, Caleb (added if statement)
// Purpose: Removes an element from the hashing table
// Incoming: e (type T)
// Outgoing: Element removed from linked list if found
// Return: true if removed, false if not found.
//********************************************************************************
template <class T>
bool HashingTable<T>::Remove(T e)
{
	int key = hashFunction(e);
	if(count >0 && data[key].Search(e))
		count--;
	return data[key].Remove(e);
}
//********************************
// SEARCH FUNCTION
//********************************
//********************************************************************************
// Author: Chloe Byrd, Tori Dean (edited)
// Purpose: Searches for an element in the hashing table
// Incoming: e (type T)
// Outgoing: loc (int) - location of element
// Return: true if found, false otherwise
//********************************************************************************
template <class T>
bool HashingTable<T>::Search(T e, int &loc)
{
	int key = hashFunction(e);
	if (data[key].Search(e))
	{
		loc = key;
		return true;
	}
	return false;
}

//********************************
// PRINT FUNCTION
//********************************
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
//********************************
// HASH FUNCTION
//********************************
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

	return (e % MAP_SIZE);
}
//********************************
// LOAD FACTOR FUNCTION
//********************************
//********************************************************************************
// Author: Tori Dean, Caleb Ellis
// Name: loadFactor
// Purpose: Prints the ratio of buckets with data to total buckets
// Incoming: None
// Outgoing: Ratio of filled buckets to total buckets
// Return: None
//********************************************************************************
template<class T>
void HashingTable<T>::loadFactor()const {
	cout << count << " pieces of data in " << MAP_SIZE << " buckets.";
}

                                        

#endif
