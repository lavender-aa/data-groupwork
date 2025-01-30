#include "set.h"
#include <iostream>

Set::Set()
{

}


Set::~Set()
{

}


void Set::insert(int)
{

}


int Set::remove_current()
{

}


bool Set::search(int)
{

}


std::ostream& operator<< (std::ostream& stream, Set set)
{
    // for each node in the list, print out the number in its own line
    Node* temp = set.head;
    while(temp != nullptr) {
        stream << "data: " << temp->data << std::endl;
    }
    
    return stream;
}

