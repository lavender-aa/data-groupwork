struct Node
{
    int data;
    Node* next;
    Node() { next = nullptr; }
    Node(int data) { this->data = data; next = nullptr; }
};

/*
    stack functions:
    ----------------

    Stack()
        description: constructor
        precondition: none
        postcondition: long

    void push(const int num)
        description: push onto stack
        precondition: none
        postcondition: adds a new node with data=num to the top of the stack

    int pop()
        description: pop off of stack
        precondition: none
        postcondition: returns the data from the topmost node, then removes the node.
                       if the stack is empty, prints a stack underflow error and exits with code 10

    int view_top()
        description: view top element
        precondition: none
        postcondition: returns the data from the topmost node without removing it.
                       if the stack is empty, prints a stack underflow error and exits with code 10
*/

class Stack
{
    private:
        Node* head;
        Node* top;

    public:
        Stack();
        void push(const int num);
        int pop();
        int view_top();
};
