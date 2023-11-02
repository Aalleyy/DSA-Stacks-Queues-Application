#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() : topNode(nullptr) {}

Stack::Stack(const Stack& stack) {
    if (stack.topNode == nullptr) {
        topNode = nullptr;
    } else {
        topNode = new Node(stack.topNode->data);
        Node* currNode = topNode;
        Node* currStackNode = stack.topNode->next;
        while (currStackNode != nullptr) {
            currNode->next = new Node(currStackNode->data);
            currNode = currNode->next;
            currStackNode = currStackNode->next;
        }
    }
}

Stack::~Stack() {
    while (!empty()) {
        pop();
    }
}

bool Stack::empty() const {
    return topNode == nullptr;
}

void Stack::push(const double x) {
    Node* newNode = new Node(x);
    if (topNode == nullptr) {
        topNode = newNode;
    } else {
        newNode->next = topNode;
        topNode = newNode;
    }
}

double Stack::pop() {
    if (empty()) {
        cerr << "Stack underflow error: Cannot pop from an empty stack." << endl;
        return 0;
    }
    double topData = topNode->data;
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    return topData;
}

double Stack::top() const {
    if (empty()) {
        cerr << "The stack is empty. There is no top element." << endl;
        return 0;
    }
    return topNode->data;
}

bool Stack::full() {
    // Always return false for linked list implementation
    return false;
}

void Stack::print() const {
    if (empty()) {
        cout << "The stack is empty. There is nothing to print." << endl;
    } else {
        cout << "Stack elements: ";
        Node* current = topNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
