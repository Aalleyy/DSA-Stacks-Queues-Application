#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(string expression) {
    string postfix = "";
    Stack stack;
    for (char c : expression) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            postfix += c;
            postfix += ' ';
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.pop(); // Discard the '('
        } else {
            while (!stack.empty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        postfix += ' ';
        stack.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    Stack stack;
    for (char c : postfix) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            switch (c) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        cerr << "Error: Division by zero" << endl;
                        return 0;
                    }
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }
    return stack.pop();
}

int main() {
    string infixExpression = "((5 + 2) * (8 - 3))";
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;
    return 0;
}
