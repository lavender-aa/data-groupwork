#include "stack.h"
#include <iostream>
#include <stdexcept>

Stack::Stack()
{
    head = nullptr;
    top = nullptr;
}

void Stack::push(const int num)
{
    // 0 nodes
    if(head == nullptr)
    {
        head = new Node(num);
        head->next = nullptr;
        top = head;
        return;
    }

    // 1+ nodes
    top->next = new Node(num);
    top = top->next;
    top->next = nullptr;
}

int Stack::pop()
{
    // 0 nodes
    if(head == nullptr)
    {
        throw std::underflow_error("Attempted to pop empty stack.");
    }

    // 1 node
    if(head == top)
    {
        int value = head->data;
        delete head;
        head = nullptr;
        top = nullptr;
        return value;
    }

    // 2+ nodes
    // get node before top, store value, delete and set top
    Node* temp = head;
    while(temp->next != top)
    {
        temp = temp->next;
    }
    int value = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    top = temp;
    temp = nullptr;

    return value;
}

int Stack::view_top()
{
    // 0 nodes
    if(head == nullptr)
    {
        throw std::underflow_error("Attempted to view top of empty stack.");
    }

    // 1+ nodes
    return top->data;
}