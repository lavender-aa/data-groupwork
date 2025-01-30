#include "set.h"
#include <iostream>

Set::Set()
{

}


Set::~Set()
{
    // loop through the list
    while(head != nullptr)
    {
        // set current to head
        current = head;

        // set head to next node
        head = head->next;

        // delete current node
        delete current;
    }
}


void Set::insert(int)
{

}


int Set::remove_current()
{
    // variables
    Node* temp = current->next;
    int val = current->data;

    // get data from next node
    current->data = current->next->data;
    
    // set pointer
    current->next = temp->next;

    // delete the node
    delete temp;

    // set current back to head
    current = head;

    // return value removed
    return val;
}


bool Set::search(int)
{

}


std::ostream& operator<< (std::ostream&, Set)
{
    
}

