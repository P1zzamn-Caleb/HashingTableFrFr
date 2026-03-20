//************************************************************************
//Authors: Caleb Ellis, Tori Dean, Chloe Byrd, Jay Goodloe
//Name: BST.h
//Purpose: CS 355 Group BST.h file
//Description: This file implements a Binary Search Tree (BST) using
//             nodes. Each node contains data and pointers to left and
//             right children. The BST maintains sorted order such that
//            left < root < right.
//************************************************************************

#ifndef _BST_H
#define _BST_H
#include <iostream>
using namespace std;

template <class T>
class BNode {
    T data;
    BNode<T>* left;
    BNode<T>* right;
    BNode(T d);
    BNode(T d, BNode<T>* l, BNode<T>* r);
    template<class> friend class BST;
};

template <class T>
class BST {
//************************************
//PRIVATE DATA MEMBERS
//************************************
    BNode<T>* root;
//************************************
//PRIVATE HELPER FUNCTIONS
//************************************
    void InsertHelper(T e, BNode<T>*& subroot);
    void PrintInHelper(BNode<T>* subroot)const;
    bool RemoveHelper(T e, BNode<T>*& subroot);
    void Remover(BNode<T>*& subroot);
public:
//************************************
// CONSTRUCTOR
//************************************
    BST();
//************************************
// PUBLIC FUNCTIONS
//************************************
    void Insert(T e);
    bool Remove(T e);
    void PrintIn()const;
    BNode<T>* SearchHelper(T e, BNode<T>* subroot)const;
    BNode<T>* Search(T e)const;
    T Count()const;
    T CountHelper(BNode<T>* subroot)const;
    void CountHelper(BNode<T>* subroot, T c)const;
};

//*********************************
// BNODE DEFINITION
//*********************************

//*******************************************************************
//Author: Jay Goodloe (EVERYONE Reviewed/Edited this file)
//Purpose: Intializes a node with given data and child pointers
//Incoming: d (type T), L (left), r (right)
//Outgoing: node initialized
//Return: node
//*******************************************************************
template <class T>
BNode<T>::BNode(T d) :data(d), left(nullptr), right(nullptr) {}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Intializes a node with given data and child pointers
//Incoming: d (type T), l (left), r (right)
//Outgoing: node initialized
//Return: node
//*******************************************************************
template <class T>
BNode<T>::BNode(T d, BNode<T>* l, BNode<T>* r) :data(d), left(l), right(r) {}
//*********************************
// BST DEFINITION
//*********************************
//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Intializes an empty Binary Search Tree
//Incoming: none
//Outgoing: empty tree (root = nullptr)
//Return: none
//*******************************************************************
template <class T>
BST<T>::BST() :root(nullptr) {}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Recursively inserts element into correct BST position
//Incoming: e (type T), subroot reference
//Outgoing: updated subtree
//Return: none
//*******************************************************************
template <class T>
void BST<T>::InsertHelper(T e, BNode<T>*& subroot) {
    if (subroot == nullptr)
        subroot = new BNode<T>(e);
    else if (e == subroot->data)
        cout << "NO DUPES" << endl;
    else if (e < subroot->data)
        InsertHelper(e, subroot->left);
    else  // e > subroot->data
        InsertHelper(e, subroot->right);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Inserts an element into the BST
//Incoming: e (type T)
//Outgoing: element added to tree
//Return: none
//*******************************************************************
template <class T>
void BST<T>::Insert(T e) {
    InsertHelper(e, root);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Performs inorder traversal of BST
//Incoming: subroot pointer
//Outgoing: displayed values
//Return: none
//*******************************************************************
template <class T>
void BST<T>::PrintInHelper(BNode<T>* subroot)const {
    if (subroot != nullptr) {
        PrintInHelper(subroot->left);
        cout << subroot->data << " ";
        PrintInHelper(subroot->right);
    }
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Prints BST in sorted (inorder) order
//Incoming: none
//Outgoing: displayed value
//Return: none
//*******************************************************************
template <class T>
void BST<T>::PrintIn()const {
    PrintInHelper(root);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Recursively searches for an element in the BST
//Incoming: e (type T), subroot pointer
//Outgoing: pointer if found
//Return: node pointer or nullptr
//*******************************************************************
template <class T>
BNode<T>* BST<T>::SearchHelper(T e, BNode<T>* subroot)const {
    // this way is better so you can only return one value
    BNode<T>* retval = nullptr;
    if (subroot != nullptr) {
        if (subroot->data == e) {
            retval = subroot;
        }
        else if (e < subroot->data) {
            retval = SearchHelper(e, subroot->left);
        }
        else { // e > subroot->data
            retval = SearchHelper(e, subroot->right);
        }
    }
    return retval;
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Searches for an element in the BST
//Incoming: e (type T)
//Outgoing: pointer if found
//Return: node pointer or nullptr
//*******************************************************************
template <class T>
BNode<T>* BST<T>::Search(T e)const {
    return SearchHelper(e, root);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: IRecursively counts the number of nodes in the BST
//Incoming: subroot pointer
//Outgoing: total count
//Return: number of nodes
//*******************************************************************
template <class T>
T BST<T>::CountHelper(BNode<T>* subroot)const {
    int count = 0;
    if (subroot != nullptr) {
        ++count;
        count += CountHelper(subroot->left);
        count += CountHelper(subroot->right);
    }
    return count;
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Returns total number of nodes in the BST
//Incoming: none
//Outgoing: total count
//Return: number of nodes
//*******************************************************************
template <class T>
T BST<T>::Count()const {
    return CountHelper(root);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Recursively updates count variable
//Incoming: subroot pointer, c (count)
//Outgoing: updated count (local only)
//Return: none
//*******************************************************************
template <class T>
void BST<T>::CountHelper(BNode<T>* subroot, T c)const {
    if (subroot != nullptr) {
        c++;
        c += CountHelper(subroot->left);
        c += CountHelper(subroot->right);
    }
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Removes an element from the BST
//Incoming: e (type T)
//Outgoing: updated tree
//Return: true if removed
//*******************************************************************
template <class T>
bool BST<T>::Remove(T e)
{
    return RemoveHelper(e, root);
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Recursively finds and removes node 
//Incoming: e (type T), subroot reference
//Outgoing: updated subtree
//Return: true if removed
//*******************************************************************
template <class T>
bool BST<T>::RemoveHelper(T e, BNode<T>*& subroot)
{
    bool retval = false;
    if (subroot != nullptr) {
        if (subroot->data == e) {
            Remover(subroot);
            retval = true;
        }
        else if (e < subroot->data) {
            retval = RemoveHelper(e, subroot->left);
        }
        else { // e > subroot->data
            retval = RemoveHelper(e, subroot->right);
        }
    }
    return retval;
}

//*******************************************************************
//Author: Jay Goodloe (Reviewed by Group)
//Purpose: Deletes node and restructures BST
//Incoming: subroot reference
//Outgoing: updated subtree
//Return: none
//*******************************************************************
template <class T>
void BST<T>::Remover(BNode<T>*& subroot)
{
    if (subroot->left != nullptr)
    {
        subroot->data = subroot->left->data;
        Remover(subroot->left);
    }
    else if (subroot->right != nullptr)
    {
        subroot->data = subroot->right->data;
        Remover(subroot->right);
    }
    else
    {
        delete subroot;
        subroot = nullptr;
    }
}

#endif
