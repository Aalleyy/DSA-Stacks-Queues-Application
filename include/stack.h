#ifndef STACK_H
#define STACK_H

class Stack {
public:
    // constructor
    Stack();
    // copy constructor
    Stack(const Stack& stack);
    // destructor
    ~Stack();
    // bool function
    bool empty() const;
    // push an element onto the stack
    void push(const double x);
    // remove and return the top element from the stack
    double pop();
    // get the top value of the stack
    double top() const;
    // check if stack is full (always false for linked list implementation)
    bool full();
    // display all elements
    void print() const;

private:
    struct Node {
        double data;
        Node* next;
        Node(double val) : data(val), next(nullptr) {}
    };

    Node* topNode;
};

#endif // STACK_H
