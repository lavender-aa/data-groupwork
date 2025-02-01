#include "set.h"
#include <iostream>

Set::Set()
{
    // set pointers to null
    head = nullptr;
    current = nullptr;
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

    // set current to null
    current = nullptr;
}


void Set::insert(int num)
{
    // if head is null, create a new node
    if(head == nullptr)
    {
        head = new Node;
        head->data = num;
        head->next = nullptr;
        current = head;
    }
    else if(num < head->data)
    {
        // create a new node before head
        Node* temp = new Node(num);
        
        // set new node next pointer
        temp->next = head;

        // set head to new node
        head = temp;

        // set current to head
        current = head;

        // set temp to null so it is not a dangling pointer
        temp = nullptr;
    }
    else
    {
        // start at the beginning
        current = head;

        // loop through the list to find the correct position for the node
        // continue looping if current node data is less than num and we did not reach the end of the list
        while(current->data < num && current->next != nullptr)
        {
            current = current->next;
        }

        // create new node if num is not already in the list
        if(current->data != num)
        {
            // create a new node and set new node's data
            Node* temp = new Node(num);

            // set new node next pointer
            temp->next = current->next;

            // set current next pointer to new node
            current->next = temp;

            // set current to the new node
            current = temp;

            // set temp to null so it is not a dangling pointer
            temp = nullptr;
        }
    }
}


int Set::remove_current()
{
    // variables
    int val = -1;

    // check if head is not null
    if(head != nullptr)
    {
        // set val to keep current data to return
        val = current->data;

        // check if next node is not null
        if(current->next != nullptr)
        {
            // create a temp node pointed to the next node
            Node* temp = current->next;

            // set current data to temp data
            current->data = temp->data;

            // set current next to temp next
            current->next = temp->next;

            // we can now delete temp
            delete temp;

            // set temp to null so it is not a dangling pointer
            temp = nullptr;
        }
        else // next node is null
        {
            // check if current is head
            if(current == head)
            {
                // delete current and set pointers to null
                delete current;
                head = nullptr;
                current = nullptr;
            }
            else // current is tail node
            {
                // create a temp previous node and start at head
                Node* prev = head;

                // loop through list if previous node's next does not equal current
                while(prev->next != current)
                {
                    prev = prev->next;
                }

                // set previous node's next pointer to null
                prev->next = nullptr;

                // delete current
                delete current;

                // set current back to head
                current = head;
            }
        }
    }

    // return value removed
    return val;
}


bool Set::search(int num)
{
    // variables
    bool found = false;

    // check if head is not null
    if(head != nullptr)
    {
        // start at the beginning
        Node* temp = head;

        // loop through the list if we did not reach the end of the list and temp data is not equal to num
        while(temp->next != nullptr && temp->data != num)
        {
            temp = temp->next;
        }

        if(temp->data == num)
        {
            // set found to true if we found the number
            current = temp;
            found = true;
        }
    }

    return found;
}


std::ostream& operator<< (std::ostream& stream, Set& set)
{
    stream << "Set elements:\n";

    // for each node in the list, print out the number in its own line
    Node* temp = set.head;
    int i = 0;
    while(temp != nullptr) {
        stream << "Node " << i << " data: " << temp->data << "\n";
        temp = temp->next;
        i++;
    }

    // spacing
    stream << "\n";
    
    return stream;
}

