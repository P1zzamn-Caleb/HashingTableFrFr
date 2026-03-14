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
//********************************************************************************
// Author: Chloe Byrd
// Purpose: Inserts an element into the hashing table
// Incoming: e (type T) - the element to be inserted
// Outgoing: element is placed into the linked list at the correct hash key
// Return: none
//********************************************************************************
	void Insert(T e); //insert

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Removes an element from the hashing table
// Incoming: e (type T) - the element to be removed
// Outgoing: the element is removed from the linked list if it exists
// Return: True if the element was removed, false if it was not found
//********************************************************************************
	bool Remove(T e); //remove

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Searches for an element in the hashing table
// Incoming: e (type T) - the element to search for 
// Outgoing: none
// Return: True if the element is found, false otherwise
//********************************************************************************
  bool Search(T e); //search/find

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Prints the hashing table showing each key and its linked list data
// Incoming: none
// Outgoing: This displays the hash table structure to the console
// Return: none
//********************************************************************************
	void Print() const; //print

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Generates a hash key using the modulo operation 
// Incoming: e (type T) - the element to generate a key for
// Outgoing: the key location within the hashing table
// Return: e % MAP_SIZE
//********************************************************************************
	int hashFunction(T e) const;
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
  data[key].Insert(e);
}

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Removes an element from the hashing table
// Incoming: e (type T)
// Outgoing: Element removed from linked list if found
// Return: true if removed, false if not found.
//********************************************************************************
template <class T>
bool HashingTable<T>::Remove(T e)
{
  int key = hashFunction(e);
  return data[key].Remove(e);
}

//********************************************************************************
// Author: Chloe Byrd
// Purpose: Searches for an element in the hashing table
// Incoming: e (type T)
// Outgoing: none
// Return: true if found, false otherwise
//********************************************************************************
template <class T>
bool HashingTable<T>::Search(T e)
{
  int key = hashFunction(e);
  return data[key].Search(e);
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

#endif
