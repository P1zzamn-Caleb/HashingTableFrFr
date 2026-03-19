//*************************************************************************************
// Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodroe
// Start Date: March 5. 2026
// Name: CS 355 Hashing Table Group Assignment LL
// Description: This file contains the LL that will implement chain linking into a
//				hashing table.
//*************************************************************************************
#ifndef _LL_H
#define _LL_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
	Node<T>* next;
	T data;
public:
	Node(T e, Node<T>* node) : data(e), next(node) {};
	template<class> friend class LL;
};

template <class T>
class LL
{
	Node<T>* head;
public:
	LL() : head(nullptr) {};

	bool Search(T e)const;
	void InsertAtFront(T e);
	bool Remove(T e);
	void Print()const;
};

//********************************************************************************
// Author: Caleb Ellis (Reviewed and Editted by Chloe Byrd)
// Name: Remove
// Purpose: Removes e
// Incoming: T e
// Outgoing: updated LL, true or false based on if it is successful or unsuccessful
// Return: true or false based on if it is successful or unsuccessful
//********************************************************************************
template <class T>
bool LL<T>::Remove(T e)
{
	bool removed = false;
	if (head == nullptr)
	{}
	else if (head->data == e)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		removed = true;
	}
	else
	{
		Node<T>* curr = head;
		Node<T>* prev = head;
		while (curr->next != nullptr && curr->data != e)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr->data == e)
		{
			prev->next = curr->next;
			delete curr;
			curr = nullptr;
			removed = true;
		}
	}
	return removed;
}
//********************************************************************************
// Author: Caleb Ellis
// Name: Search
// Purpose: Searches for e
// Incoming: T e
// Outgoing: true or false based on if it is found
// Return: true or false based on if it is found
//********************************************************************************
template <class T>
bool LL<T>::Search(T e)const
{
	bool found = false;
	if (head != nullptr)
	{
		Node<T>* curr = head;
		while (curr->data != e && curr->next != nullptr)
		{
			curr = curr->next;
		}
		if (curr->data == e)
			found = true;
	}
	return found;
}

//********************************************************************************
// Author: Caleb Ellis
// Name: InsertAtFront
// Purpose: Inserts at the front of the LL
// Incoming: T e
// Outgoing: updated LL
// Return: none
//********************************************************************************
template <class T>
void LL<T>::InsertAtFront(T e)
{
	head = new Node<T>(e, head);
}

//********************************************************************************
// Author: Caleb Ellis
// Purpose: Prints LL
// Incoming: none
// Outgoing: none
// Return: none
//********************************************************************************
template <class T>
void LL<T>::Print()const
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

#endif
