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


void Set::insert(int num)
{
    // start at the beginning
    current = head;

    // loop through the list until the next node data is greater than num and the next node is not null
    while(current->data < num && current->next != nullptr)
    {
        current = current->next;
    }

    // create new node if num is not already in the list
    if(current->data != num)
    {
        // create a new node
        Node* temp = new Node;

        // set new node data
        temp->data = num;

        // set new node next pointer
        temp->next = current->next;

        // set current next pointer to new node
        current->next = temp;
    }
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

