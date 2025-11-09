#include <iostream>
#include <string>
using namespace std;

char stackArr[50];
int top = -1;

void push(char c) {
    stackArr[++top] = c;
}

char pop() {
    return stackArr[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;  // Operand goes directly
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (top != -1 && stackArr[top] != '(') {
                postfix += pop();
            }
            pop(); // remove '('
        } 
        else { // Operator
            while (top != -1 && precedence(stackArr[top]) >= precedence(ch)) {
                postfix += pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix += pop();

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
