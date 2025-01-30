/*

    Set()
        precondition: none
        postcondition: sets data pointers to null
        description: initializes pointers

    ~Set()
        precondition: >0 nodes exist
        postcondition: all nodes deleted, pointers set to null
        description: deletes set

    void insert(int)
        precondition: an integer value to add
        postcondition: adds node with specified value to list, points current to that node
        description: adds a number to the set

    int remove_current()
        precondition: >0 nodes exist
        postcondition: removes current node, points current to head node, returns value removed
        description: removes and prints value under current

    bool search(int)
        precondition: >0 nodes exist
        postcondition: if set contains input, point current to it's node, return true; otherwise return false
        description: locates a number in the list

    friend std::ostream& operator<< (std::ostream&, Set)
        precondition: >0 nodes exist
        postcondition: prints list
        description: prints list

*/

#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node() { data = 0; next = nullptr; };
};

class Set
{
    private:
        Node* head;
        Node* current;

    public:
        Set();
        ~Set();
        void insert(int);
        int remove_current();
        bool search(int);
        friend std::ostream& operator<< (std::ostream&, Set);
};