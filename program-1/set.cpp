#include "set.h"
#include <iostream>

Set::Set()
{

}


Set::~Set()
{
    while(head != nullptr)
    {
        current = head;
        head = head->next;
        delete current;
    }
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


std::ostream& operator<< (std::ostream&, Set)
{
    
}

