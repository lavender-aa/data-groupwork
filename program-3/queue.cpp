#include "queue.h"
#include <iostream>
#include <stdexcept>

Queue::Queue()
{
    front = nullptr;
    back = nullptr;
}

Queue::~Queue()
{
    // loop through the queue and delete each node
    while(front != nullptr)
    {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::enqueue(const int num)
{
    Node* newNode = new Node(num);

    // check if the queue is empty
    if(back == nullptr)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

int Queue::dequeue()
{
    // check if the queue is empty
    if(front == nullptr)
    {
        throw std::underflow_error("Queue is empty.");
    }

    // get the front node
    Node* temp = front;
    front = front->next;

    // get data from node
    int value = temp->data;

    // check if queue becomes empty
    if(front == nullptr)
    {
        back = nullptr;
    }

    // delete node
    delete temp;

    return value;
}

int Queue::view_front()
{
    // check if the queue is empty
    if(front == nullptr)
    {
        throw std::underflow_error("Queue is empty.");
    }

    return front->data;
}

int Queue::view_back()
{
    // check if the queue is empty
    if(back == nullptr)
    {
        throw std::underflow_error("Queue is empty.");
    }

    return back->data;
}

