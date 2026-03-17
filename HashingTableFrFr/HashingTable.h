//*********************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: March 5, 2026
// Name: CS 355 HashingTable Group Assignment
// Description: This header file defines the class the HashingTable class, its data
// members, and private and public member functions.
//********************************************************************************

#ifndef _HASHING_TABLE_H
#define _HASHING_TABLE_H
#include <iostream>
using namespace std;

const int MAP_SIZE = 7; // for tests only, we can remove this and let user decide - Tori


class HashingTable
{
	int capacity;
	int count;
	int* table;
	bool* empty; // this is to help us keep track of which buckets have data stored in them - Tori
	
	int hashFunction(int key)const;
public:
	// constructor
	HashingTable();
  	// insert 
	bool Insert(int key);
	// remove
	bool Remove(int key);
	// print
	void Print()const;
	// find
	bool Search(const int key, int& loc);
	// print load factor
	void loadFactor()const;

	// BIG 3
	// deconstructor
	~HashingTable();
};                                        

#endif
