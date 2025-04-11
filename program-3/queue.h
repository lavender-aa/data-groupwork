struct Node
{
    int data;
    Node* next;
    Node() { next = nullptr; }
    Node(int data) { this->data = data; next = nullptr; }
};

/*
    queue functions:
    ----------------

    Queue()
        description: constructor
        precondition: none
        postcondition: sets pointers to null

    ~Queue()
        description: destructor
        precondition: none
        postcondition: deletes the queue

    void enqueue(const int num)
        description: add a new node
        precondition: none
        postcondition: adds a new node with data = num to the back of the list

    int dequeue()
        description: delete a node and return its data
        precondition: >0 nodes exist
        postcondition: returns the data from the front node, then removes the node
                       throws an underflow error if the queue is empty

    int view_front()
        description: view front's data
        precondition: >0 nodes exist
        postcondition: returns the data from the front node
                       throws an underflow error if the queue is empty

    int view_back()
        description: view back's data
        precondition: >0 nodes exist
        postcondition: returns the data from the back node
                       throws an underflow error if the queue is empty
*/

class Queue
{
    private:
        Node* front;
        Node* back;

    public:
        Queue();
        ~Queue();
        void enqueue(const int num);
        int dequeue();
        int view_front();
        int view_back();
};