#include "set.h"
#include <iostream>
#include <iomanip>

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
    else
    {
        // loop through the list and check if num already exists
        Node* search = head;
        bool exist = false;
        while(search != nullptr)
        {
            if(search->data == num)
            {
                // num does exist, exit loop
                exist = true;
                break;
            }
            search = search->next;
        }

        // only create a new node if num does not exist
        if(!exist)
        {
            // create a new node
            Node* temp = new Node(num);
            
            // set new node next pointer
            if(current->next == nullptr)
            {
                temp->next = nullptr;
            }
            else
            {
                temp->next = current->next;
            }

            // set current next to new node
            current->next = temp;

            // set current to head
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
    // don't do anything if there is no list
    if(set.head == nullptr) return stream;

    // print label, set width alignment
    stream << "Set elements:" << std::left;

    // get width of longest number (num digits of last number in list)
    Node* temp = set.head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    int width = 1;
    int num = temp->data;
    while(num >= 10) 
    {
        num /= 10;
        width++;
    }

    // for each node in the list, print out the number
    // (up to 4 in a line)
    temp = set.head;
    int i = 0;
    while(temp != nullptr)
    {
        if(i % 4 == 0) stream << "\n";
        stream << std::setw(width) << temp->data << " ";
        temp = temp->next;
        i++;
    }

    // spacing
    stream << "\n\n";
    
    return stream;
}

