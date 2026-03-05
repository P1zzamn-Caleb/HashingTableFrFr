#ifndef _LL_H
#define _LL_H
#include <iostream>
using namespace std;

class LL
{
    Node* head;
public:
    LL();
    void InsertFront(int e);
    void InsertBack(int e);
    void Insert(int e);
    void RemoveFront();
    void RemoveItem(int e);
    void Print()const;
};

class Node
{
    int data;     //current data item
    Node* next;   //address of the next Node, holding the next item
    Node();
    Node(int e);
    Node(int e, Node* n);
    friend class LL;  //declares the LL class as a friend and the LL
    // class may access/modify without accessor/mutator methods
};
#endif
