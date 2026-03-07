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
	//void Insert();
	// remove
	//bool Remove();
	// print
	void Print()const;
	// find
	//bool Search();
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



                                        

#endif
