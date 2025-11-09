#include <iostream>
#include <string>
using namespace std;

char stackArr[50];
int top = -1;

void push(char c) { stackArr[++top] = c; }
char pop() { return stackArr[top--]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// reverse a string
string reverseStr(string s) {
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--)
        rev += s[i];
    return rev;
}

string infixToPostfix(string infix) {
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (top != -1 && stackArr[top] != '(')
                postfix += pop();
            pop();
        } else {
            while (top != -1 && precedence(stackArr[top]) >= precedence(ch))
                postfix += pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix += pop();

    return postfix;
}

string infixToPrefix(string infix) {
    infix = reverseStr(infix);
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    string prefix = reverseStr(postfix);
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
