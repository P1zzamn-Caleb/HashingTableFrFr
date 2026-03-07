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

template <class T>
bool LL<T>::Remove(T e)
{
	bool removed = false;
	if (head == nullptr)
		cout << "EMPTY" << endl;
	else if (head->data == e)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
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

template <class T>
bool LL<T>::Search(T e)const
{
	bool found = false;
	if (head == nullptr)
		cout << "EMPTY" << endl;
	else
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

template <class T>
void LL<T>::InsertAtFront(T e)
{
	head = new Node<T>(e, head);
}

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