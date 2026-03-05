#ifndef _HASHING_TABLE_H
#define _HASHING_TABLE_H

// constructor
#include "LL.h"

const MAP_SIZE = 7;

class HashingTable
{
	Node* data[MAP_SIZE];
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
