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
    BNode<T>* root;
    void InsertHelper(T e, BNode<T>*& subroot);
  /*  void PrintInHelper(BNode<T>* subroot)const;*/
public:
    BST();
    void Insert(T e);
   /* void PrintIn()const;
    void PrintPre()const;
    void PrintPost()const;
    void PrintPreHelper(BNode<T>* subroot)const;
    void PrintPostHelper(BNode<T>* subroot)const;*/
    BNode<T>* searchHelper(T e, BNode<T>* subroot)const;
    BNode<T>* search(T e, BNode<T>* subroot);
    T Count()const;
    T CountHelper(BNode* subroot)const;
    void CountHelper(BNode* subroot, T c)const;
    //void GetMin(T& min); // go straight left
    //void GetMax(T& max); // go straight right
};

//*********************************
// BNODE DEFINITION
//*********************************
template <class T>
BNode<T>::BNode(T d) :data(d), left(nullptr), right(nullptr) {}
template <class T>
BNode<T>::BNode(T d, BNode<T>* l, BNode<T>* r) :data(d), left(l), right(r) {}
//*********************************
// BST DEFINITION
//*********************************
template <class T>
BST<T>::BST() :root(nullptr) {}

template <class T>
void BST<T>::InsertHelper(T e, BNode<T>*& subroot) {
    if (subroot == nullptr)
        subroot = new BNode(e);
    else if (e == subroot->data)
        cout << "NO DUPES" << endl;
    else if (e < subroot->data)
        InsertHelper(e, subroot->left);
    else  // e > subroot->data
        InsertHelper(e, subroot->right);
}

template <class T>
void BST<T>::Insert(T e) {
    InsertHelper(e, root);
}

template <class T>
void BST<T>::PrintInHelper(BNode<T>* subroot)const {
    if (subroot != nullptr) {
        PrintInHelper(subroot->left);
        cout << subroot->data << endl;
        PrintInHelper(subroot->right);
    }
}

template <class T>
void BST<T>::PrintIn()const {
    PrintInHelper(root);
}

template <class T>
void BST<T>::PrintPreHelper(BNode<T>* subroot)const {
    if (subroot != nullptr) {
        cout << subroot->data << endl;
        PrintPreHelper(subroot->left);
        PrintPreHelper(subroot->right);
    }
}

template <class T>
void BST<T>::PrintPre()const {
    PrintPreHelper(root);
}

template <class T>
void BST<T>::PrintPostHelper(BNode<T>* subroot)const {
    if (subroot != nullptr) {
        PrintPostHelper(subroot->left);
        PrintPostHelper(subroot->right);
        cout << subroot->data << endl;
    }
}

template <class T>
void BST<T>::PrintPost()const {
    PrintPostHelper(root);
}

template <class T>
BNode<T>* BST<T>::searchHelper(T e, BNode<T>* subroot)const {
    // this way is better so you can only return one value
    BNode* retval = nullptr;
    if (subroot != nullptr) {
        if (subroot->data == e) {
            retval = subroot;
        }
        else if (e < subroot->data) {
            retval = searchHelper(e, subroot->left);
        }
        else { // e > subroot->data
            retval = searchHelper(e, subroot->right);
        }
    }
    return retval;
}

template <class T>
BNode<T>* BST<T>::search(T e, BNode<T>* subroot) {
    return searchHelper(e, subroot);
}

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

template <class T>
T BST<T>::Count()const {
    return CountHelper(root);
}

template <class T>
void BST<T>::CountHelper(BNode<T>* subroot, T c)const {
    if (subroot != nullptr) {
        c++;
        c += CountHelper(subroot->left);
        c += CountHelper(subroot->right);
    }
}

#endif