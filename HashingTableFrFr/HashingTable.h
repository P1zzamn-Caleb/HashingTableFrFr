#ifndef _HASHING_TABLE_H
#define _HASHING_TABLE_H

// constructor
#include "LL.h"

const MAP_SIZE = 7;

template <class T>
class HashingTable
{
	LL<T>* data[MAP_SIZE]; //7 (MAP_SIZE) LL pointers that we can update to point to the first item in the LL - Caleb
public:
	HashingTable();
  	// insert 
	void Insert();
	// remove
	bool Remove();
	// print
	void Print();
	// find
	bool Search();
};



                                        

#endif
