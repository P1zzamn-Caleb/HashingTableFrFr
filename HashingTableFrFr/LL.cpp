/*#include "LL.h"

Node::Node() :next(nullptr) {}
Node::Node(int e) :data(e), next(nullptr) {}
Node::Node(int e, Node* n) :data(e), next(n) {}

LL::LL() :head(nullptr) {}

void LL::InsertFront(int e) {
    head = new Node(e, head); //what does the new operator return?    
}
void LL::InsertBack(int e) {
    if (head == nullptr) //if empty, head gets address of new node
        head = new Node(e);
    else {
        Node* temp = head;
        while (temp->next != nullptr) { //moves temp to the last node
            temp = temp->next;
        }
        temp->next = new Node(e); //last node's next field gets address of new node
    }
}

void LL::Insert(int e) {
    if (head == nullptr || e < head->data) //2 cases where head could change
        head = new Node(e, head);
    else {                                   //insert in the middle or at the end
        //loop to get to the insertion point
        Node* prev = head;
        Node* current = head;
        while (current != nullptr && e > current->data) { ///stopped when e (16) < current->data(20)
            prev = current;
            current = current->next;
        }
        //code to actually create a new Node and set pointers accurately
        if (current != nullptr && e == current->data)
            cout << "NO DUPES" << endl;
        else
            prev->next = new Node(e, current);
    }
}

void LL::RemoveFront()
{
    if (head == nullptr)
    {
        cout << "nu uh" << endl;

    }
    else
    {

        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}



void LL::RemoveItem(int e)
{
    // 4 cases:
    // 1. not in list
    // 2. In middle of list
    // 3. At the beginning of list
    // 4. At the end of list
    if (head == nullptr)
    {
        cout << "no list" << endl;

    }
    else if (head->data == e)
    {
        RemoveFront();
    }
    else
    {
        Node* curr = head;
        Node* prev = head;
        while (curr != nullptr && curr->data != e)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "not in list" << endl;
        }
        else {
            prev->next = curr->next;
            delete curr;
            curr = nullptr;
        }
    }




}

void LL::Print()const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
*/